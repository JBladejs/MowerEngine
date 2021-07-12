//
// Created by JJBla on 1/14/2021.
//

#ifndef MOWERENGINE_INPUTPROCESSOR_H
#define MOWERENGINE_INPUTPROCESSOR_H

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "InputHandler.h"

//TODO: make it more static

enum InputType {
    DOWN, HOLD, UP
};

struct Position2D {
    int x;
    int y;
};

struct Position2Df {
    float x;
    float y;
};

class InputProcessor {
private:
    //TODO: use more controlled data types (like uint32)
    std::vector<InputHandler*> handlers;
    std::vector<uint16_t> verbs;
    std::map<uint16_t, SDL_Keycode> key_map;
    int keyboard_i;
    int mouse_i;
    std::vector<SDL_Keycode> pressed_keyboard_keys;
    std::vector<unsigned char> pressed_mouse_buttons;
    bool leftButtonPressed;
    Position2D mousePos{};
    Position2D mouseDrag{};
public:
    InputProcessor();
    ~InputProcessor();
    void addHandler(InputHandler *handler);
    void removeHandler(InputHandler *handler);
    //For updating:
    void processInput(SDL_Event input);
    void endProcessing();
    void updateHandlers(InputType type, SDL_Keycode input);
    //For bound input:
    void addVerb(uint16_t verb);
    void map_key(uint8_t key, uint16_t verb);
    bool isVerbMapped(uint16_t verb);
    char getBoundKey(uint16_t verb);
    bool isBoundKeyPressed(uint16_t verb);
    //For general input:
    bool isKeyPressed(char key);
//    SDL_Keycode getKeyboardInput();
//    unsigned char getMouseButtonInput();
//    Position2Df getMouseDrag();
//    bool hasProcessedKeyboardInput();
//    bool hasProcessedMouseButtonInput();
//    bool isMouseDragged() const;
//    static Position2D getMouseCoordinates();
};

#endif //MOWERENGINE_INPUTPROCESSOR_H
