//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/ecs/Entity.h"
#include "../../logic/components/Position.h"
#include "../../logic/components/Textured.h"

void LuaEntity::bind(sol::state &lua) {
    lua.new_usertype<Entity>("Entity",
                             "addPosition", &Entity::addComponent<Position>,
                             "addTexturing", &Entity::addComponent<Textured>);
}