#include "Renderer.h"

bool Rex::Renderer::Initialize() {

	if (!SDL_Init(SDL_INIT_VIDEO)) {

		std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Rex::Renderer::Shutdown() {

    SDL_DestroyRenderer(s_renderer);
    SDL_DestroyWindow(s_window);
    SDL_Quit();
}

bool Rex::Renderer::CreateWindow(const std::string& name, int width, int height) {

    s_window = SDL_CreateWindow(name.c_str(), width, height, 0);
    if (s_window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }

    s_renderer = SDL_CreateRenderer(s_window, NULL);
    if (s_renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(s_window);
        SDL_Quit();
        return false;
    }

	return true;
}

void Rex::Renderer::Clear() {

    SDL_RenderClear(s_renderer);
}

void Rex::Renderer::Present() {

    SDL_RenderPresent(s_renderer);
}

void Rex::Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {

    SDL_SetRenderDrawColor(s_renderer, r, g, b, a);
}

void Rex::Renderer::DrawLine(float x1, float y1, float x2, float y2) {

    SDL_RenderLine(s_renderer, x1, y1, x2, y2);
}

void Rex::Renderer::DrawPoint(float x, float y) {

    SDL_RenderPoint(s_renderer, x, y);
}
