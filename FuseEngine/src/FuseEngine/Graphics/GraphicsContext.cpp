#include "fepch.h"
#include "GraphicsContext.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Fuse
{
	GraphicsContext::GraphicsContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		FE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void GraphicsContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		const int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FE_CORE_ASSERT(status, "Failed to initialize Glad!")

		FE_CORE_INFO("OpenGL Info:");
		FE_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		FE_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		FE_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));

		FE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 6), "FuseEngine requires at least OpenGL version 4.6!")
	}

	void GraphicsContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
