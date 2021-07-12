//
// Created by goon on 12.07.2021.
//

#ifndef MOWERENGINE_TESTINPUTHANDLER2_H
#define MOWERENGINE_TESTINPUTHANDLER2_H


#include "input/handlers/BoundInputHandler.h"
#include "graphics/TestObject.h"

class TestInputHandler2: public BoundInputHandler {
private:
    TestObject *object;
public:
    explicit TestInputHandler2(TestObject *object);
    bool onKeyDown(uint16_t key) override;
    bool onKeyHold(uint16_t key) override;
    bool onKeyUp(uint16_t key) override;
};


#endif //MOWERENGINE_TESTINPUTHANDLER2_H
