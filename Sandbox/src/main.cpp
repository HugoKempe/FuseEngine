#include "FuseEngine.h"
#include "FuseEngine/Core/EntryPoint.h"
#include "SandboxLayer.h"

class Sandbox : public Fuse::Application
{
public:
	Sandbox(const Fuse::ApplicationSpecification& specification)
		: Application(specification)
	{
		FE_DEBUG("SANDBOX Created!");
		SandboxLayer* layer = new SandboxLayer();
		PushLayer(layer);
	}

	~Sandbox()
	{
		FE_DEBUG("SANDBOX Destroyed!");
	}
};

Fuse::Application* Fuse::CreateApplication(ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
