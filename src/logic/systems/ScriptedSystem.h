//
// Created by JJBla on 9/14/2021.
//

#ifndef MOWERENGINE_SCRIPTEDSYSTEM_H
#define MOWERENGINE_SCRIPTEDSYSTEM_H


#include "../ecs/System.h"

class ScriptedSystem: public System {
public:
    const char* scriptName;
    void initialize();
    void render() override;
    void update() override;
};


#endif //MOWERENGINE_SCRIPTEDSYSTEM_H
