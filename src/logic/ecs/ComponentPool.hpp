//
// Created by JJBla on 8/26/2021.
//

#ifndef MOWERENGINE_COMPONENTPOOL_HPP
#define MOWERENGINE_COMPONENTPOOL_HPP

class IComponentPool {
public:
    virtual ~IComponentPool() = default;
    virtual void entityDestroyed() = 0;
};

#include "../../util/Bag.h"
#include <unordered_map>

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

    bool removeData(uint32_t entityID) {
        if (entity_to_index.find(entityID) == entity_to_index.end()) return false;
        components.remove(entity_to_index[entityID]);
        uint32_t new_index = components.get(entityID);
        entity_to_index[entityID] = new_index;
        index_to_entity[new_index] = entityID;
        return true;
    }

    C& getData(uint32_t entityID) {
        return entity_to_index[entityID];
    }

    uint32_t size() {
        return components.size();
    }
};


#endif //MOWERENGINE_COMPONENTPOOL_HPP
