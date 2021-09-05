//
// Created by JJBla on 1/16/2021.
//

#include "TestObject.h"
#include "texturing/Sprite.h"
#include "../logic/components/Position.h"
#include "../logic/components/Textured.h"

TestObject::TestObject(float x, float y) : entity(Coordinator::getInstance().createEntity()) {
    image = new Animation("assets/megaman.png", 5, 2, 15);
    entity.addComponent<Position>({x, y});
    entity.addComponent<Textured>({image});
}

void TestObject::render() {
//    image->update();
//    auto& position = entity.getComponent<Position>();
//    image->render(position.x, position.y, 0.25f);
}

float TestObject::getX() const {
    return entity.getComponent<Position>().x;
}

float TestObject::getY() const {
    return entity.getComponent<Position>().y;
}

void TestObject::setX(float x) {
    auto& position = entity.getComponent<Position>();
    position.x = x;
}

void TestObject::setY(float y) {
    auto& position = entity.getComponent<Position>();
    position.y = y;
}

TestObject::~TestObject() {
    delete image;
    Coordinator::getInstance().removeEntity(entity);
}
