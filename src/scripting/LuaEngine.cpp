//
// Created by Alan Ćwiek on 2022-01-23.
//

#include "LuaEngine.h"
#include "LuaBindings.h"

static sol::state* lua;

void LuaEngine::init() {
    lua = new sol::state();
    lua->open_libraries(sol::lib::base);

#define BIND(_name)  \
        _name::bind(*lua);

    BIND(LuaCollider)
    BIND(LuaCollision)
    BIND(LuaCoordinator)
    BIND(LuaEntity)
    BIND(LuaPosition)
    BIND(LuaSystem)
    BIND(LuaTextured)
    BIND(LuaTexturingSystem)
}
