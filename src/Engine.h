//
// Created by JJBla on 1/9/2021.
//

#ifndef MOWERENGINE_ENGINE_H
#define MOWERENGINE_ENGINE_H

#include <SDL2/SDL_video.h>

class Engine {
private:
    SDL_Window* window;
    SDL_GLContext context;

    int screenWidth;
    int screenHeight;
    bool running;
    int exitCode;

    void initGL() const;
    void initSDL();
    void gameLoop();
    void quit();
public:
    Engine();
    void start();
    int getExitCode() const;
};


#endif //MOWERENGINE_ENGINE_H
