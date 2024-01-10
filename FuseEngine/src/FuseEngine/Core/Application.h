#pragma once
#include "FuseEngine/Core/Window.h"
#include "FuseEngine/Event/Event.h"
#include "FuseEngine/Layer/LayerStack.h"

int main(int argc, char** argv);

namespace Fuse
{
	class ImGuiLayer;

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			FE_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{
		std::string Name = "FuseBox Application";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void Start();
		void Suspend();
		void Resume();
		void Stop();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }

		const Window& GetWindow() const { return *m_Window; }

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

		static std::string GetBuildConfiguration();
	private:
		void Run();
		void OnTick();

		void OnEventInternal(Event& e);
	private:
		ApplicationSpecification m_Specification;
		Ref<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = false;
		bool m_Suspended = false;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		uint32_t m_TickRate = 60;
		float m_TicksPerSecond = 1.0f / static_cast<float>(m_TickRate);
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);
}