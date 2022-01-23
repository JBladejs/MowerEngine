//
// Created by Alan Ćwiek on 2022-01-23.
//

#include "LuaEngine.h"
#include "bindings/LuaBindings.h"
#include "../logic/ecs/Coordinator.h"
#include "../logging/Log.h"

void LuaEngine::init() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);

#define BIND(_name)  \
        _name::bind(lua);

    BIND(LuaCollider)
    BIND(LuaCollision)
    BIND(LuaCoordinator)
    BIND(LuaEntity)
    BIND(LuaPosition)
//    BIND(LuaSystem)
    BIND(LuaTextured)
//    BIND(LuaTexturingSystem)

    Log::write("Running script...");
    lua["coordinator"] = &Coordinator::getInstance();
    lua.script_file("scripts/main.lua");
}
