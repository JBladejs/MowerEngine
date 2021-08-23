//
// Created by JJBla on 1/9/2021.
//

#ifndef MOWERENGINE_MOWER_H
#define MOWERENGINE_MOWER_H

#include <SDL2/SDL_video.h>
#include "input/InputProcessor.h"
#include "objects/Camera.h"

//TODO: make it more static
class Mower {
private:
    SDL_Window *window;
    SDL_GLContext context;
    Camera *camera;
    float screenWidth;
    float screenHeight;
    bool running;
    int exitCode;
    void initGL() const;
    void initSDL();
    void update();
    void render();
    void quit();
public:
    static InputProcessor *input;
    //TODO: try to remove constructor
    Mower();
    ~Mower();
    void start();
    int getExitCode() const;
};


#endif //MOWERENGINE_MOWER_H
