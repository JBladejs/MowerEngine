//
// Created by JJBla on 1/9/2021.
//

#include "Engine.h"
#include "graphics/Rectangle.h"

#include<SDL2/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <iostream>

using namespace MowerEngine;
using namespace std;

MowerEngine::Rectangle *testRect = nullptr;

Engine::Engine() {
    window = nullptr;
    context = nullptr;
    inputProcessor = nullptr;
    //TODO: make it not hardcoded
    screenWidth = 600.f;
    screenHeight = 600.f;
    exitCode = -1;
    running = false;
}

void Engine::initGL() const {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( 0.0, screenWidth, screenHeight, 0.0, 1.0, -1.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
//    TODO: Find out the difference between matrix modes
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
    inputProcessor = new InputProcessor();
    running = true;

    testRect = new Rectangle(500.0f, 500.0f, 64.0f, 64.0f);

    while (running) {
        render();
        update();
    }
    quit();
}

void Engine::quit() {
    SDL_DestroyWindow(window);
    window = nullptr;
    context = nullptr;
    inputProcessor = nullptr;
    SDL_Quit();
    exitCode = 0;
}

Engine::~Engine() {
    delete testRect;
    testRect = nullptr;
    quit();
}

int Engine::getExitCode() const {
    return exitCode;
}

void Engine::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) {
            running = false;
            break;
        } else inputProcessor->processInput(event);
    }

    while (inputProcessor->hasProcessedKeys()) {
        switch (inputProcessor->getProcessedKeys()) {
            case SDLK_w:
                testRect->setY(testRect->getY() - 5);
                break;
            case SDLK_s:
                testRect->setY(testRect->getY() + 5);
                break;
            case SDLK_a:
                testRect->setX(testRect->getX() - 5);
                break;
            case SDLK_d:
                testRect->setX(testRect->getX() + 5);
                break;
            default:
                break;
        }
    }

    inputProcessor->endProcessing();
    SDL_GL_SwapWindow(window);
}

void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity(); //TODO: Check functionality of this
    testRect->render();
    //TODO: find out about glFlush
    glFlush();
    glDisable(GL_TEXTURE_2D);
}
