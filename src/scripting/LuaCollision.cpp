//
// Created by JJBla on 9/14/2021.
//

#include "LuaCollision.h"

void LuaCollision::bind(sol::state &lua) {
    lua.new_usertype<Collision>("Collision",
                                "collidingEntity", &Collision::collidingEntity
                                );
}
