//
// Created by goon on 12.07.2021.
//

#include <iostream>
#include "TestInputHandler.h"

//TODO: investigate sudden increase in speed

TestInputHandler::TestInputHandler(TestObject *object): BoundInputHandler(true), object(object) {}

bool TestInputHandler::onKeyDown(uint16_t key) {
    switch (key) {
        case 1: object->setY(object->getY() - 20); break;
        case 2: object->setY(object->getY() + 20); break;
//        case 'a': object->setX(object->getX() - 20); break;
//        case 'd': object->setX(object->getX() + 20); break;
        default: std::cout << "unrecognized key received!" << std::endl; break;
    }
    return true;
}

bool TestInputHandler::onKeyHold(uint16_t key) {
    switch (key) {
        case 1: object->setY(object->getY() - 5); break;
        case 2: object->setY(object->getY() + 5); break;
//        case 'a': object->setX(object->getX() - 5); break;
//        case 'd': object->setX(object->getX() + 5); break;
        default: std::cout << "unrecognized key received!" << std::endl; break;
    }
    return true;
}

bool TestInputHandler::onKeyUp(uint16_t key) {
    switch (key) {
        case 1: object->setY(object->getY() - 100); break;
        case 2: object->setY(object->getY() + 100); break;
//        case 'a': object->setX(object->getX() - 100); break;
//        case 'd': object->setX(object->getX() + 100); break;
        default: std::cout << "unrecognized key received!" << std::endl; break;
    }
    return true;
}


