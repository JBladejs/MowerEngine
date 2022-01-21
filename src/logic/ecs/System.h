//
// Created by goon on 15.07.2021.
//
#ifndef MOWERENGINE_SYSTEM_H
#define MOWERENGINE_SYSTEM_H

#include <set>
#include "ECSTypes.h"

class System {
public:
    std::set<EntityID> entities{};
    virtual void update() {}
    virtual void render() {}
};


#endif //MOWERENGINE_SYSTEM_H
