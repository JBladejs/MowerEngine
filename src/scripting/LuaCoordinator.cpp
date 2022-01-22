//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../logic/ecs/Coordinator.h"


void LuaCoordinator::bind(sol::state &lua) {
    lua.new_usertype<Coordinator>("Coordinator",

        "", &Coordinator::createEntity,
        "", &Coordinator::getEntity,
        "", &Coordinator::removeEntity,
        //TODO: use resolve
        "", &Coordinator::getNumberOfActiveEntities,

        //TODO: nail those down to specific components
//        "", &Coordinator::registerComponent,
//        "", &Coordinator::getComponentType,
//        "", &Coordinator::addComponent,
//        "", &Coordinator::removeComponent,
//        "", &Coordinator::getComponent,

        //TODO: nail those down to specific Systems
//        "", &Coordinator::registerSystem,
//        "", &Coordinator::observeComponentType,
        "", &Coordinator::update,
        "", &Coordinator::render);
}
