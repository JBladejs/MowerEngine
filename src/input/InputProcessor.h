//
// Created by JJBla on 1/14/2021.
//

#ifndef MOWERENGINE_INPUTPROCESSOR_H
#define MOWERENGINE_INPUTPROCESSOR_H

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include "handlers/InputHandler.h"

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
    InputHandler *handler{};
    std::vector<uint16_t> verbs;
    //TODO: do this in a more optimized way (without using two vectors)
    std::map<uint16_t, SDL_Keycode> key_map;
    std::map<SDL_Keycode, uint16_t> verb_map;
    int keyboard_i;
    int mouse_i;
    std::vector<SDL_Keycode> pressed_keyboard_keys;
    std::vector<uint8_t> pressed_mouse_buttons;
    bool leftButtonPressed;
    Position2D mousePos{};
    Position2D mouseDrag{};
public:
    InputProcessor();
    ~InputProcessor();

//    static const char* getKeyName(uint8_t key);

    void setHandler(InputHandler *inputHandler);
    void updateHandler(InputType type, SDL_Keycode input);

    void processInput(SDL_Event input);
    void endProcessing();

    void addVerb(uint16_t verb);
    void map_key(uint8_t key, uint16_t verb);
    bool isVerbMapped(uint16_t verb);
    uint8_t getBoundKey(uint16_t verb);
    bool isKeyMapped(uint8_t key);
    uint16_t getBoundVerb(uint8_t key);
    bool isBoundKeyPressed(uint16_t verb);
    bool isKeyPressed(uint8_t key);
//    SDL_Keycode getKeyboardInput();
//    unsigned char getMouseButtonInput();
//    Position2Df getMouseDrag();
//    bool hasProcessedKeyboardInput();
//    bool hasProcessedMouseButtonInput();
//    bool isMouseDragged() const;
//    static Position2D getMouseCoordinates();
};

#endif //MOWERENGINE_INPUTPROCESSOR_H
