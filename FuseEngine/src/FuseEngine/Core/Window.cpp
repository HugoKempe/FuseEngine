#include "fepch.h"
#include "Window.h"

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "FuseEngine/Event/Event.h"
#include "FuseEngine/Event/ApplicationEvent.h"
#include "FuseEngine/Event/KeyEvent.h"
#include "FuseEngine/Event/MouseEvent.h"

namespace Fuse
{
	static uint32_t s_NumWindowsCreated = 0;

	static void GLFWErrorCallback(int code, const char* description)
	{
		FE_CORE_ERROR("GLFW Error! code={}, Description={}", code, description);
	}

	static void CenterGLFWwindow(GLFWwindow* window)
	{
		int windowWidth, windowHeight;
		glfwGetWindowSize(window, &windowWidth, &windowHeight);

		GLFWmonitor* primary = glfwGetPrimaryMonitor();
		int xpos, ypos, monitorWidth, monitorHeight;
		glfwGetMonitorWorkarea(primary, &xpos, &ypos, &monitorWidth, &monitorHeight);

		glfwSetWindowPos(window, (int)monitorWidth / 2 - windowWidth / 2, (int)monitorHeight / 2 - windowHeight / 2);
	}

	Window::Window(const WindowProperties& properties)
	{
		Init(properties);
	}

	Window::~Window()
	{
		Shutdown();
	}

	void Window::OnUpdate() const
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void Window::SetEventCallback(const EventCallbackFN& callback)
	{
		m_Data.EventCallback = callback;
	}

	void Window::SetVSync(const bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool Window::IsVSync() const
	{
		return m_Data.VSync;
	}

	void Window::SetPosition(uint32_t x, uint32_t y)
	{
		m_Data.PosX = x;
		m_Data.PosY = y;
		glfwSetWindowPos(m_Window, (int)x, (int)y);
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	Ref<Window> Window::Create(const WindowProperties& properties)
	{
		return CreateRef<Window>(properties);
	}

	void Window::Init(const WindowProperties& properties)
	{
		m_Data.Title = properties.Title;
		m_Data.Width = properties.Width;
		m_Data.Height = properties.Height;
		m_Data.Fullscreen = properties.Fullscreen;
		m_Data.VSync = properties.VSync;

		if (s_NumWindowsCreated == 0)
		{
			const int success = glfwInit();
			FE_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if defined(FUSE_ENGINE_DEBUG)
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		++s_NumWindowsCreated;

		m_Context = CreateScope<GraphicsContext>(m_Window);
		m_Context->Init();

		CenterGLFWwindow(m_Window);
		SetVSync(true);

		RegisterCallbacks();
	}

	void Window::Shutdown() const
	{
		glfwDestroyWindow(m_Window);
		--s_NumWindowsCreated;

		if (s_NumWindowsCreated <= 0)
		{
			glfwTerminate();
		}
	}

	void Window::RegisterCallbacks()
	{
		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int xpos, int ypos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.PosX = xpos;
				data.PosY = ypos;

				WindowMoveEvent event(xpos, ypos);
				data.EventCallback(event);
			});

		glfwSetWindowFocusCallback(m_Window, [](GLFWwindow* window, int focused)
			{
				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (focused)
				{
				case GLFW_TRUE:
				{
					WindowFocusEvent event(true);
					data.EventCallback(event);
					break;
				}
				case GLFW_FALSE:
				{
					WindowFocusEvent event(false);
					data.EventCallback(event);
					break;
				}
				default: break;
				}
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				const WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0, mods);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1, mods);
					data.EventCallback(event);
					break;
				}
				default: break;
				}
			});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, uint32_t keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				default: break;
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}
}
