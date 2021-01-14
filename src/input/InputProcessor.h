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
        std::vector<SDL_Keycode> pressedKeys;
        bool leftButtonPressed;
        Position2D mousePos{};
        Position2D mouseDrag{};
        int i;
    public:
        InputProcessor();

        void processInput(SDL_Event input);

        SDL_Keycode getProcessedKeys();

        Position2Df getMouseDrag();

        bool hasProcessedKeys();

        bool isMouseDragged();

        void endProcessing();

        Position2Df getMouseCoordinates();
    };
}

#endif //MOWERENGINE_INPUTPROCESSOR_H
