//
// Created by goon on 12.07.2021.
//

#include "TestInputHandler.h"

//TODO: investigate sudden increase in speed

TestInputHandler::TestInputHandler(TestObject *object): InputHandler(), object(object) {}

bool TestInputHandler::onKeyDown(char key) {
    switch (key) {
        case 'w': object->setY(object->getY() - 20); break;
        case 's': object->setY(object->getY() + 20); break;
        case 'a': object->setX(object->getX() - 20); break;
        case 'd': object->setX(object->getX() + 20); break;
        default: return false;
    }
    return true;
}

bool TestInputHandler::onKeyHold(char key) {
    switch (key) {
        case 'w': object->setY(object->getY() - 5); break;
        case 's': object->setY(object->getY() + 5); break;
        case 'a': object->setX(object->getX() - 5); break;
        case 'd': object->setX(object->getX() + 5); break;
        default: return false;
    }
    return true;
}

bool TestInputHandler::onKeyUp(char key) {
    switch (key) {
        case 'w': object->setY(object->getY() - 100); break;
        case 's': object->setY(object->getY() + 100); break;
        case 'a': object->setX(object->getX() - 100); break;
        case 'd': object->setX(object->getX() + 100); break;
        default: return false;
    }
    return true;
}


