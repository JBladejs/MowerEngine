//
// Created by JJBla on 9/14/2021.
//

#ifndef MOWERENGINE_LUAPOSITION_H
#define MOWERENGINE_LUAPOSITION_H


#include <state.hpp>
#include "../logic/components/Position.h"

namespace LuaPosition {
    void bind(sol::state& lua);
};


#endif //MOWERENGINE_LUAPOSITION_H
