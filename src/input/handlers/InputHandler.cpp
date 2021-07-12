//
// Created by goon on 11.07.2021.
//

#include "InputHandler.h"
#include "../../Engine.h"

InputHandler::InputHandler() {
    Engine::input->addHandler(this);
}

InputHandler::~InputHandler() {
    Engine::input->removeHandler(this);
}
