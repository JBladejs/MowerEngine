//
// Created by JJBla on 1/14/2021.
//

#ifndef MOWERENGINE_INPUTPROCESSOR_H
#define MOWERENGINE_INPUTPROCESSOR_H

#include <SDL2/SDL.h>
#include <vector>

namespace MowerEngine {

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
        int keyboard_i;
        int mouse_i;
        std::vector<SDL_Keycode> pressed_keyboard_keys;
        std::vector<unsigned char> pressed_mouse_buttons;
        bool leftButtonPressed;
        Position2D mousePos{};
        Position2D mouseDrag{};
    public:
        InputProcessor();

        void processInput(SDL_Event input);

        SDL_Keycode getKeyboardInput();
        unsigned char getMouseButtonInput();

        Position2Df getMouseDrag();

        bool hasProcessedKeyboardInput();

        bool hasProcessedMouseButtonInput();

        bool isMouseDragged();

        void endProcessing();

        Position2D getMouseCoordinates();
    };
}

#endif //MOWERENGINE_INPUTPROCESSOR_H
