//
// Created by JJBla on 1/16/2021.
//

#ifndef MOWERENGINE_TESTOBJECT_H
#define MOWERENGINE_TESTOBJECT_H

#include "texturing/memory/TextureManager.h"

namespace MowerEngine {
    class TestObject {
    private:
        float x, y;
        float width, height;
        Image *image;
    public:
        TestObject(float x, float y, float width, float height);

        ~TestObject();

        void render();

        float getX() const;

        float getY() const;

        void setX(float x);

        void setY(float y);
    };
}

#endif //MOWERENGINE_TESTOBJECT_H
