//
// Created by goon on 12.07.2021.
//

#ifndef MOWERENGINE_TESTINPUTHANDLER_H
#define MOWERENGINE_TESTINPUTHANDLER_H


#include "input/InputHandler.h"
#include "graphics/TestObject.h"

class TestInputHandler: public InputHandler {
private:
    TestObject *object;
public:
    explicit TestInputHandler(TestObject *object);
    bool onKeyDown(char key) override;
    bool onKeyHold(char key) override;
    bool onKeyUp(char key) override;
};


#endif //MOWERENGINE_TESTINPUTHANDLER_H
