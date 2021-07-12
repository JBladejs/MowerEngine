//
// Created by goon on 12.07.2021.
//

#include "InputMultiplexer.h"
#include <algorithm>

void InputMultiplexer::addHandler(InputHandler *handler) {
    handlers.push_back(handler);
}

void InputMultiplexer::removeHandler(InputHandler *handler) {
    auto index = find(handlers.begin(), handlers.end(), handler);
    if (index != handlers.end()) handlers.erase(index);
}

void InputMultiplexer::updateHandlers(InputType type, SDL_Keycode input) {
    for (auto handler: handlers) {
        switch (type) {
            case DOWN:
                handler->onKeyDown((uint8_t) input);
                break;
            case HOLD:
                handler->onKeyHold((uint8_t) input);
                break;
            case UP:
                handler->onKeyUp((uint8_t) input);
                break;
        }
    }
}

bool InputMultiplexer::onKeyDown(uint8_t key) {
    return false;
}

bool InputMultiplexer::onKeyUp(uint8_t key) {
    return false;
}

bool InputMultiplexer::onKeyHold(uint8_t key) {
    return false;
}
