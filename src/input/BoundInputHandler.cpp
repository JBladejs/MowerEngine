//
// Created by goon on 12.07.2021.
//

#include "BoundInputHandler.h"
#include "../Engine.h"

BoundInputHandler::BoundInputHandler(bool disableUnbound): InputHandler(), disableUnbound(disableUnbound) {}

bool BoundInputHandler::onKeyDown(uint8_t key) {
    if (Engine::input->isKeyMapped(key)) return onKeyDown(Engine::input->getBoundVerb(key));
    else return disableUnbound;
}

bool BoundInputHandler::onKeyUp(uint8_t key) {
    if (Engine::input->isKeyMapped(key)) return onKeyUp(Engine::input->getBoundVerb(key));
    else return disableUnbound;
}

bool BoundInputHandler::onKeyHold(uint8_t key) {
    if (Engine::input->isKeyMapped(key)) return onKeyHold(Engine::input->getBoundVerb(key));
    else return disableUnbound;
}
