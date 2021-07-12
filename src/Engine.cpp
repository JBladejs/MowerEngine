//
// Created by JJBla on 1/9/2021.
//

#include "Engine.h"
#include "graphics/TestObject.h"
#include "graphics/texturing/Sprite.h"
#include "TestInputHandler.h"
#include<SDL2/SDL.h>
#include<GL/gl.h>
#include <IL/il.h>
#include <ilu.h>

using namespace std;

TestInputHandler *handler = nullptr;
TestObject *testRect = nullptr;
Sprite *background = nullptr;
InputProcessor *Engine::input;
//auto last_time = std::chrono::high_resolution_clock::now();

//TODO: Add error checking
Engine::Engine() {
    camera = new Camera();
    window = nullptr;
    context = nullptr;
    input = nullptr;
    //TODO: make it not hardcoded
    screenWidth = 500.f;
    screenHeight = 500.f;
    exitCode = -1;
    running = false;
}

void Engine::initGL() const {
    //TODO: add viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, screenWidth, screenHeight, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.0, 0.0, 0.0, 1.0);

    glEnable(GL_TEXTURE_2D);

    //Enable blending
    glEnable(GL_BLEND);
    //TODO: research depth test
//    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //TODO: add error checking

//    TODO: Find out the difference between matrix modes
    ilInit();
    iluInit();
    ilClearColour(0, 0, 0, 0);
}

void Engine::initSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    window = SDL_CreateWindow("Mower Pre-Alpha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int) screenWidth,
                              (int) screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);
}

void Engine::start() {
    initSDL();
    initGL();
    input = new InputProcessor();
    running = true;

    testRect = new TestObject(250.f, 250.f, 64.f, 64.f);
    background = new Sprite("assets/crate.jpg");

//    input->map_key('s', 1);
//    input->map_key('d', 2);
    handler = new TestInputHandler(testRect);

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
    delete input;
    input = nullptr;
    SDL_Quit();
    exitCode = 0;
}

Engine::~Engine() {
    delete testRect;
    testRect = nullptr;
    delete input;
    input = nullptr;
    quit();
}

int Engine::getExitCode() const {
    return exitCode;
}

void Engine::update() {
    //TODO: move that to input processor
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
            break;
        } else input->processInput(event);
    }

//    if (input->isKeyPressed('w')) testRect->setY(testRect->getY() - 5);
//    if (input->isKeyPressed('a')) testRect->setX(testRect->getX() - 5);
//    if (input->isBoundKeyPressed(1)) testRect->setY(testRect->getY() + 5);
//    if (input->isBoundKeyPressed(2)) testRect->setX(testRect->getX() + 5);

    input->endProcessing();
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
    background->render(0.f, 0.f);
    testRect->render();
    //TODO: find out about glFlush
    glFlush();
    glDisable(GL_TEXTURE_2D);
}
