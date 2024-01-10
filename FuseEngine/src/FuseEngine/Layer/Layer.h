#pragma once

#include "FuseEngine/Core/Core.h"
#include "FuseEngine/Event/Event.h"

namespace Fuse
{
	class Layer
	{
	public:
		Layer(std::string_view name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(float delta) {}
		virtual void OnTick() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
