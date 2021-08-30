//
// Created by goon on 16.07.2021.
//
#ifndef MOWERENGINE_ENTITYMANAGER_H
#define MOWERENGINE_ENTITYMANAGER_H

#include <vector>
#include <cstdint>
#include <queue>
#include "../../util/Bag.h"
#include "ComponentManager.hpp"

class Entity;

class EntityManager {
private:
    //TODO: go through the rest of the class and change pointers to references when pointers are not necessary
    ComponentManager& component_manager = ComponentManager::getInstance();
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


#endif //MOWERENGINE_ENTITYMANAGER_H
