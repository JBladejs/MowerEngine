//
// Created by goon on 15.07.2021.
//
#ifndef MOWERENGINE_ENTITY_HPP
#define MOWERENGINE_ENTITY_HPP

#include <cstdint>
#include <string>
#include <typeinfo>
#include "ECSTypes.h"
#include "../../util/Bag.h"
#include "../../util/ExtendingBitset.h"
#include "EntityManager.h"
#include "Coordinator.hpp"

class Entity {
private:
    uint32_t id;
    ExtendingBitset bits;

    explicit Entity(uint32_t id): id(id) {}
public:
    friend Entity& EntityManager::createEntity();
    uint32_t getID() const {
        return id;
    }
    Entity(Entity const&) = delete;
    void operator=(Entity const&) = delete;

    template<typename C>
    void addComponent(C component) {
        Coordinator::getInstance().addComponent<C>(component);
    }

    template<typename C>
    void removeComponent() {
        Coordinator::getInstance().removeComponent<C>(id);
    }

    template<typename C>
    bool hasComponent() {
        return hasComponent(Coordinator::getInstance().getComponentType<C>());
    }

    ~Entity() = default;

    template<typename C>
    C getComponent() {
        return Coordinator::getInstance().getComponent<C>(id);
    }

private:
    bool hasComponent(int componentType) {
        return bits.get(componentType);
    }
};

#endif //MOWERENGINE_ENTITY_HPP
