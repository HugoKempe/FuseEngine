#include "SandboxLayer.h"

#include "imgui.h"
#include "imgui-addons/DearWidgets/demo/demo.h"

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
	m_Color.r = Fuse::Input::GetMouseX() / (float)Fuse::Application::Get().GetWindow().GetWidth();
	m_Color.b = Fuse::Input::GetMouseY() / (float)Fuse::Application::Get().GetWindow().GetHeight();

	Fuse::Renderer::SetClearColor(m_Color);
}

void SandboxLayer::OnTick()
{
}

void SandboxLayer::OnImGuiRender()
{
	static int pressCount = 0;
	ImGui::Begin("Properties");
	if (ImGui::Button(fmt::format("You Pressed me {} times!", pressCount).c_str()))
		pressCount++;
	ImGui::End();

	ImWidgets::ShowDemo();
}

void SandboxLayer::OnEvent(Fuse::Event& event)
{
	Fuse::EventDispatcher dispatcher(event);
	dispatcher.Dispatch<Fuse::MouseButtonPressedEvent>([this](Fuse::MouseButtonEvent& e) -> bool
		{
			if (e.GetMouseButton() == Fuse::Mouse::Button0)
			{
				static uint32_t index = 0;
				m_Color.g = index % 2 == 0 ? 1.0f : 0.0f;
				index++;
				
			}
			return false;
		});
}
