//
// Created by JJBla on 8/26/2021.
//
#pragma once

#ifndef MOWERENGINE_COMPONENTPOOL_H
#define MOWERENGINE_COMPONENTPOOL_H

#include <unordered_map>
#include "../../util/Bag.h"

class IComponentPool {
public:
    virtual ~IComponentPool() = default;
    virtual void entityDestroyed(uint32_t entityID) = 0;
};

template <typename C>
class ComponentPool: public IComponentPool {
private:
    Bag<C> components;
    std::unordered_map<uint32_t, uint32_t> entity_to_index;
    std::unordered_map<uint32_t, uint32_t> index_to_entity;
public:
    bool insertData(uint32_t entityID, C component) {
        if (entity_to_index.find(entityID) == entity_to_index.end()) return false;
        uint32_t index = components.size() - 1;
        //TODO: replace component if necessary
        components.add(component);
        entity_to_index[entityID] = index;
        index_to_entity[index] = entityID;
        return true;
    }

    void removeData(uint32_t entityID) {
        components.remove(entity_to_index[entityID]);
        uint32_t new_index = components.get(entityID);
        entity_to_index[entityID] = new_index;
        index_to_entity[new_index] = entityID;
    }

    void entityDestroyed(uint32_t entityID) override {
        if (entity_to_index.find(entityID) != entity_to_index.end())
            removeData(entityID);
    }

    C& getData(uint32_t entityID) {
        return entity_to_index[entityID];
    }

    uint32_t size() {
        return components.size();
    }
};


#endif //MOWERENGINE_COMPONENTPOOL_H
