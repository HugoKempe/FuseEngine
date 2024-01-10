#include "fepch.h"
#include "Application.h"
#include "FuseEngine/Event/ApplicationEvent.h"
#include "FuseEngine/Graphics/Renderer.h"
#include "FuseEngine/ImGui/ImGuiLayer.h"

//TODO: put in separate timer class
#include "GLFW/glfw3.h"

namespace Fuse
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		FE_CORE_INFO("Args:");
		for (auto i = 0; i < specification.CommandLineArgs.Count; i++)
			FE_CORE_INFO("\t{0}: {1}", i, specification.CommandLineArgs[i]);

		FE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		// Set working directory here
		if (!m_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(m_Specification.WorkingDirectory);

		FE_CORE_INFO("Application Initialized");

		m_Window = Window::Create({ m_Specification.Name });
		m_Window->SetEventCallback([this](auto& e) { return this->OnEventInternal(e); });

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		Renderer::Shutdown();
		FE_CORE_INFO("Application Destroyed");
	}

	void Application::Start()
	{
		m_Running = true;
	}

	void Application::Suspend()
	{
		m_Suspended = true;
	}

	void Application::Resume()
	{
		m_Suspended = false;
	}

	void Application::Stop()
	{
		m_Running = false;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::Run()
	{
		m_Running = true;

		float lastTime = (float)glfwGetTime();
		float time = lastTime;
		float deltaTime = 0.0f;
		uint32_t frames = 0, ticks = 0;

		while (m_Running)
		{
			// Measure time
			const float nowTime = (float)glfwGetTime();
			deltaTime += (nowTime - lastTime) / m_TicksPerSecond;
			const float timestep = nowTime - lastTime;
			lastTime = nowTime;

			// Only tick at specified frames / s
			while (deltaTime >= 1.0)
			{
				OnTick();
				ticks++;
				deltaTime--;
			}

			// Update at maximum possible frames if visible
			
			if (!m_Minimized)
			{
				Renderer::Begin();
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
				Renderer::End();

				m_ImGuiLayer->Begin();
				for (Layer* layer : m_LayerStack)
					layer->OnImGuiRender();
				m_ImGuiLayer->End();

				frames++;
			}
			

			// Reset after one second
			if ((float)glfwGetTime() - time > 1.0)
			{
				time++;
				//FB_CORE_INFO("FPS: {0}, Ticks: {1}, Delta: {2}ms", frames, ticks, timestep.GetMilliseconds());
				ticks = 0;
				frames = 0;
			}

			

			
			m_Window->OnUpdate();
		}
	}

	void Application::OnTick()
	{
		for (Layer* layer : m_LayerStack)
			layer->OnTick();
	}

	void Application::OnEventInternal(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](auto&) -> bool { m_Running = false; return true; });
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& e) -> bool
			{
				if (e.GetWidth() == 0 || e.GetHeight() == 0)
				{
					m_Minimized = true;
					return false;
				}

				m_Minimized = false;
				Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
				return false;
			});

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}

		//FE_CORE_INFO("Application On Event => [{}]", e);
	}

	std::string Application::GetBuildConfiguration()
	{
#if defined(FUSEBOX_DEBUG)
		return "Debug";
#elif defined(FUSEBOX_RELEASE)
		return "Release";
#elif defined(FUSEBOX_DIST)
		return "Dist"
#else
		return "Unknown Build Configuration";
#endif
	}
}
