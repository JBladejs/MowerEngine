//
// Created by JJBla on 9/14/2021.
//

#include "ScriptSystem.h"
#include "../ecs/Coordinator.h"
#include "../components/Script.h"

void ScriptSystem::initialize() {
    auto& coordinator = Coordinator::getInstance();
    coordinator.registerSystem<ScriptSystem>();
    coordinator.registerComponent<Script>();
    coordinator.observeComponentType<ScriptSystem>(coordinator.getComponentType<Script>());
}

void ScriptSystem::render() {
    for (const auto& entity: entities) {
        //TODO: execute render function from script contained in component and pass entity to it
    }
}

void ScriptSystem::update() {
    for (const auto& entity: entities) {
        //TODO: execute update function from script contained in component and pass entity to it
    }
}