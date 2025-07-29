#pragma once
#include "../Math/Vector2.h"
#include <SDL3/SDL.h>
#include <array>
#include <vector>

namespace Rex {
	class InputSystem {
	public:

		enum class MouseButton : uint8_t{

			Left,
			Middle,
			Right
		};
	public:

		InputSystem() = default;
		
		bool Initialize();
		void Shutdown();

		void Update();

		//Keyboard Input
		bool GetKeyDown(uint8_t key) { return s_keyboardState[key]; }
		bool GetPrevKeyDown(uint8_t key) { return s_prevKeyboardState[key]; }
		bool GetKeyPressed(uint8_t key) { return !s_prevKeyboardState[key] && s_keyboardState[key]; }
		bool GetKeyRelease(uint8_t key) { return s_prevKeyboardState[key] && !s_keyboardState[key]; }

		//Mouse Input
		bool GetMouseButtonDown(MouseButton button) { assert(button < 3); return s_mouseButtonState[(uint8_t)button]; }
		bool GetPrevMouseButtonDown(MouseButton button) { assert(button < 3); return s_prevMouseButtonState[(uint8_t)button];}
		bool GetMouseButtonPressed(MouseButton button) { assert(button < 3); return !s_prevMouseButtonState[(uint8_t)button] && s_mouseButtonState[(uint8_t)button]; }
		bool GetMouseButtonReleaased(MouseButton button) { assert(button < 3); return s_prevMouseButtonState[(uint8_t)button] && !s_mouseButtonState[(uint8_t)button]; }

		const vec2& GetMousePos() const { return s_mousePos; }
		const vec2& GetPrevMousePos() const { return s_prevMousePos; }
	private:

		std::vector<bool> s_keyboardState;
		std::vector<bool> s_prevKeyboardState;

		vec2 s_mousePos{0, 0};
		vec2 s_prevMousePos{0, 0};

		std::array<bool, 3> s_mouseButtonState {false, false, false};
		std::array<bool, 3> s_prevMouseButtonState{ false, false, false };
	};
}