#include "InputSystem.h"

namespace Rex {

    bool InputSystem::Initialize() {

        int numkeys;
        const bool* keyboardState = SDL_GetKeyboardState(&numkeys);

        s_keyboardState.resize(numkeys);
      
        std::copy(keyboardState, keyboardState + numkeys, s_keyboardState.begin());

        s_prevKeyboardState = s_keyboardState;

        s_prevMousePos = s_mousePos;
        SDL_GetMouseState(&s_mousePos.x, &s_mousePos.y);

        return true;
    }

    void InputSystem::Shutdown() {

        
    }

    void InputSystem::Update() {

        s_prevKeyboardState = s_keyboardState;

        const bool* keyboardState = SDL_GetKeyboardState(nullptr);

        std::copy(keyboardState, keyboardState + s_keyboardState.size(), s_keyboardState.begin());

        //mouse input
        s_prevMousePos = s_mousePos;

        s_prevMouseButtonState = s_mouseButtonState;

        uint32_t mouseButtonState = SDL_GetMouseState(&s_mousePos.x, &s_mousePos.y);   

        s_mouseButtonState[(uint8_t)MouseButton::Left] = mouseButtonState & SDL_BUTTON_LMASK;
        s_mouseButtonState[(uint8_t)MouseButton::Middle] = mouseButtonState & SDL_BUTTON_MMASK;
        s_mouseButtonState[(uint8_t)MouseButton::Right] = mouseButtonState & SDL_BUTTON_RMASK;
    }
}