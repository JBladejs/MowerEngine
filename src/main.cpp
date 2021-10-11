#include "Engine.h"
//TODO: try to convert as many pointers to values as possible

int main(int argc, char *args[]) {
    Engine engine = Engine::getInstance();
    engine.start();
    return engine.getExitCode();
}