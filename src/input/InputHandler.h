//
// Created by goon on 11.07.2021.
//

#ifndef MOWERENGINE_INPUTHANDLER_H
#define MOWERENGINE_INPUTHANDLER_H

#include <cstdint>

//interface
class InputHandler {
public:
    InputHandler();
    virtual ~InputHandler();
    virtual bool onKeyDown(char key) = 0;
    virtual bool onKeyUp(char key) = 0;
    virtual bool onKeyHold(char key) = 0;
    //TODO: add mouse functions
};


#endif //MOWERENGINE_INPUTHANDLER_H
