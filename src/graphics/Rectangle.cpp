//
// Created by JJBla on 1/16/2021.
//

#include <GL/gl.h>
#include "Rectangle.h"

using namespace MowerEngine;

Rectangle::Rectangle(float x, float y, float sizeX, float sizeY) {
    this->x = x;
    this->y = y;
    halfSizeX = sizeX * 0.5f;
    halfSizeY = sizeY * 0.5f;
    texture = Texture();
}

void Rectangle::render() {
    texture.bind();
    glBegin(GL_QUADS);
//    glColor3ub(255, 51, 0);
    glTexCoord2f(0.f, 0.f); glVertex2f(x - halfSizeX, y - halfSizeY);
//    glColor3ub(255, 255, 102);
    glTexCoord2f(1.f, 0.f); glVertex2f(x + halfSizeX, y - halfSizeY);
//    glColor3ub(0, 153, 0);
    glTexCoord2f(1.f, 1.f); glVertex2f(x + halfSizeX, y + halfSizeY);
//    glColor3ub(0, 255, 204);
    glTexCoord2f(0.f, 1.f); glVertex2f(x - halfSizeX, y + halfSizeY);
    glEnd();
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
