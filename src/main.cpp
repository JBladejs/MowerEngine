#include "Mower.h"

//TODO: try to convert as many pointers to values as possible

class TestSystem: public System {};

int main(int argc, char *args[]) {
    Mower engine = Mower::getInstance();
    engine.start();
    return engine.getExitCode();
}