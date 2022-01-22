//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/components/Position.h"

void LuaPosition::bind(sol::state &lua) {
    lua.new_usertype<Position>("Position",
                               "x", &Position::x,
                               "y", &Position::y);
}
