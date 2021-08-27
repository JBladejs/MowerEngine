//
// Created by JJBla on 8/24/2021.
//
#include <iostream>
#include "EntityManager.h"

#include "Entity.hpp"

Entity& EntityManager::createEntity() {
    auto *entity = new Entity(getAvailableID());
    entities.add(entity);
    return *entity;
}

bool EntityManager::removeEntity(Entity& entity) {
    bool success = entities.removeElement(&entity);
    if (entity.getID() == entities.size() - 1) next_id--;
    else available_ids.push(entity.getID());
    delete &entity;
    return success;
}

uint32_t EntityManager::getNumberOfActiveEntities() {
    return entities.size();
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
