//
// Created by goon on 12.07.2021.
//

#include <iostream>
#include "TestInputHandler.h"

//TODO: investigate sudden increase in speed

TestInputHandler::TestInputHandler(TestObject *object): BoundInputHandler(true), object(object) {}

bool TestInputHandler::onKeyDown(uint16_t key) {
    if (key == 2) {
        object->setY(object->getY() + 20);
        return true;
    } else return false;
}

bool TestInputHandler::onKeyHold(uint16_t key) {
    if (key == 2) {
        object->setY(object->getY() + 5);
        return true;
    } else return false;
}

bool TestInputHandler::onKeyUp(uint16_t key) {
    if (key == 2) {
        object->setY(object->getY() + 100);
        return true;
    } else return false;
}



