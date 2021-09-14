//
// Created by JJBla on 9/14/2021.
//

#ifndef MOWERENGINE_SCRIPTSYSTEM_H
#define MOWERENGINE_SCRIPTSYSTEM_H


#include "../ecs/System.h"

class ScriptSystem: public System {
public:
    void initialize();
    void render() override;
    void update() override;
};


#endif //MOWERENGINE_SCRIPTSYSTEM_H
