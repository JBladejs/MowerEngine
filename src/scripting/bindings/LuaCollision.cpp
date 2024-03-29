//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/components/Collision.h"


void LuaCollision::bind(sol::state &lua) {
    lua.new_usertype<Collision>("Collision",
                                "collidingEntity", &Collision::collidingEntity
                                );
}
