#pragma once

#include <string>
#include "FuseEngine/Graphics/GraphicsContext.h"
#include "FuseEngine/Event/Event.h"

struct GLFWwindow;

namespace Fuse
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t Width, Height;
		bool Fullscreen;
		bool VSync;

		WindowProperties(
			std::string_view title = "FuseEngineApplication",
			uint32_t width = 800,
			uint32_t height = 600,
			bool fullscreen = false,
			bool vsync = false
		)
			: Title(title)
			, Width(width)
			, Height(height)
			, Fullscreen(fullscreen)
			, VSync(vsync)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFN = std::function<void(Event&)>;
		Window(const WindowProperties& properties);
		~Window();

		void OnUpdate() const;

		inline uint32_t GetWidth() const { return m_Data.Width; }
		inline uint32_t GetHeight() const { return m_Data.Height; }
		inline float GetAspectRatio() const { return static_cast<float>(m_Data.Width) / static_cast<float>(m_Data.Height); }

		// Window attributes
		void SetEventCallback(const EventCallbackFN& callback);

		void SetVSync(bool enabled);
		bool IsVSync() const;

		uint32_t GetPosX() const { return m_Data.PosX; }
		uint32_t GetPosY() const { return m_Data.PosY; }
		void SetPosition(uint32_t x, uint32_t y);

		bool ShouldClose() const;

		static Ref<Window> Create(const WindowProperties& properties = WindowProperties());
	private:
		void Init(const WindowProperties& properties);
		void Shutdown() const;

		void RegisterCallbacks();
	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;
		struct WindowData
		{
			std::string Title;
			uint32_t PosX, PosY;
			uint32_t Width, Height;
			bool Fullscreen;
			bool VSync;

			EventCallbackFN EventCallback;
		};

		WindowData m_Data;
	};
}
