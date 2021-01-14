//
// Created by JJBla on 1/14/2021.
//

#include <iostream>
#include <algorithm>
#include "InputProcessor.h"
#include "../util/misc_functions.h"

using namespace MowerEngine;

InputProcessor::InputProcessor() {
    i = 0;

    mousePos.x = 0;
    mousePos.y = 0;
    mouseDrag.x = 0;
    mouseDrag.y = 0;

    leftButtonPressed = false;
}

void InputProcessor::processInput(SDL_Event input) {
    switch (input.type) {
        case SDL_KEYDOWN: {
            if (!MowerEngine::vector_contains(pressedKeys, input.key.keysym.sym))
                pressedKeys.push_back(input.key.keysym.sym);
            break;
        }
        case SDL_KEYUP: {
            auto iter = std::find(pressedKeys.begin(), pressedKeys.end(), input.key.keysym.sym);
            if (iter != pressedKeys.end()) pressedKeys.erase(iter);
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            if (input.button.button == SDL_BUTTON_LEFT && !leftButtonPressed){
                leftButtonPressed = true;
                SDL_GetMouseState(&(mousePos.x), &(mousePos.y));
                mouseDrag.x = mousePos.x;
                mouseDrag.y = mousePos.y;
            }
            break;
        }
        case SDL_MOUSEBUTTONUP: {
            if (input.button.button == SDL_BUTTON_LEFT) leftButtonPressed = false;
            break;
        }
        case SDL_MOUSEMOTION: {
            SDL_GetMouseState(&(mouseDrag.x), &(mouseDrag.y));
            break;
        }
    }
}

SDL_Keycode InputProcessor::getProcessedKeys() {
    return pressedKeys[i++];
}

Position2Df InputProcessor::getMouseDrag() {
    Position2Df drag = Position2Df();
    drag.x = (float) (mouseDrag.x - mousePos.x) / 320.0f * 2.75f;
    drag.y = (float) (mouseDrag.y - mousePos.y) / 240.0f * 2.0625f;
    mousePos.x = mouseDrag.x;
    mousePos.y = mouseDrag.y;
    return drag;
}

bool InputProcessor::hasProcessedKeys() {
    return !pressedKeys.empty() && i != pressedKeys.size();
}

bool InputProcessor::isMouseDragged() {
    return leftButtonPressed;
}

void InputProcessor::endProcessing() {
    i = 0;
}

Position2Df InputProcessor::getMouseCoordinates() {
    Position2Df coordinates = Position2Df();
    coordinates.x = ((float) mouseDrag.x - 320.0f) / 320.0f * 2.75f;
    coordinates.y = -((float) mouseDrag.y - 240.0f) / 240.0f * 2.0625f;
    return coordinates;
}
