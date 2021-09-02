//
// Created by JJBla on 8/25/2021.
//
#pragma once

#ifndef MOWERENGINE_COMPONENTMANAGER_H
#define MOWERENGINE_COMPONENTMANAGER_H

#include "ECSTypes.h"
#include "ComponentPool.h"
#include <unordered_map>

class ComponentManager {
private:
    //TODO: implement a similar system as in EntityManager
    ComponentType next_type = 0;
    std::unordered_map<const char*, ComponentType> component_types{};
    std::unordered_map<const char*, IComponentPool*> component_pools{};

    ComponentManager() = default;
public:
    static ComponentManager& getInstance();

    ComponentManager(ComponentManager const&) = delete;
    void operator=(ComponentManager const&) = delete;
    ~ComponentManager() = default;

    template<typename C>
    void registerComponent();
    template <typename C>
    ComponentType getComponentType();

    //TODO: change to bool
    template <typename C>
    void addComponent(uint32_t entityID, C component);
    //TODO: change to bool
    template <typename C>
    void removeComponent(uint32_t entityID);
    void entityDestroyed(uint32_t entityID);

    template<typename C>
    C getComponent(uint32_t entityID);

private:
    template <typename C>
    ComponentPool<C>* getComponentPool();
};

inline ComponentManager &ComponentManager::getInstance() {
    static ComponentManager instance;
    return instance;
}

template<typename C>
inline void ComponentManager::registerComponent() {
    //TODO: throw exception if component is already registered
    const char* typeName = typeid(C).name();
    component_types[typeName] = next_type++;
    //TODO: investigate using shared pointer here
    component_pools[typeName] = new ComponentPool<C>;
}

template<typename C>
inline ComponentType ComponentManager::getComponentType() {
    const char* typeName = typeid(C).name();
    //TODO: error checking
    return component_types[typeName];
}

template<typename C>
inline void ComponentManager::addComponent(uint32_t entityID, C component) {
    //TODO: check for component registration (either throw exception or automatically register the component)
    getComponentPool<C>()->insertData(entityID, component);
}

template<typename C>
inline void ComponentManager::removeComponent(uint32_t entityID) {
    getComponentPool<C>()->removeData(entityID);
}

inline void ComponentManager::entityDestroyed(uint32_t entityID) {
    for (auto const& pair : component_pools) {
        auto const& component_pool = pair.second;
        component_pool->entityDestroyed(entityID);
    }
}

template<typename C>
inline C ComponentManager::getComponent(uint32_t entityID) {
    return getComponentPool<C>()->getData(entityID);
}

template<typename C>
inline ComponentPool<C> *ComponentManager::getComponentPool() {
    const char* typeName = typeid(C).name();
    //TODO: throw error if memory pool is not there
    return component_pools[typeName];
}


#endif //MOWERENGINE_COMPONENTMANAGER_H
