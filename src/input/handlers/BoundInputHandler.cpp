//
// Created by goon on 12.07.2021.
//

#include "BoundInputHandler.h"
#include "../../Mower.h"

BoundInputHandler::BoundInputHandler(bool disableUnbound): InputHandler(), disableUnbound(disableUnbound) {}

bool BoundInputHandler::onKeyDown(uint8_t key) {
    if (Mower::input->isKeyMapped(key)) return onKeyDown(Mower::input->getBoundVerb(key));
    else return disableUnbound;
}

bool BoundInputHandler::onKeyUp(uint8_t key) {
    if (Mower::input->isKeyMapped(key)) return onKeyUp(Mower::input->getBoundVerb(key));
    else return disableUnbound;
}

bool BoundInputHandler::onKeyHold(uint8_t key) {
    if (Mower::input->isKeyMapped(key)) return onKeyHold(Mower::input->getBoundVerb(key));
    else return disableUnbound;
}
