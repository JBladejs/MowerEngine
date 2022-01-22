//
// Created by Alan Ćwiek on 2022-01-22.
//

#ifndef MOWERENGINE_LUABINDINGS_H
#define MOWERENGINE_LUABINDINGS_H

#include <state.hpp>

#define _BINDING_DECL(_name)            \
        namespace _name {               \
            void bind(sol::state& lua); \
        }

_BINDING_DECL(LuaCollider)
_BINDING_DECL(LuaCollision)
_BINDING_DECL(LuaCoordinator)
_BINDING_DECL(LuaEntity)
_BINDING_DECL(LuaPosition)
_BINDING_DECL(LuaSystem)
_BINDING_DECL(LuaTextured)
_BINDING_DECL(LuaTexturingSystem)

#endif //MOWERENGINE_LUABINDINGS_H
