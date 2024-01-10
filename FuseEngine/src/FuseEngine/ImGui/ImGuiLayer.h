#pragma once

#include "FuseEngine/Layer/Layer.h"
#include "FuseEngine/Event/Event.h"

namespace Fuse
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();

		static uint32_t GetActiveWidgetID();
	private:
		bool m_BlockEvents = true;
	};
}
