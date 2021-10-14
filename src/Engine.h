//
// Created by JJBla on 1/9/2021.
//

#ifndef MOWERENGINE_ENGINE_H
#define MOWERENGINE_ENGINE_H

#include <SDL2/SDL_video.h>
#include "input/InputProcessor.h"
#include "objects/Camera.h"
#include "logic/ecs/Coordinator.h"

class Engine {
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

    Engine();
    virtual ~Engine();
    void start();
    int getExitCode() const;

    virtual void onInit() {};
    virtual void onUpdate() {};
    virtual void onRender() {};
};


#endif //MOWERENGINE_ENGINE_H
