//
// Created by Alan Ćwiek on 11.07.2021.
//

#ifndef MOWERENGINE_INPUTHANDLER_H
#define MOWERENGINE_INPUTHANDLER_H

#include <cstdint>

//interface
class InputHandler {
public:
    virtual bool onKeyDown(uint8_t key) = 0;
    virtual bool onKeyUp(uint8_t key) = 0;
    virtual bool onKeyHold(uint8_t key) = 0;
    //TODO: add mouse functions
};


#endif //MOWERENGINE_INPUTHANDLER_H
