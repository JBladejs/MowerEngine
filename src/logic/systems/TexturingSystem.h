//
// Created by JJBla on 9/4/2021.
//

#ifndef MOWERENGINE_TEXTURINGSYSTEM_H
#define MOWERENGINE_TEXTURINGSYSTEM_H

#include <iostream>
#include "../ecs/System.h"
#include "../ecs/Coordinator.h"
#include "../components/Textured.h"
#include "../components/Position.h"

class TexturingSystem: public System {
public:
    static void initialize();
    void update() override;
    void render() override;
};

void TexturingSystem::initialize() {
    auto& coordinator = Coordinator::getInstance();
    coordinator.registerSystem<TexturingSystem>();
    coordinator.registerComponent<Textured>();
    coordinator.observeComponentType<TexturingSystem>(coordinator.getComponentType<Textured>());
    coordinator.observeComponentType<TexturingSystem>(coordinator.getComponentType<Position>());
}

void TexturingSystem::render() {
    for (const auto& entity: entities) {
        auto& coordinator = Coordinator::getInstance();
        auto* texture = coordinator.getComponent<Textured>(entity).texture;
        auto& position = coordinator.getComponent<Position>(entity);
        std::cout << texture << std::endl;
        texture->update();
        //TODO: make sprite methods const and change this
    }
}

void TexturingSystem::update() {}

#endif //MOWERENGINE_TEXTURINGSYSTEM_H
