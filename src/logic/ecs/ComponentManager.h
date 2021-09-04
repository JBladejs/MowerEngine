//
// Created by JJBla on 8/25/2021.
//
#ifndef MOWERENGINE_COMPONENTMANAGER_H
#define MOWERENGINE_COMPONENTMANAGER_H

#include <memory>
#include <unordered_map>
#include <iostream>
#include "ComponentPool.h"

class ComponentManager {
public:
    template<typename C>
    void registerComponent();
    template <typename C>
    ComponentType getComponentType();

    //TODO: change to bool
    template <typename C>
    void addComponent(EntityID entityID, C component);
    //TODO: change to bool
    template <typename C>
    void removeComponent(EntityID entityID);
    template<typename C>
    C& getComponent(EntityID entityID);

    void entityDestroyed(EntityID entityID);

private:
    ComponentType next_type = 0;
    std::unordered_map<const char*, ComponentType> component_types{};
    std::unordered_map<const char*, IComponentPool*> component_pools{};

    template <typename C>
    ComponentPool<C>* getComponentPool();

    //Singleton:
private:
    ComponentManager() = default;
public:
    static ComponentManager& getInstance();
    ComponentManager(ComponentManager const&) = delete;
    void operator=(ComponentManager const&) = delete;
    ~ComponentManager() = default;
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
inline void ComponentManager::addComponent(EntityID entityID, C component) {
    //TODO: check for component registration (either throw exception or automatically register the component)
    getComponentPool<C>()->insertData(entityID, component);
}

template<typename C>
inline void ComponentManager::removeComponent(EntityID entityID) {
    getComponentPool<C>()->removeData(entityID);
}

inline void ComponentManager::entityDestroyed(EntityID entityID) {
    for (auto const& pair : component_pools) {
        auto const& component_pool = pair.second;
        component_pool->entityDestroyed(entityID);
    }
}

template<typename C>
inline C& ComponentManager::getComponent(EntityID entityID) {
    return getComponentPool<C>()->getData(entityID);
}

template<typename C>
inline ComponentPool<C>* ComponentManager::getComponentPool() {
    const char* typeName = typeid(C).name();
    //TODO: throw error if memory pool is not there
    return (ComponentPool<C>*) component_pools[typeName];
}


#endif //MOWERENGINE_COMPONENTMANAGER_H
