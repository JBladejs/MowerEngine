//
// Created by Alan Ćwiek on 12.07.2021.
//

#ifndef MOWERENGINE_TESTINPUTHANDLER_H
#define MOWERENGINE_TESTINPUTHANDLER_H


#include "input/handlers/InputHandler.h"
#include "input/handlers/BoundInputHandler.h"
#include "logic/ecs/Entity.h"

class TestInputHandler: public BoundInputHandler {
private:
    Entity& player;
public:
    explicit TestInputHandler(EntityID entityID);
    bool onKeyDown(uint16_t key) override;
    bool onKeyHold(uint16_t key) override;
    bool onKeyUp(uint16_t key) override;
};


#endif //MOWERENGINE_TESTINPUTHANDLER_H
