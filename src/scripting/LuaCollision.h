//
// Created by JJBla on 9/14/2021.
//

#ifndef MOWERENGINE_LUACOLLISION_H
#define MOWERENGINE_LUACOLLISION_H


#include <state.hpp>
#include "../logic/components/Collision.h"

namespace LuaCollision {
    void bind(sol::state& lua);
};


#endif //MOWERENGINE_LUACOLLISION_H
