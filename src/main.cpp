#include <iostream>
#include "Engine.h"
#include "graphics/Color.h"

int main(int argc, char *args[]) {
    Engine engine = Engine();
    engine.start();
    return engine.getExitCode();
}
