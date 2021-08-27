//
// Created by JJBla on 8/25/2021.
//

#ifndef MOWERENGINE_COMPONENTMANAGER_HPP
#define MOWERENGINE_COMPONENTMANAGER_HPP

#include "ECSTypes.h"
#include "ComponentPool.hpp"
#include <unordered_map>

class ComponentManager {
private:
    //TODO: implement a similar system as in EntityManager
    componentType next_type = 0;
    std::unordered_map<const char*, componentType> component_types;
    std::unordered_map<const char*, IComponentPool*> component_pools;

    ComponentManager() = default;
public:
    static ComponentManager& getInstance() {
        static ComponentManager instance;
        return instance;
    }

    ComponentManager(ComponentManager const&) = delete;
    void operator=(ComponentManager const&) = delete;
    ~ComponentManager() = default;

    template<typename C>
    bool registerComponent() {
        const char* typeName = typeid(C).name();
        if (component_types.find(typeName) != component_types.end()) return false;
        component_types[typeName] = next_type++;
        //TODO: investigate using shared pointer here
        component_pools[typeName] = new ComponentPool<C>;
    }

    template <typename C>
    componentType getComponentType() {
        const char* typeName = typeid(C).name();
        //TODO: error checking
        return component_types[typeName];
    }

    template <typename C>
    void addComponent(uint32_t entityID, C component) {
        getComponentPool<C>()->insertData(entityID, component);
    }

    template <typename C>
    void removeComponent(uint32_t entityID) {
        getComponentPool<C>()->removeData(entityID);
    }

private:
    template <typename C>
    ComponentPool<C>* getComponentPool() {
        const char* typeName = typeid(C).name();
        //TODO: throw error if memory pool is not there
        return component_pools[typeName];
    }
};


#endif //MOWERENGINE_COMPONENTMANAGER_HPP
