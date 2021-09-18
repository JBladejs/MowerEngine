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

bool InputMultiplexer::updateHandlers(InputType type, uint8_t input) {
    for (auto handler: handlers) {
        switch (type) {
            case DOWN:
                if(handler->onKeyDown(input)) return true;
                break;
            case HOLD:
                if(handler->onKeyHold(input)) return true;
                break;
            case UP:
                if(handler->onKeyUp(input)) return true;
                break;
        }
    }
    return false;
}

bool InputMultiplexer::onKeyDown(uint8_t key) {
    return updateHandlers(DOWN, key);
}

bool InputMultiplexer::onKeyUp(uint8_t key) {
    return updateHandlers(UP, key);
}

bool InputMultiplexer::onKeyHold(uint8_t key) {
    return updateHandlers(HOLD, key);
}
