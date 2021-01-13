//
// Created by JJBla on 1/9/2021.
//

#include "Engine.h"

#include<SDL2/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Engine::Engine() {
    window = nullptr;
    context = nullptr;
    screenWidth = 640.0;
    screenHeight = 480.0;
    exitCode = -1;
    running = false;
}

void Engine::initGL() const {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,screenWidth / screenHeight,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void Engine::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    window = SDL_CreateWindow("Mower Pre-Alpha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);
}

void Engine::start() {
    initSDL();
    initGL();
    running = true;

    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

        SDL_GL_SwapWindow(window);
    }
    quit();
}

void Engine::quit() {
    SDL_DestroyWindow(window);
    window = nullptr;
    context = nullptr;
    SDL_Quit();
    exitCode = 0;
}

int Engine::getExitCode() const {
    return exitCode;
}

void Engine::gameLoop() {

}
