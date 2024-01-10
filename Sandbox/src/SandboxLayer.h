#pragma once

#include <FuseEngine.h>

class SandboxLayer : public Fuse::Layer
{
public:
	SandboxLayer();
	~SandboxLayer() override = default;
	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(float delta) override;
	void OnTick() override;
	void OnImGuiRender() override;
	void OnEvent(Fuse::Event& event) override;
private:
	Fuse::Color m_Color;
};
