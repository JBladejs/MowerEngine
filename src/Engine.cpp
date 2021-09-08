//
// Created by JJBla on 1/9/2021.
//

#include "Engine.h"
#include "graphics/texturing/Sprite.h"
#include "TestInputHandler.h"
#include "input/handlers/InputMultiplexer.h"
#include "logic/components/Position.h"
#include "logic/systems/TexturingSystem.h"
#include "graphics/texturing/Animation.h"
#include "logic/systems/CollisionSystem.h"
#include<SDL2/SDL.h>
#include<GL/gl.h>
#include <IL/il.h>
#include <ilu.h>

using namespace std;
InputProcessor *Engine::input;
//auto last_time = std::chrono::high_resolution_clock::now();

//TODO: Add error checking
Engine::Engine(): ecs_coordinator(Coordinator::getInstance()) {
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

    window = SDL_CreateWindow("Engine Alpha", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (int) screenWidth,
                              (int) screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    context = SDL_GL_CreateContext(window);
    SDL_GL_SetSwapInterval(1);
}

void Engine::start() {
    initSDL();
    initGL();
    ecs_coordinator.registerComponent<Position>();
    TexturingSystem::initialize();
    CollisionSystem::initialize();
    input = new InputProcessor();
    running = true;

    //TODO: fix relative placement

    auto& background = ecs_coordinator.createEntity();
    background.addComponent<Position>({250.f, 250.f});
    background.addComponent<Textured>({new Sprite("assets/crate.jpg")});

    auto& player = ecs_coordinator.createEntity();
    player.addComponent<Position>({250.f, 250.f});
//    player.addComponent<Textured>({new Animation("assets/megaman.png", 5, 2, 15), CONSTANT, 100.f, 100.f});
    player.addComponent<Textured>({new Sprite("assets/circle.png"), CONSTANT, 100.f, 100.f});
    player.addComponent<CircleCollider>({0.f, 0.f, 50.f});

    auto& circle = ecs_coordinator.createEntity();
    circle.addComponent<Position>({250.f, 250.f});
    circle.addComponent<Textured>({new Sprite("assets/circle.png"), CONSTANT, 50.f, 50.f});
    circle.addComponent<CircleCollider>({0.f, 0.f, 25.f});

    auto& square = ecs_coordinator.createEntity();
    square.addComponent<Position>({400.f, 400.f});
    square.addComponent<Textured>({new Sprite("assets/square.jpg"), CONSTANT, 85.f, 85.f});
    square.addComponent<BoxCollider>({0.f, 0.f, 85.f, 85.f});

    input->map_key('w', 1);
    input->map_key('s', 2);
    input->map_key('a', 3);
    input->map_key('d', 4);

    auto handler = new TestInputHandler(player.getID());

    input->setHandler(handler);

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
    if (running) quit();
    delete input;
    input = nullptr;
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
    ecs_coordinator.update();
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
    ecs_coordinator.render();
    //TODO: find out about glFlush
    glFlush();
    glDisable(GL_TEXTURE_2D);
}
