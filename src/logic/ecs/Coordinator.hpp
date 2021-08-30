//
// Created by JJBla on 8/29/2021.
//
#ifndef MOWERENGINE_COORDINATOR_H
#define MOWERENGINE_COORDINATOR_H

#include "ECSTypes.h"

#include "ComponentManager.hpp"
#include "EntityManager.h"

class Entity;

//TODO: move singleton to a base class
class Coordinator {
private:
    ComponentManager& component_manager;
    EntityManager& entity_manger;
public:
    Entity& createEntity() {
        return entity_manger.createEntity();
    }
    Entity& getEntity(uint32_t entityID) {
        return entity_manger.getEntity(entityID);
    }
    void removeEntity(Entity& entity) {
        entity_manger.removeEntity(entity);
    }
    uint32_t getNumberOfActiveEntities() const {
        return entity_manger.getNumberOfActiveEntities();
    }

    template<typename C>
    bool registerComponent() {
        return component_manager.registerComponent<C>();
    }
    template <typename C>
    componentType getComponentType() {
        return component_manager.getComponentType<C>();
    }
    template <typename C>
    void addComponent(uint32_t entityID, C component) {
        component_manager.addComponent(entityID, component);
    }
    template <typename C>
    void removeComponent(uint32_t entityID) {
        component_manager.removeComponent<C>(entityID);
    }
    template<typename C>
    C getComponent(uint32_t entityID) {
        return component_manager.getComponentType<C>(entityID);
    }
private:
    Coordinator(): component_manager(ComponentManager::getInstance()), entity_manger(EntityManager::getInstance()) {}
public:
    static Coordinator& getInstance() {
        static Coordinator instance;
        return instance;
    }
    ~Coordinator() = default;
    Coordinator(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
};


#endif //MOWERENGINE_COORDINATOR_H
