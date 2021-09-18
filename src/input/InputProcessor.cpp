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
    handler = nullptr;
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
            if (!vector_contains(pressed_keyboard_keys, input.key.keysym.sym)) {
                pressed_keyboard_keys.push_back(input.key.keysym.sym);
                updateHandler(DOWN, input.key.keysym.sym);
            }
            break;
        }
        case SDL_KEYUP: {
            auto iter = std::find(pressed_keyboard_keys.begin(), pressed_keyboard_keys.end(), input.key.keysym.sym);
            if (iter != pressed_keyboard_keys.end()) {
                pressed_keyboard_keys.erase(iter);
                updateHandler(UP, input.key.keysym.sym);
            }
            break;
        }
//        case SDL_MOUSEBUTTONDOWN: {
//            if (vector_contains(pressed_mouse_buttons, input.button.button))
//                pressed_mouse_buttons.push_back(input.button.button);
//            break;
//        }
//        case SDL_MOUSEBUTTONUP: {
//            auto iter = std::find(pressed_mouse_buttons.begin(), pressed_mouse_buttons.end(), input.button.button);
//            if (iter != pressed_mouse_buttons.end()) pressed_mouse_buttons.erase(iter);
//            break;
//        }
    }
}

void InputProcessor::endProcessing() {
    //TODO: make sure that the first press doesn't count into that
    for (auto key: pressed_keyboard_keys) {
        updateHandler(HOLD, key);
    }
    keyboard_i = 0;
    mouse_i = 0;
}

void InputProcessor::addVerb(uint16_t verb) {
    if (!vector_contains(verbs, verb)) verbs.push_back(verb);
}

void InputProcessor::map_key(uint8_t key, uint16_t verb) {
    if (key_map.find(verb) != key_map.end())
        verb_map.erase(key_map[verb]);
    if (verb_map.find(key) != verb_map.end())
        key_map.erase(verb_map[key]);
    key_map[verb] = (SDL_Keycode) key;
    verb_map[key] = verb;
    addVerb(verb);
}

bool InputProcessor::isVerbMapped(uint16_t verb) {
    return key_map.find(verb) != key_map.end();
}

bool InputProcessor::isKeyMapped(uint8_t key) {
    return verb_map.find(key) != verb_map.end();
}

//TODO: add error checking
uint8_t InputProcessor::getBoundKey(uint16_t verb) {
    return (uint8_t) key_map[verb];
}

uint16_t InputProcessor::getBoundVerb(uint8_t key) {
    return verb_map[key];
}

bool InputProcessor::isBoundKeyPressed(uint16_t verb) {
    if (isVerbMapped(verb)) return isKeyPressed(getBoundKey(verb));
    else return false;
}

bool InputProcessor::isKeyPressed(uint8_t key) {
    if (vector_contains(pressed_keyboard_keys, (int) key)) return true;
    else return false;
}

//const char *InputProcessor::getKeyName(uint8_t key) {
////    return SDL_Keysym((SDL_Keycode) key);
//}

void InputProcessor::updateHandler(InputType type, SDL_Keycode input) {
    if (handler == nullptr) return;
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

void InputProcessor::setHandler(InputHandler *inputHandler) {
    handler = inputHandler;
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
