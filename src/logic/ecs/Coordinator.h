//
// Created by JJBla on 8/29/2021.
//
#ifndef MOWERENGINE_COORDINATOR_H
#define MOWERENGINE_COORDINATOR_H

class SystemManager;

class Coordinator {
private:
    ComponentManager& component_manager;
    EntityManager& entity_manger;
    SystemManager& system_manager;
public:
    Entity& createEntity();
    Entity& getEntity(EntityID entityID);
    void removeEntity(Entity& entity);
    uint32_t getNumberOfActiveEntities() const;

    template<typename C>
    bool registerComponent();
    template <typename C>
    ComponentType getComponentType();
    template <typename C>
    void addComponent(EntityID entityID, C component);
    template <typename C>
    void removeComponent(EntityID entityID);
    template<typename C>
    C getComponent(EntityID entityID);

    template<typename S>
    S& registerSystem();
    template<typename S>
    void observeComponentType(ComponentType componentType);
    void update();
    void render();
    //Singleton:
private:
    Coordinator();
public:
    static Coordinator& getInstance() {
        static Coordinator instance;
        return instance;
    }
    Coordinator(EntityManager const&) = delete;
    void operator=(EntityManager const&) = delete;
};

#include "SystemManager.h"

inline Entity &Coordinator::createEntity() {
    return entity_manger.createEntity();
}

inline Entity &Coordinator::getEntity(EntityID entityID) {
    return entity_manger.getEntity(entityID);
}

inline void Coordinator::removeEntity(Entity &entity) {
    entity_manger.removeEntity(entity);
    EntityID id = entity.getID();

    component_manager.entityDestroyed(id);
    system_manager.entityDestroyed(id);
}

inline uint32_t Coordinator::getNumberOfActiveEntities() const {
    return entity_manger.getNumberOfActiveEntities();
}

template<typename C>
inline bool Coordinator::registerComponent() {
    return component_manager.registerComponent<C>();
}

template<typename C>
inline ComponentType Coordinator::getComponentType() {
    return component_manager.getComponentType<C>();
}

template<typename C>
inline void Coordinator::addComponent(EntityID entityID, C component) {
    component_manager.addComponent(entityID, component);
    system_manager.entitySignatureChanged(entityID);
}

template<typename C>
inline void Coordinator::removeComponent(EntityID entityID) {
    component_manager.removeComponent<C>(entityID);
    system_manager.entitySignatureChanged(entityID);
}

template<typename C>
inline C Coordinator::getComponent(EntityID entityID) {
    return component_manager.getComponentType<C>(entityID);
}

inline Coordinator::Coordinator() : component_manager(ComponentManager::getInstance()), entity_manger(EntityManager::getInstance()), system_manager(SystemManager::getInstance()) {}

template<typename S>
S &Coordinator::registerSystem() {
    system_manager.registerSystem<S>();
}

template<typename S>
void Coordinator::observeComponentType(ComponentType componentType) {
    system_manager.registerSystem<S>(componentType);
}

void Coordinator::update() {
    system_manager.update();
}

void Coordinator::render() {
    system_manager.render();
}


#endif //MOWERENGINE_COORDINATOR_H
