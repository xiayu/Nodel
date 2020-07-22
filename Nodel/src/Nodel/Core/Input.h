#pragma once
#include "Nodel/Core/KeyCodes.h"
#include "Nodel/Core/MouseCodes.h"

namespace Nodel {
	class Input {
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
