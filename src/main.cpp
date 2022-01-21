
#include "Engine.h"
#include "sol/sol.hpp"

int main(int argc, char *args[]) {
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    lua.script("print('testing lua')");
    auto engine = Engine();
    engine.start();
    return engine.getExitCode();
}