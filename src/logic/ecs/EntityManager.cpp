//
// Created by JJBla on 8/24/2021.
//
#include <iostream>
#include "EntityManager.h"

#include "Entity.h"

Entity& EntityManager::createEntity() {
    uint32_t id = getAvailableID();
    auto *entity = new Entity(id);
    entities.set(id, entity);
    active_entities++;
    return *entity;
}

Entity &EntityManager::getEntity(uint32_t entityID) {
    return *entities.get(entityID);
}

void EntityManager::removeEntity(Entity& entity) {
    if (!isEntityRegistered(entity)) return;
    if (entity.getID() == entities.size() - 1) next_id--;
    else available_ids.push(entity.getID());
    component_manager.entityDestroyed(entity.getID());
    active_entities--;
    delete &entity;
    entities.set(entity.getID(), nullptr);
}

uint32_t EntityManager::getNumberOfActiveEntities() const {
    return active_entities;
}

EntityManager::~EntityManager() {
    for (uint32_t i = 0; i < entities.size(); i++) {
        delete entities.get(i);
    }
    entities.clear();
}

uint32_t EntityManager::getAvailableID() {
    if (!available_ids.empty()) {
        uint32_t id = available_ids.front();
        available_ids.pop();
        return id;
    } else return next_id++;
}

bool EntityManager::isEntityRegistered(Entity& entity) {
    return entities.get(entity.getID()) == &entity;
}


