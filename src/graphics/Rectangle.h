//
// Created by JJBla on 1/16/2021.
//

#ifndef MOWERENGINE_RECTANGLE_H
#define MOWERENGINE_RECTANGLE_H

namespace MowerEngine {
    class Rectangle {
    private:
        float x, y;
        float halfSizeX, halfSizeY;
    public:
        Rectangle(float x, float y, float sizeX, float sizeY);
        void render() const;
        float getX() const;
        float getY() const;
        void setX(float x);
        void setY(float y);
    };
}


#endif //MOWERENGINE_RECTANGLE_H
