#include "Core/Time.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"

#include <iostream>
#include <SDL3/SDL.h>


int main(int argc, char* argv[]) {

    Rex::Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow("Plz don't blow up", 1200, 1024);

    SDL_Event e;
    bool quit = false;

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }


        renderer.SetColor(0, 0, 0, 0);
        renderer.Clear(); // Clear the renderer
        
        for (int i = 0; i < 10; i++) {

            renderer.SetColor(Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256));
            renderer.DrawLine(Rex::Random::getRandomFloat() * 1200, Rex::Random::getRandomFloat() * 1024, Rex::Random::getRandomFloat() * 1200, Rex::Random::getRandomFloat() * 1024);
        }

        for (int i = 0; i < 20; i++) {

            renderer.SetColor(Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256));
            renderer.DrawPoint(Rex::Random::getRandomFloat() * 1200, Rex::Random::getRandomFloat() * 1024);
        }

        renderer.Present();
    }

    renderer.Shutdown();
    return 0;
}