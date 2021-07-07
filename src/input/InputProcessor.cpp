//
// Created by JJBla on 1/14/2021.
//

#include <iostream>
#include <algorithm>
#include "InputProcessor.h"
#include "../util/misc_functions.h"

using namespace MowerEngine;

InputProcessor::InputProcessor() {
    keyboard_i = 0;
    mouse_i = 0;
    mousePos.x = 0;
    mousePos.y = 0;
    mouseDrag.x = 0;
    mouseDrag.y = 0;
    //TODO: make this work for any button/key
    leftButtonPressed = false;
}

void InputProcessor::processInput(SDL_Event input) {
    switch (input.type) {
        case SDL_KEYDOWN: {
            if (!MowerEngine::vector_contains(pressed_keyboard_keys, input.key.keysym.sym))
                pressed_keyboard_keys.push_back(input.key.keysym.sym);
            break;
        }
        case SDL_KEYUP: {
            auto iter = std::find(pressed_keyboard_keys.begin(), pressed_keyboard_keys.end(), input.key.keysym.sym);
            if (iter != pressed_keyboard_keys.end()) pressed_keyboard_keys.erase(iter);
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            if (!MowerEngine::vector_contains(pressed_mouse_buttons, input.button.button))
                pressed_mouse_buttons.push_back(input.button.button);
            break;
        }
        case SDL_MOUSEBUTTONUP: {
            auto iter = std::find(pressed_mouse_buttons.begin(), pressed_mouse_buttons.end(), input.button.button);
            if (iter != pressed_mouse_buttons.end()) pressed_mouse_buttons.erase(iter);
            break;
        }
    }
}

SDL_Keycode InputProcessor::getKeyboardInput() {
    return pressed_keyboard_keys[keyboard_i++];
}

unsigned char InputProcessor::getMouseButtonInput() {
    return pressed_mouse_buttons[mouse_i++];
}

Position2Df InputProcessor::getMouseDrag() {
    Position2Df drag = Position2Df();
    drag.x = (float) (mouseDrag.x - mousePos.x) / 320.0f * 2.75f;
    drag.y = (float) (mouseDrag.y - mousePos.y) / 240.0f * 2.0625f;
    mousePos.x = mouseDrag.x;
    mousePos.y = mouseDrag.y;
    return drag;
}

bool InputProcessor::hasProcessedKeyboardInput() {
    return !pressed_keyboard_keys.empty() && keyboard_i != pressed_keyboard_keys.size();
}

bool InputProcessor::hasProcessedMouseButtonInput() {
    return !pressed_mouse_buttons.empty() && mouse_i != pressed_mouse_buttons.size();
}

bool InputProcessor::isMouseDragged() const {
    return leftButtonPressed;
}

void InputProcessor::endProcessing() {
    keyboard_i = 0;
    mouse_i = 0;
}

Position2D InputProcessor::getMouseCoordinates() {
    Position2D coordinates = Position2D();
    SDL_GetMouseState(&(coordinates.x), &(coordinates.y));
    return coordinates;
}
