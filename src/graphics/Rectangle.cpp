//
// Created by JJBla on 1/16/2021.
//

#include <GL/gl.h>
#include "Rectangle.h"
#include "texturing/Sprite.h"

using namespace MowerEngine;

Rectangle::Rectangle(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {
    image = new Sprite("assets/crate.jpg");
}

void Rectangle::render() {
    image->update();
    image->render(x, y);
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
    delete image;
    image = nullptr;
//    delete texture;
//    texture = nullptr;
//    delete animation;
//    animation = nullptr;
}
