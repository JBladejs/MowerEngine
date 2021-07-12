//
// Created by goon on 12.07.2021.
//

#ifndef MOWERENGINE_TESTINPUTHANDLER_H
#define MOWERENGINE_TESTINPUTHANDLER_H


#include "input/InputHandler.h"
#include "graphics/TestObject.h"
#include "input/BoundInputHandler.h"

class TestInputHandler: public BoundInputHandler {
private:
    TestObject *object;
public:
    explicit TestInputHandler(TestObject *object);
    bool onKeyDown(uint16_t key) override;
    bool onKeyHold(uint16_t key) override;
    bool onKeyUp(uint16_t key) override;
};


#endif //MOWERENGINE_TESTINPUTHANDLER_H
