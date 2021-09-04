//
// Created by goon on 12.07.2021.
//

#include <iostream>
#include "TestInputHandler.h"

//TODO: investigate sudden increase in speed

TestInputHandler::TestInputHandler(TestObject *object): BoundInputHandler(true), object(object) {}

bool TestInputHandler::onKeyDown(uint16_t key) {
    return false;
}

bool TestInputHandler::onKeyHold(uint16_t key) {
    switch (key) {
        case 1: object->setY(object->getY() - 5.f); return true;
        case 2: object->setY(object->getY() + 5.f); return true;
        case 3: object->setX(object->getX() - 5.f); return true;
        case 4: object->setX(object->getX() + 5.f); return true;
        default: return false;
    }
}

bool TestInputHandler::onKeyUp(uint16_t key) {
    return false;
}



