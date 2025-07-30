#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Core/Time.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Model.h"

#include <iostream>
#include <SDL3/SDL.h>
#include <fmod.hpp>


int main(int argc, char* argv[]) {

    union data_t {

        bool b;
        int i;
        double d;
    };

    data_t data;
    data.b = true;

    std::cout << data.b << std::endl;

    //Initialize Systems
    Rex::AudioSystem audio;
        
    Rex::Time time;

    Rex::Renderer renderer;

    Rex::InputSystem input;

    std::vector<Rex::vec2> points{

        {5, 5},
        {15, 5},
        {15, 15},
        {5, 15}
    }; 

    Rex::Model model{ points, Rex::vec3{500,0,0} };

    audio.Initialize();

    renderer.Initialize();
    renderer.CreateWindow("Plz don't blow up", 1280, 1024);

    input.Initialize();


    SDL_Event e;
    bool quit = false;

    //Init Objects
    std::vector<Rex::vec2> stars;
    for (int i = 0; i < 100; i++) {

        stars.push_back(Rex::vec2(Rex::Random::getRandomFloat() * 1280, Rex::Random::getRandomFloat() * 1024));
    }
        
    audio.AddSound("clap.wav", "clap");    
    audio.AddSound("bass.wav", "bass");
    audio.AddSound("close-hat.wav", "close-hat");    
    audio.AddSound("snare.wav", "snare");    
    
    while (!quit) {

        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input.GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

        //Update Systems
        audio.Update();
        input.Update();       
        
        if (input.GetKeyDown(SDL_SCANCODE_W)) audio.PlaySound("clap");
        if (input.GetKeyDown(SDL_SCANCODE_A)) audio.PlaySound("bass");
        if (input.GetKeyDown(SDL_SCANCODE_S)) audio.PlaySound("close-hat");
        if (input.GetKeyDown(SDL_SCANCODE_D)) audio.PlaySound("snare");

        //draw
        Rex::vec3 color{0, 0, 0};       

        renderer.SetColor(color.r, color.g, color.b);
        renderer.Clear(); // Clear the renderer
       
        model.Draw(renderer, input.GetMousePos(), time.GetTime(), 10.0f);
                               
        Rex::vec2 speed{ -140.0f, 0.0f };
        float length = speed.Length();

        for (auto& star : stars) {

            star += speed * time.GetDeltaTime();

            if (star[0] > 1280) star[0] = 0;
            if (star[0] < 0) star[0] = 1280;

            renderer.SetColor((uint8_t)Rex::Random::getRandomInt(256), (uint8_t)Rex::Random::getRandomInt(256), (uint8_t)Rex::Random::getRandomInt(256));
            renderer.DrawPoint(star.x, star.y);
        }
        
        renderer.Present();
    }

    audio.Shutdown();
    renderer.Shutdown();
    input.Shutdown();

    return 0;
}