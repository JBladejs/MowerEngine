#include "Engine.h"
#include "sol/sol.hpp"
//TODO: try to convert as many pointers to values as possible

int main(int argc, char *args[]) {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('testing lua')");
    Engine engine = Engine::getInstance();
    engine.start();
    return engine.getExitCode();
}