#pragma once

namespace Fuse
{
	class RenderCommand
	{
	public:
		static void Init();

		static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
		static void SetClearColor(float r, float g,float b, float a);
		static void Clear();

		static void SetLineWidth(float width);
	};
}