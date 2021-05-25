//
// Created by JJBla on 1/16/2021.
//

#include <GL/gl.h>
#include "Rectangle.h"

using namespace MowerEngine;

Rectangle::Rectangle(float x, float y, float sizeX, float sizeY) : x(x), y(y), sizeX(sizeX), sizeY(sizeY) {
//    texture = TextureManager::makeCheckTexture(sizeX, sizeY);
//    texture = TextureManager::loadTextureFromFile("assets/crate.jpg");
    animation = TextureManager::loadSpriteSheetFromFile("assets/running.png", 8, 1, 12);
}

void Rectangle::render() {
//    texture->render(x, y, sizeX, sizeY);
    animation->render(x, y, sizeX, sizeY);
    animation->nextFrame();
}

float MowerEngine::Rectangle::getX() const {
    return x;
}

float MowerEngine::Rectangle::getY() const {
    return y;
}

void MowerEngine::Rectangle::setX(float x) {
    this->x = x;
}

void MowerEngine::Rectangle::setY(float y) {
    this->y = y;
}

Rectangle::~Rectangle() {
//    delete texture;
//    texture = nullptr;
    delete animation;
    animation = nullptr;
}
