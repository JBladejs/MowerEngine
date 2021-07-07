#include <iostream>
#include "Engine.h"
#include "graphics/Color.h"

using namespace MowerEngine;

int main(int argc, char *args[]) {
    Engine engine = Engine();
    engine.start();
    return engine.getExitCode();
}
