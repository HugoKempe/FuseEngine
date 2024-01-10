#pragma once

#include "Event.h"
#include <sstream>

namespace Fuse
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height) {}

		inline uint32_t GetWidth() const { return m_Width; }
		inline uint32_t GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryWindow)
	private:
		uint32_t m_Width, m_Height;
	};

	class WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(uint32_t x, uint32_t y)
			: m_PosX(x), m_PosY(y) {}

		inline uint32_t GetX() const { return m_PosX; }
		inline uint32_t GetY() const { return m_PosY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowMoveEvent: " << m_PosX << ", " << m_PosY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowMove)
		EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryWindow)
	private:
		uint32_t m_PosX, m_PosY;
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent(bool focused)
			: m_Focused(focused) {}

		inline bool IsFocused() const { return m_Focused; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowFocusEvent: ";
			m_Focused ? ss << "true" : ss << "false";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryWindow)

	private:
		bool m_Focused;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication | EventCategoryWindow)
	};

	class AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppShutdownEvent : public Event
	{
	public:
		AppShutdownEvent() {}

		EVENT_CLASS_TYPE(AppShutdown)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
