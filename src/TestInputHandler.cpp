//
// Created by Alan Ćwiek on 12.07.2021.
//

#include <iostream>
#include "TestInputHandler.h"
#include "logic/components/Position.h"

//TODO: investigate sudden increase in speed

TestInputHandler::TestInputHandler(EntityID entityID): BoundInputHandler(true), player(Coordinator::getInstance().getEntity(entityID)) {}

bool TestInputHandler::onKeyDown(uint16_t key) {
    return false;
}

bool TestInputHandler::onKeyHold(uint16_t key) {
    auto& position = player.getComponent<Position>();
    switch (key) {
        case 1: position.y -= 5.f; return true;
        case 2: position.y += 5.f; return true;
        case 3: position.x -= 5.f; return true;
        case 4: position.x += 5.f; return true;
        default: return false;
    }
}

bool TestInputHandler::onKeyUp(uint16_t key) {
    return false;
}



