#include <iostream>
#include "Mower.h"
#include "graphics/Color.h"

int main(int argc, char *args[]) {
    Mower engine = Mower();
    engine.start();
    return engine.getExitCode();
}
