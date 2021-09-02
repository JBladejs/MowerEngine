//
// Created by goon on 15.07.2021.
//
#ifndef MOWERENGINE_ENTITY_H
#define MOWERENGINE_ENTITY_H

#include <cstdint>
#include "ECSTypes.h"
#include "../../util/ExtendingBitset.h"

class EntityManager;

class Entity {
private:
    uint32_t id;
    ExtendingBitset bits;

    explicit Entity(uint32_t id): id(id) {}
public:
    friend class EntityManager;
    Entity(Entity const&) = delete;
    void operator=(Entity const&) = delete;

    uint32_t getID() const;
    ExtendingBitset getSignature() const;

    template<typename C>
    void addComponent(C component);
    template<typename C>
    void removeComponent();
    template<typename C>
    bool hasComponent();
    template<typename C>
    C getComponent();

    ~Entity() = default;
private:
    bool hasComponent(int componentType);
};

#include "EntityManager.h"
#include "Coordinator.h"
#include <typeinfo>

inline uint32_t Entity::getID() const {
    return id;
}

template<typename C>
inline void Entity::addComponent(C component) {
    Coordinator::getInstance().addComponent<C>(component);
}

template<typename C>
inline void Entity::removeComponent() {
    Coordinator::getInstance().removeComponent<C>(id);
}

template<typename C>
inline bool Entity::hasComponent() {
    return hasComponent(Coordinator::getInstance().getComponentType<C>());
}

template<typename C>
inline C Entity::getComponent() {
    return Coordinator::getInstance().getComponent<C>(id);
}

inline bool Entity::hasComponent(int componentType) {
    return bits.get(componentType);
}

inline ExtendingBitset Entity::getSignature() const {
    return bits;
}

#endif //MOWERENGINE_ENTITY_H
