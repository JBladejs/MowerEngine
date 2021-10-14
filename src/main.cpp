#include "Engine.h"
#include "logic/components/Position.h"
#include "logic/components/Textured.h"
#include "graphics/texturing/Sprite.h"
//TODO: try to convert as many pointers to values as possible

class CustomEngine: public Engine {
    void onInit() override {
        auto& check = Coordinator::getInstance().createEntity();
        check.addComponent<Position>({250.f, 250.f});
        check.addComponent<Textured>({new Sprite("assets/circle2.png", true, 0x00FFFF)});
    }
};

int main(int argc, char *args[]) {
    CustomEngine engine = CustomEngine();
    engine.start();
    return engine.getExitCode();
}