//
// Created by JJBla on 1/9/2021.
//

#ifndef MOWERENGINE_MOWER_H
#define MOWERENGINE_MOWER_H

#include <SDL2/SDL_video.h>
#include "input/InputProcessor.h"
#include "objects/Camera.h"
#include "logic/ecs/Coordinator.h"

class Mower {
private:
    SDL_Window *window;
    SDL_GLContext context;
    Camera *camera;
    float screenWidth;
    float screenHeight;
    bool running;
    int exitCode;
    Coordinator& ecs_coordinator;

    void initGL() const;
    void initSDL();
    void update();
    void render();
    void quit();
public:
    static InputProcessor *input;
    ~Mower();
    void start();
    int getExitCode() const;

    //Singleton:
private:
    Mower();
public:
    static Mower& getInstance() {
        static Mower instance;
        return instance;
    }
    Mower(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
};


#endif //MOWERENGINE_MOWER_H
