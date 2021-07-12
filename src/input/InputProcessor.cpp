//
// Created by JJBla on 1/14/2021.
//

//TODO: reformat
//TODO: add mouse and controller to key mapping
//TODO: add input multiplexer

#include <iostream>
#include <algorithm>
#include "InputProcessor.h"
#include "../util/misc_functions.h"

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
            if (!vector_contains(pressed_keyboard_keys, input.key.keysym.sym))
                pressed_keyboard_keys.push_back(input.key.keysym.sym);
            updateHandlers(DOWN, input.key.keysym.sym);
            break;
        }
        case SDL_KEYUP: {
            auto iter = std::find(pressed_keyboard_keys.begin(), pressed_keyboard_keys.end(), input.key.keysym.sym);
            if (iter != pressed_keyboard_keys.end()) pressed_keyboard_keys.erase(iter);
            updateHandlers(UP, input.key.keysym.sym);
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            if (vector_contains(pressed_mouse_buttons, input.button.button))
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

void InputProcessor::endProcessing() {
    //TODO: make sure that the first press dosen't count into that
    for (auto key: pressed_keyboard_keys) {
        updateHandlers(HOLD, key);
    }
    keyboard_i = 0;
    mouse_i = 0;
}

void InputProcessor::addVerb(uint16_t verb) {
    if (!vector_contains(verbs, verb)) verbs.push_back(verb);
}

void InputProcessor::map_key(uint8_t key, uint16_t verb) {
    key_map[verb] = (SDL_Keycode) key;
    addVerb(verb);
}

//TODO: change all chars to uint8_t
bool InputProcessor::isVerbMapped(uint16_t verb) {
    return key_map.find(verb) != key_map.end();
}

char InputProcessor::getBoundKey(uint16_t verb) {
    return (char) key_map[verb];
}

bool InputProcessor::isBoundKeyPressed(uint16_t verb) {
    if (isVerbMapped(verb)) return isKeyPressed(getBoundKey(verb));
    else return false;
}

bool InputProcessor::isKeyPressed(char key) {
    if (vector_contains(pressed_keyboard_keys, (int) key)) return true;
    else return false;
}

void InputProcessor::addHandler(InputHandler *handler) {
    handlers.push_back(handler);
}

void InputProcessor::removeHandler(InputHandler *handler) {
    auto index = find(handlers.begin(), handlers.end(), handler);
    if (index != handlers.end()) handlers.erase(index);
}

InputProcessor::~InputProcessor() {
    for (auto *handler: handlers) {
        delete handler;
    }
    handlers.clear();
}

void InputProcessor::updateHandlers(InputType type, SDL_Keycode input) {
    for (auto handler: handlers) {
        switch (type) {
            case DOWN:
                handler->onKeyDown((char) input);
                break;
            case HOLD:
                handler->onKeyHold((char) input);
                break;
            case UP:
                handler->onKeyUp((char) input);
                break;
        }
    }
}

//SDL_Keycode InputProcessor::getKeyboardInput() {
//    return pressed_keyboard_keys[keyboard_i++];
//}
//
//unsigned char InputProcessor::getMouseButtonInput() {
//    return pressed_mouse_buttons[mouse_i++];
//}
//
//Position2Df InputProcessor::getMouseDrag() {
//    Position2Df drag = Position2Df();
//    drag.x = (float) (mouseDrag.x - mousePos.x) / 320.0f * 2.75f;
//    drag.y = (float) (mouseDrag.y - mousePos.y) / 240.0f * 2.0625f;
//    mousePos.x = mouseDrag.x;
//    mousePos.y = mouseDrag.y;
//    return drag;
//}
//
//bool InputProcessor::hasProcessedKeyboardInput() {
//    return !pressed_keyboard_keys.empty() && keyboard_i != pressed_keyboard_keys.size();
//}
//
//bool InputProcessor::hasProcessedMouseButtonInput() {
//    return !pressed_mouse_buttons.empty() && mouse_i != pressed_mouse_buttons.size();
//}
//
//bool InputProcessor::isMouseDragged() const {
//    return leftButtonPressed;
//}
//
//
//Position2D InputProcessor::getMouseCoordinates() {
//    Position2D coordinates = Position2D();
//    SDL_GetMouseState(&(coordinates.x), &(coordinates.y));
//    return coordinates;
//}
