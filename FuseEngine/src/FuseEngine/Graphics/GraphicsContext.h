#pragma once

struct GLFWwindow;

namespace Fuse
{
	class GraphicsContext
	{
	public:
		GraphicsContext(GLFWwindow* windowHandle);

		void Init();
		void SwapBuffers();
	private:
		GLFWwindow* m_WindowHandle;
	};
}
