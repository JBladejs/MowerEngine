//
// Created by JJBla on 9/14/2021.
//

#ifndef MOWERENGINE_LUACOLLIDER_H
#define MOWERENGINE_LUACOLLIDER_H


#include <state.hpp>
#include "../logic/components/Collider.h"

namespace LuaCollider {
    void bind(sol::state& lua);
};


#endif //MOWERENGINE_LUACOLLIDER_H