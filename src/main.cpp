#include <iostream>
#include "Mower.h"
#include "graphics/util/Color.h"
#include "util/Bag.h"
#include "logic/ecs/Entity.hpp"

//TODO: try to convert as many pointers to values as possible

int main(int argc, char *args[]) {
    Mower engine = Mower();
    engine.start();
    return engine.getExitCode();
}