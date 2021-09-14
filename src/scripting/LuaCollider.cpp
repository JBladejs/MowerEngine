//
// Created by JJBla on 9/14/2021.
//

#include "LuaCollider.h"
#include "../logic/components/Collider.h"

void LuaCollider::bind(sol::state& lua) {
    lua.new_usertype<BoxCollider>("BoxCollider",
                                   "x", &BoxCollider::x,
                                   "y", &BoxCollider::y,
                                   "w", &BoxCollider::w,
                                   "h", &BoxCollider::h
                                   );

    lua.new_usertype<CircleCollider>("CircleCollider",
                                   "x", &CircleCollider::x,
                                   "y", &CircleCollider::y,
                                   "r", &CircleCollider::r
    );
}
