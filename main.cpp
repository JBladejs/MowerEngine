#include<SDL2/SDL.h>
#include "Engine.h"

int main(int argc, char* args[]) {
    Engine engine = Engine();
    engine.start();
    return engine.getExitCode();
}
