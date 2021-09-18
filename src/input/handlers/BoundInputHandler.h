//
// Created by Alan Ćwiek on 12.07.2021.
//

#ifndef MOWERENGINE_BOUNDINPUTHANDLER_H
#define MOWERENGINE_BOUNDINPUTHANDLER_H


#include "InputHandler.h"

class BoundInputHandler: public InputHandler {
private:
    bool disableUnbound;
public:
    //TODO: change those three to SDL_Keycode
    explicit BoundInputHandler(bool disableUnbound = false);
    bool onKeyDown(uint8_t key) override;
    bool onKeyUp(uint8_t key) override;
    bool onKeyHold(uint8_t key) override;
    virtual bool onKeyDown(uint16_t key) = 0;
    virtual bool onKeyUp(uint16_t key) = 0;
    virtual bool onKeyHold(uint16_t key) = 0;
};


#endif //MOWERENGINE_BOUNDINPUTHANDLER_H
