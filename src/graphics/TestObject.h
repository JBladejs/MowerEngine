//
// Created by JJBla on 1/16/2021.
//

#ifndef MOWERENGINE_TESTOBJECT_H
#define MOWERENGINE_TESTOBJECT_H

#include "texturing/memory/TextureManager.h"
#include "../logic/ecs/Entity.h"

class TestObject {
private:
    Entity& entity;
    Image* image;
public:
    TestObject(float x, float y);
    ~TestObject();
    void render();
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
};

#endif //MOWERENGINE_TESTOBJECT_H
