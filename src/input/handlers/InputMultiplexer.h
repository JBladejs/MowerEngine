//
// Created by goon on 12.07.2021.
//

#ifndef MOWERENGINE_INPUTMULTIPLEXER_H
#define MOWERENGINE_INPUTMULTIPLEXER_H


#include "InputHandler.h"
#include "../InputProcessor.h"

class InputMultiplexer: public InputHandler {
private:
    std::vector<InputHandler*> handlers;
    void addHandler(InputHandler *handler);
    void removeHandler(InputHandler *handler);
    void updateHandlers(InputType type, SDL_Keycode input);
    bool onKeyDown(uint8_t key) override;
    bool onKeyUp(uint8_t key) override;
    bool onKeyHold(uint8_t key) override;
};


#endif //MOWERENGINE_INPUTMULTIPLEXER_H
