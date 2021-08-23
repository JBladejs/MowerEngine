//
// Created by goon on 15.07.2021.
//

#ifndef MOWERENGINE_ENTITY_H
#define MOWERENGINE_ENTITY_H

#include <cstdint>
#include <string>
#include <typeinfo>
#include "Component.h"
#include "../../util/Bag.h"
#include "../../util/ExtendingBitset.h"

class Entity {
private:
    Bag<Component> components;
    uint64_t id;
    std::string tag;
    ExtendingBitset bits;

    //TODO: change to transform
    int x;
    int y;

public:
    Entity();
    ~Entity();
    void add(Component component);
    void remove(Component component);
    void removeAll();
    //TODO: add this:
    //bool hasComponent(ComponentType componentType);
    bool hasComponent(int componentID);
    template<typename C> C getComponent();
private:
    Component getComponent(const std::type_info& componentClass);
    Component getComponent(int componentID);

public:
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
};

#endif //MOWERENGINE_ENTITY_H
