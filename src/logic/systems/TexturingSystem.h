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
        auto& textured = coordinator.getComponent<Textured>(entity);
        auto& position = coordinator.getComponent<Position>(entity);
        //TODO: find a way to remove that
//        glLoadIdentity();
        textured.texture->update();
        //TODO: move the correction to texture rendering method
        float corr_x;
        float corr_y;
        switch (textured.scalingType) {
            case NONE:
                corr_x = textured.texture->getTexture().getImageWidth() * .5f;
                corr_y = textured.texture->getTexture().getImageHeight() * .5f;
                textured.texture->render(position.x - corr_x, position.y - corr_y);
                break;
            case FRACTIONAL:
                corr_x = textured.texture->getTexture().getImageWidth() * .5f * textured.scalingA;
                corr_y = textured.texture->getTexture().getImageHeight() * .5f * textured.scalingA;
                textured.texture->render(position.x - corr_x, position.y - corr_y, textured.scalingA);
                break;
            case CONSTANT:
                corr_x = textured.scalingA * .5f;
                corr_y = textured.scalingB * .5f;
                textured.texture->render(position.x - corr_x, position.y - corr_y, textured.scalingA, textured.scalingB);
                break;
        }
        //TODO: make sprite methods const and change this
    }
}

void TexturingSystem::update() {}

#endif //MOWERENGINE_TEXTURINGSYSTEM_H
