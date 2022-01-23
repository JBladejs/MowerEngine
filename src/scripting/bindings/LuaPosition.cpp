//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/components/Position.h"

void LuaPosition::bind(sol::state &lua) {
    lua.new_usertype<Position>("Position",
                               sol::call_constructor,
                               sol::factories([](float x, float y) {
                                   return Position { x, y };
                               }),
                               "x", &Position::x,
                               "y", &Position::y);
}
