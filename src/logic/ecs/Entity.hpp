//
// Created by goon on 15.07.2021.
//
#pragma once
#ifndef MOWERENGINE_ENTITY_HPP
#define MOWERENGINE_ENTITY_HPP

#include <cstdint>
#include <string>
#include <typeinfo>
#include "ECSTypes.h"
#include "../../util/Bag.h"
#include "../../util/ExtendingBitset.h"
#include "EntityManager.h"

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


    ~Entity() = default;

//    template<typename C>
//    bool addComponent(C component);
//
//    void remove(Component component);
//    void removeAll();
//    //TODO: add this:
//    //bool hasComponent(ComponentType componentType);
//    bool hasComponent(int componentID);
//    template<typename C> C getComponent();
//private:
//    Component getComponent(const std::type_info& componentClass);
//    Component getComponent(int componentID);
};

#endif //MOWERENGINE_ENTITY_HPP
