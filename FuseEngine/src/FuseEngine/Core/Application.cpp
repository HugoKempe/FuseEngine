#include "fepch.h"
#include "Application.h"

namespace Fuse
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		FE_CORE_INFO("Args:");
		for (auto i = 0; i < specification.CommandLineArgs.Count; i++)
			FE_CORE_INFO("\t{0}: {1}", i, specification.CommandLineArgs[i]);

		FE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		// Set working directory here
		if (!m_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(m_Specification.WorkingDirectory);

		FE_CORE_INFO("Application Initialized");
	}

	Application::~Application()
	{
		FE_CORE_INFO("Application Destroyed");
	}

	void Application::Run()
	{
		m_Running = true;
		FE_CORE_INFO("Application Running");
	}

	std::string Application::GetBuildConfiguration()
	{
#if defined(FUSEBOX_DEBUG)
		return "Debug";
#elif defined(FUSEBOX_RELEASE)
		return "Release";
#elif defined(FUSEBOX_DIST)
		return "Dist"
#else
		return "Unknown Build Configuration";
#endif
	}
}
