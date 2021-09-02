//
// Created by goon on 16.07.2021.
//
#ifndef MOWERENGINE_ENTITYMANAGER_H
#define MOWERENGINE_ENTITYMANAGER_H

#include <vector>
#include <cstdint>
#include <queue>
#include "../../util/Bag.h"

class Entity;

class EntityManager {
private:
    //TODO: go through the rest of the class and change pointers to references when pointers are not necessary
    Bag<Entity*> entities;
    std::queue<uint32_t> available_ids;
    uint32_t active_entities = 0;
    uint32_t next_id = 0;
public:
    static EntityManager& getInstance() {
        static EntityManager instance;
        return instance;
    }
    EntityManager(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
    Entity& createEntity();
    Entity& getEntity(uint32_t entityID);
    void removeEntity(Entity& entity);
    uint32_t getNumberOfActiveEntities() const;
    ~EntityManager();
private:
    EntityManager() = default;
    bool isEntityRegistered(Entity& entity);
    uint32_t getAvailableID();
};

#include <iostream>
#include "Entity.h"

inline Entity& EntityManager::createEntity() {
    uint32_t id = getAvailableID();
    auto *entity = new Entity(id);
    entities.set(id, entity);
    active_entities++;
    return *entity;
}

inline Entity &EntityManager::getEntity(uint32_t entityID) {
    return *entities.get(entityID);
}

inline void EntityManager::removeEntity(Entity& entity) {
    if (!isEntityRegistered(entity)) return;
    if (entity.getID() == entities.size() - 1) next_id--;
    else available_ids.push(entity.getID());
    active_entities--;
    delete &entity;
    entities.set(entity.getID(), nullptr);
}

inline uint32_t EntityManager::getNumberOfActiveEntities() const {
    return active_entities;
}

inline EntityManager::~EntityManager() {
    for (uint32_t i = 0; i < entities.size(); i++) {
        delete entities.get(i);
    }
    entities.clear();
}

inline uint32_t EntityManager::getAvailableID() {
    if (!available_ids.empty()) {
        uint32_t id = available_ids.front();
        available_ids.pop();
        return id;
    } else return next_id++;
}

inline bool EntityManager::isEntityRegistered(Entity& entity) {
    return entities.get(entity.getID()) == &entity;
}


#endif //MOWERENGINE_ENTITYMANAGER_H
