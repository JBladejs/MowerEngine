//
// Created by goon on 12.07.2021.
//

#include "TestInputHandler2.h"

TestInputHandler2::TestInputHandler2(TestObject *object): BoundInputHandler(true), object(object) {}

bool TestInputHandler2::onKeyDown(uint16_t key) {
    if (key == 1 || key == 2) {
        object->setY(object->getY() - 20);
        return true;
    } else return false;
}

bool TestInputHandler2::onKeyHold(uint16_t key) {
    if (key == 1 || key == 2) {
        object->setY(object->getY() - 5);
        return true;
    } else return false;
}

bool TestInputHandler2::onKeyUp(uint16_t key) {
    if (key == 1 || key == 2) {
        object->setY(object->getY() - 100);
        return true;
    } else return false;
}