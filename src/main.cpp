
#include "Engine.h"

int main(int argc, char *args[]) {
    auto engine = Engine();
    engine.start();
    return engine.getExitCode();
}