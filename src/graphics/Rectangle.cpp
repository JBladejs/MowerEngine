//
// Created by JJBla on 1/16/2021.
//

#include <GL/gl.h>
#include "Rectangle.h"

using namespace MowerEngine;

Rectangle::Rectangle(float x, float y, float sizeX, float sizeY) {
    halfSizeX = sizeX * 0.5f;
    halfSizeY = sizeY * 0.5f;
}

void Rectangle::render() {
    glColor3ub(255, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(x - halfSizeX, y - halfSizeY);
    glVertex2f(x + halfSizeX, y - halfSizeY);
    glVertex2f(x + halfSizeX, y + halfSizeY);
    glVertex2f(x - halfSizeX, y + halfSizeY);
    glEnd();
}
