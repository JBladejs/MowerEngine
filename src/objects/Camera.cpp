//
// Created by Alan Ćwiek on 24.05.2021.
//

#include "Camera.h"

Camera::Camera() {
    x = y = z = 0.f;
}

float Camera::getX() const {
    return x;
}

void Camera::setX(float value) {
    x = value;
}

float Camera::getY() const {
    return y;
}

void Camera::setY(float value) {
    y = value;
}

float Camera::getZ() const {
    return z;
}

void Camera::setZ(float value) {
    z = value;
}
