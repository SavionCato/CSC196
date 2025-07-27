#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

#include <iostream>
#include <SDL3/SDL.h>


int main(int argc, char* argv[]) {
    Rex::Time time;

    Rex::Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow("Plz don't blow up", 1280, 1024);

    Rex::InputSystem input;
    input.Initialize();


    SDL_Event e;
    bool quit = false;

    std::vector<Rex::vec2> stars;
    for (int i = 0; i < 100; i++) {

        stars.push_back(Rex::vec2(Rex::Random::getRandomFloat() * 1280, Rex::Random::getRandomFloat() * 1024));
    }

    std::vector<Rex::vec2> points;

    while (!quit) {

        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        input.Update();
        
        if(input.GetKeyPressed(SDL_SCANCODE_A)) {
        
            std::cout << "pressed\n";
        }

        if (input.GetMouseButtonDown(0)) {

            Rex::vec2 position = input.GetMousePos();
            if (points.empty()) {
                
                points.push_back(position);
            } else if ((position - points.back()).Length() > 10) {
                
                points.push_back(position); 
            }
        }

        renderer.SetColor(0, 0, 0);
        renderer.Clear(); // Clear the renderer
       
        if (points.size() > 0) {

            for (int i = 0; i < points.size() - 1; i++) {

                // set color or random color
                renderer.SetColor(Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256));

                if (points.size() > 1) {

                    renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
                }
            }
        }

        /*Rex::vec2 mouse = input.GetMousePos();
        std::cout << mouse.x << " " << mouse.y << std::endl;*/

        
        Rex::vec2 speed{ -140.0f, 0.0f };
        float length = speed.Length();

        for (auto& star : stars) {

            star += speed * time.GetDeltaTime();

            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;

            renderer.SetColor(Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256), Rex::Random::getRandomInt(256));
            renderer.DrawPoint(star.x, star.y);
        }
        
        renderer.Present();
    }

    renderer.Shutdown();
    input.Shutdown();

    return 0;
}