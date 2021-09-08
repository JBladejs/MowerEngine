//
// Created by JJBla on 9/4/2021.
//

#ifndef MOWERENGINE_TEXTURINGSYSTEM_H
#define MOWERENGINE_TEXTURINGSYSTEM_H

#include <iostream>
#include "../ecs/System.h"
#include "../ecs/Coordinator.h"
#include "../components/Textured.h"
#include "../components/Position.h"

class TexturingSystem: public System {
public:
    static void initialize();
    void update() override;
    void render() override;
};

#endif //MOWERENGINE_TEXTURINGSYSTEM_H
