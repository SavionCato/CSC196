#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Time.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <fmod.hpp>


int main(int argc, char* argv[]) {

    //Initialize Systems
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    Rex::Time time;

    Rex::Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow("Plz don't blow up", 1280, 1024);

    Rex::InputSystem input;
    input.Initialize();


    SDL_Event e;
    bool quit = false;

    //Init Objects
    std::vector<Rex::vec2> stars;
    for (int i = 0; i < 100; i++) {

        stars.push_back(Rex::vec2(Rex::Random::getRandomFloat() * 1280, Rex::Random::getRandomFloat() * 1024));
    }

    std::vector<Rex::vec2> points;

    FMOD::Sound* sound = nullptr;
    std::vector<FMOD::Sound*> sounds;

    audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);
    
    while (!quit) {

        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        //Update Systems
        audio->update();
        input.Update();
        
        if (input.GetMouseButtonDown(Rex::InputSystem::MouseButton::Left)) {

            Rex::vec2 position = input.GetMousePos();
            if (points.empty()) {
                
                points.push_back(position);
            } else if ((position - points.back()).Length() > 10) {
                
                points.push_back(position); 
            }
        }
        
        if (input.GetKeyDown(SDL_SCANCODE_W))audio->playSound(sounds[0], 0, false, nullptr);
        if (input.GetKeyDown(SDL_SCANCODE_A))audio->playSound(sounds[1], 0, false, nullptr);
        if (input.GetKeyDown(SDL_SCANCODE_S))audio->playSound(sounds[2], 0, false, nullptr);
        if (input.GetKeyDown(SDL_SCANCODE_D))audio->playSound(sounds[3], 0, false, nullptr);

        //draw
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