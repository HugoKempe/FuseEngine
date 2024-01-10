#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("Sandbox")
{
	
}

void SandboxLayer::OnAttach()
{
}

void SandboxLayer::OnDetach()
{
}

void SandboxLayer::OnUpdate(float delta)
{
}

void SandboxLayer::OnTick()
{
}

void SandboxLayer::OnImGuiRender()
{
}

void SandboxLayer::OnEvent(Fuse::Event& event)
{
	//Fuse::EventDispatcher dispatcher(event);
	//dispatcher.Dispatch<Fuse::MouseButtonPressedEvent>([this](Fuse::MouseButtonEvent& e) -> bool
	//	{
	//		if (e.GetMouseButton() == Fuse::Mouse::Button0)
	//		{
	//			static uint32_t index = 0;
	//			m_Color = index % 2 == 0 ? Fuse::Color::Red : Fuse::Color::Green;
	//			index++;
	//			//Fuse::Renderer::SetClearColor(m_Color);
	//		}
	//		return false;
	//	});
}
