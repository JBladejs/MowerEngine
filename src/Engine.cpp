//
// Created by JJBla on 1/9/2021.
//

#include "Engine.h"
#include "graphics/TestObject.h"

#include<SDL2/SDL.h>
#include<GL/gl.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <chrono>
#include <iostream>

using namespace MowerEngine;
using namespace std;

MowerEngine::TestObject *testRect = nullptr;
//auto last_time = std::chrono::high_resolution_clock::now();

//TODO: Add error checking
Engine::Engine() {
    camera = new Camera();
    window = nullptr;
    context = nullptr;
    inputProcessor = nullptr;
    //TODO: make it not hardcoded
    screenWidth = 500.f;
    screenHeight = 500.f;
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
    ilInit();
    ilClearColour(255, 255, 255, 000);
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

    testRect = new TestObject(250.f, 250.f, 64.f, 64.f);

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
    delete camera;
    camera = nullptr;
    delete inputProcessor;
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

    while (inputProcessor->hasProcessedKeyboardInput()) {
        switch (inputProcessor->getKeyboardInput()) {
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
            case SDLK_UP:
                camera->setY(camera->getY() - 2.5f);
                break;
            case SDLK_DOWN:
                camera->setY(camera->getY() + 2.5f);
                break;
            case SDLK_LEFT:
                camera->setX(camera->getX() - 2.5f);
                break;
            case SDLK_RIGHT:
                camera->setX(camera->getX() + 2.5f);
                break;
            default:
                break;
        }
    }

//    while (inputProcessor->hasProcessedMouseButtonInput()) {
//        std::cout << (int) inputProcessor->getMouseButtonInput() << std::endl;
//    }

//    std::cout << inputProcessor->getMouseCoordinates().x << " " << inputProcessor->getMouseCoordinates().y << std::endl;

    inputProcessor->endProcessing();
    SDL_GL_SwapWindow(window);
}

//TODO: add delta time as argument of render to make it framerate independent
void Engine::render() {
//    May be useful later
//    auto time = last_time;
//    last_time = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed = last_time - time;
//    std::cout << 1.0 / elapsed.count() << std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity(); //TODO: Check functionality of this
    glTranslatef(-camera->getX(), -camera->getY(), -camera->getZ());
    testRect->render();
    //TODO: find out about glFlush
    glFlush();
    glDisable(GL_TEXTURE_2D);
}
