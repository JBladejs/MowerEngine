//
// Created by JJBla on 1/9/2021.
//

#ifndef MOWERENGINE_ENGINE_H
#define MOWERENGINE_ENGINE_H

#include <SDL2/SDL_video.h>
#include "input/InputProcessor.h"

namespace MowerEngine {

    class Engine {
    private:
        SDL_Window *window;
        SDL_GLContext context;

        InputProcessor *inputProcessor;

        int screenWidth;
        int screenHeight;
        bool running;
        int exitCode;

        void initGL() const;

        void initSDL();

        void update();

        void render();

        void quit();

    public:
        Engine();
        ~Engine();

        void start();

        int getExitCode() const;
    };

}


#endif //MOWERENGINE_ENGINE_H
