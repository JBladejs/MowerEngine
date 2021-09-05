//
// Created by JJBla on 8/26/2021.
//
#ifndef MOWERENGINE_COMPONENTPOOL_H
#define MOWERENGINE_COMPONENTPOOL_H

#include <vector>
#include <unordered_map>
#include "ECSTypes.h"
//#include "../../util/Bag.h"

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
    //TODO: change that back into Bag
    std::vector<C> components{};
    std::unordered_map<EntityID, uint32_t> entity_to_index{};
    std::unordered_map<uint32_t, EntityID> index_to_entity{};
};

template<typename C>
bool ComponentPool<C>::insertData(EntityID entityID, C component) {
    if (entity_to_index.find(entityID) != entity_to_index.end()) return false;
    uint32_t index = components.size();
    //TODO: replace component if necessary
    components.push_back(component);
    entity_to_index[entityID] = index;
    index_to_entity[index] = entityID;
    return true;
}

template<typename C>
void ComponentPool<C>::removeData(EntityID entityID) {
    //TODO: check this
//    components.erase(entity_to_index[entityID]);
    uint32_t new_index = components.size();
    entity_to_index[entityID] = new_index;
    index_to_entity[new_index] = entityID;
}

template<typename C>
void ComponentPool<C>::entityDestroyed(EntityID entityID) {
    if (entity_to_index.find(entityID) != entity_to_index.end())
        removeData(entityID);
}

template<typename C>
C& ComponentPool<C>::getData(EntityID entityID){
    return components[entity_to_index[entityID]];
}

template<typename C>
uint32_t ComponentPool<C>::size() const{
    return components.size();
}


#endif //MOWERENGINE_COMPONENTPOOL_H
