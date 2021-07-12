//
// Created by JJBla on 1/16/2021.
//

#include "TestObject.h"
#include "texturing/Sprite.h"


TestObject::TestObject(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {
//    image = new Sprite("assets/crate.jpg");
    image = new Animation("assets/megaman.png", 5, 2, 15);
}

void TestObject::render() {
    image->update();
    image->render(x, y, 0.25f);
}

float TestObject::getX() const {
    return x;
}

float TestObject::getY() const {
    return y;
}

void TestObject::setX(float x) {
    this->x = x;
}

void TestObject::setY(float y) {
    this->y = y;
}

TestObject::~TestObject() {
    delete image;
    image = nullptr;
}
