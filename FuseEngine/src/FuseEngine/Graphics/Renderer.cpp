#include "fepch.h"
#include "Renderer.h"
#include "Renderer.h"

#include "RenderCommand.h"

namespace Fuse
{
	Renderer::RenderData Renderer::s_RenderData = RenderData();

	void Renderer::Init()
	{
		RenderCommand::Init();
		RenderCommand::SetClearColor(s_RenderData.ClearColor.r, s_RenderData.ClearColor.g, s_RenderData.ClearColor.b, s_RenderData.ClearColor.a);
	}

	void Renderer::Shutdown()
	{
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::Begin()
	{
		RenderCommand::Clear();
	}

	void Renderer::End()
	{
	}

	void Renderer::SetClearColor(const glm::vec4& color)
	{
		RenderCommand::SetClearColor(color.r, color.g, color.b, color.a);
		s_RenderData.ClearColor = color;
	}
}
