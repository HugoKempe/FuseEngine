#pragma once

#include "FuseEngine/Core/KeyCodes.h"
#include "FuseEngine/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Fuse
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
