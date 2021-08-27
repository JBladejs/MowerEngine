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
    Bag<Entity*> entities;
    std::queue<uint32_t> available_ids;
    uint32_t next_id = 0;
public:
    static EntityManager& getInstance() {
        static EntityManager instance;
        return instance;
    }
    EntityManager(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
    Entity& createEntity();
    bool removeEntity(Entity& entity);
    uint32_t getNumberOfActiveEntities();
    ~EntityManager();
private:
    EntityManager() = default;
    uint32_t getAvailableID();
};


#endif //MOWERENGINE_ENTITYMANAGER_H
