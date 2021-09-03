//
// Created by JJBla on 1/16/2021.
//

#include "TestObject.h"
#include "texturing/Sprite.h"
#include "../logic/Components/Position.h"

TestObject::TestObject(float x, float y) : entity(EntityManager::getInstance().createEntity()) {
//    image = new Sprite("assets/crate.jpg");
    entity.addComponent<Position>({x, y});
    image = new Animation("assets/megaman.png", 5, 2, 15);
}

void TestObject::render() {
    image->update();
    auto position = entity.getComponent<Position>();
    image->render(position.x, position.y, 0.25f);
}

float TestObject::getX() const {
    return entity.getComponent<Position>().x;
}

float TestObject::getY() const {
    return entity.getComponent<Position>().y;
}

void TestObject::setX(float x) {
//    this->x = x;
}

void TestObject::setY(float y) {
//    this->y = y;
}

TestObject::~TestObject() {
    delete image;
    image = nullptr;
}
