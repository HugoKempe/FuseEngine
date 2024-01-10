#pragma once
#include "FuseEngine/Core/Core.h"
#include "FuseEngine/Core/Application.h"

#ifdef FE_PLATFORM_WINDOWS

extern Fuse::Application* Fuse::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Fuse::Log::Init();

	FE_CORE_INFO("---------- Startup ----------");
	auto app = Fuse::CreateApplication({ argc, argv });
	FE_CORE_INFO("----- Startup Finished. -----");

	FE_CORE_INFO("---------- Runtime ----------");
	app->Run();
	FE_CORE_INFO("----- Runtime Finished. -----");

	FE_CORE_INFO("---------- Shutdown ----------");
	delete app;
	FE_CORE_INFO("----- Shutdown Finished. -----");
}

#endif