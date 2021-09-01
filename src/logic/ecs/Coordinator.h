//
// Created by JJBla on 8/29/2021.
//
#ifndef MOWERENGINE_COORDINATOR_H
#define MOWERENGINE_COORDINATOR_H

//#include "ECSTypes.h"

//TODO: move singleton to a base class
class Coordinator {
private:
    ComponentManager& component_manager;
    EntityManager& entity_manger;
    SystemManager& system_manager;
public:
    Entity& createEntity() {
        return entity_manger.createEntity();
    }
    Entity& getEntity(EntityID entityID) {
        return entity_manger.getEntity(entityID);
    }
    void removeEntity(Entity& entity) {
        entity_manger.removeEntity(entity);
        EntityID id = entity.

        component_manager.entityDestroyed(en)
        system_manager.entityDestroyed()
    }
    uint32_t getNumberOfActiveEntities() const {
        return entity_manger.getNumberOfActiveEntities();
    }

    template<typename C>
    bool registerComponent() {
        return component_manager.registerComponent<C>();
    }
    template <typename C>
    ComponentType getComponentType() {
        return component_manager.getComponentType<C>();
    }
    template <typename C>
    void addComponent(EntityID entityID, C component) {
        component_manager.addComponent(entityID, component);
    }
    template <typename C>
    void removeComponent(EntityID entityID) {
        component_manager.removeComponent<C>(entityID);
    }
    template<typename C>
    C getComponent(EntityID entityID) {
        return component_manager.getComponentType<C>(entityID);
    }
private:
    Coordinator(): component_manager(ComponentManager::getInstance()), entity_manger(EntityManager::getInstance()), system_manager(SystemManager::getInstance()) {}
public:
    static Coordinator& getInstance() {
        static Coordinator instance;
        return instance;
    }
    Coordinator(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
};


#endif //MOWERENGINE_COORDINATOR_H
