//
// Created by JJBla on 1/16/2021.
//

#include "TestObject.h"
#include "texturing/Sprite.h"

using namespace MowerEngine;

TestObject::TestObject(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {
//    image = new Sprite("assets/crate.jpg");
    image = new Animation("assets/spaceship.png", 2, 2, 8);
}

void TestObject::render() {
    image->update();
    image->render(x, y);
}

float MowerEngine::TestObject::getX() const {
    return x;
}

float MowerEngine::TestObject::getY() const {
    return y;
}

void MowerEngine::TestObject::setX(float x) {
    this->x = x;
}

void MowerEngine::TestObject::setY(float y) {
    this->y = y;
}

TestObject::~TestObject() {
    delete image;
    image = nullptr;
}
