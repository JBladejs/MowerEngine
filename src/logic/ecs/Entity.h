//
// Created by Alan Ćwiek on 15.07.2021.
//
#ifndef MOWERENGINE_ENTITY_H
#define MOWERENGINE_ENTITY_H

#include "ECSTypes.h"
#include "../../util/ExtendingBitset.h"

class Entity {
public:
    uint32_t getID() const;
    ExtendingBitset& getSignature();

    template<typename C>
    void addComponent(C component);
    template<typename C>
    void removeComponent();
    template<typename C>
    bool hasComponent() const;
    template<typename C>
    C& getComponent();

    ~Entity() = default;

    friend class EntityManager;
    Entity(Entity const&) = delete;
    void operator=(Entity const&) = delete;
private:
    uint32_t id;
    ExtendingBitset* bits;

    explicit Entity(uint32_t id): id(id), bits(new ExtendingBitset()) {}
    bool has_component(int componentType) const;
};

#include "Coordinator.h"

inline uint32_t Entity::getID() const {
    return id;
}

template<typename C>
inline void Entity::addComponent(C component) {
    Coordinator::getInstance().addComponent<C>(id, component);
}

template<typename C>
inline void Entity::removeComponent() {
    Coordinator::getInstance().removeComponent<C>(id);
}

template<typename C>
inline bool Entity::hasComponent() const{
    return has_component(Coordinator::getInstance().getComponentType<C>());
}

template<typename C>
inline C& Entity::getComponent() {
    return Coordinator::getInstance().getComponent<C>(id);
}

inline bool Entity::has_component(int componentType) const {
    return bits->get(componentType);
}

inline ExtendingBitset& Entity::getSignature() {
    return *bits;
}

#endif //MOWERENGINE_ENTITY_H
