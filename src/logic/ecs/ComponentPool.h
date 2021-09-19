//
// Created by JJBla on 8/26/2021.
//
#ifndef MOWERENGINE_COMPONENTPOOL_H
#define MOWERENGINE_COMPONENTPOOL_H

#include <unordered_map>
#include "ECSTypes.h"
#include "../../util/Bag.h"

class IComponentPool {
public:
    virtual ~IComponentPool() = default;
    virtual void entityDestroyed(EntityID entityID) = 0;
};

template <typename C>
class ComponentPool: public IComponentPool {
public:
    bool insertData(EntityID entityID, C component);
    void removeData(EntityID entityID);
    void entityDestroyed(EntityID entityID) override;
    C& getData(EntityID entityID);
    uint32_t size() const;

private:
    Bag<C> components{};
    std::unordered_map<EntityID, uint32_t> entity_to_index{};
    std::unordered_map<uint32_t, EntityID> index_to_entity{};
};

template<typename C>
bool ComponentPool<C>::insertData(EntityID entityID, C component) {
    if (entity_to_index.find(entityID) != entity_to_index.end()) return false;
    uint32_t index = components.size();
    //TODO: replace component if necessary
    components.add(component);
    entity_to_index[entityID] = index;
    index_to_entity[index] = entityID;
    return true;
}

template<typename C>
void ComponentPool<C>::removeData(EntityID entityID) {
    if (components.size() > 1) {
        uint32_t index = entity_to_index[entityID];
        uint32_t last_index = components.size() - 1;
        EntityID last_index_entity = index_to_entity[last_index];

        components.remove(index);

        entity_to_index[last_index_entity] = index;
        index_to_entity[index] = last_index_entity;

        entity_to_index.erase(entityID);
        index_to_entity.erase(last_index);
    } else {
        components.clear();
        entity_to_index.clear();
        index_to_entity.clear();
    }

}

template<typename C>
void ComponentPool<C>::entityDestroyed(EntityID entityID) {
    if (entity_to_index.find(entityID) != entity_to_index.end())
        removeData(entityID);
}

template<typename C>
C& ComponentPool<C>::getData(EntityID entityID){
    return components.get(entity_to_index[entityID]);
}

template<typename C>
uint32_t ComponentPool<C>::size() const{
    return components.size();
}


#endif //MOWERENGINE_COMPONENTPOOL_H
