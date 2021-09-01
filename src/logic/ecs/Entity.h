//
// Created by goon on 15.07.2021.
//
#ifndef MOWERENGINE_ENTITY_H
#define MOWERENGINE_ENTITY_H

#include <cstdint>
#include <string>
#include <typeinfo>
#include "ECSTypes.h"
#include "../../util/Bag.h"
#include "../../util/ExtendingBitset.h"
#include "EntityManager.h"
#include "Coordinator.h"

class Entity {
private:
    uint32_t id;
    ExtendingBitset bits;

    explicit Entity(uint32_t id): id(id) {}
public:
    friend Entity& EntityManager::createEntity();
    uint32_t getID() const;
    Entity(Entity const&) = delete;
    void operator=(Entity const&) = delete;
    template<typename C>
    void addComponent(C component);
    template<typename C>
    void removeComponent();
    template<typename C>
    bool hasComponent();
    ~Entity() = default;
    template<typename C>
    C getComponent();
private:
    bool hasComponent(int componentType);
};

uint32_t Entity::getID() const {
    return id;
}

template<typename C>
void Entity::addComponent(C component) {
    Coordinator::getInstance().addComponent<C>(component);
}

template<typename C>
void Entity::removeComponent() {
    Coordinator::getInstance().removeComponent<C>(id);
}

template<typename C>
bool Entity::hasComponent() {
    return hasComponent(Coordinator::getInstance().getComponentType<C>());
}

template<typename C>
C Entity::getComponent() {
    return Coordinator::getInstance().getComponent<C>(id);
}

bool Entity::hasComponent(int componentType) {
    return bits.get(componentType);
}

#endif //MOWERENGINE_ENTITY_H
