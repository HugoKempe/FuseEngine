#pragma once

#include <glm/glm.hpp>

namespace Fuse
{
	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void Begin();
		static void End();

		static void SetClearColor(const glm::vec4& color);
	private:
		struct RenderData
		{
			glm::vec4 ClearColor{ 0.4f, 0.1f, 0.6f, 1.0f };
		};

		static RenderData s_RenderData;
	};
}
