//
// Created by goon on 15.07.2021.
//

#include "Entity.h"
#include <typeinfo>
#include "ComponentMapper.h"

//TODO: add signals

Entity::Entity() {
    components = Bag<Component>();
}

//TODO: pass here a component and not a pointer to it
void Entity::add(Component component) {
    int componentID = ComponentMapper::getComponentID(typeid(&component));
    if (hasComponent(componentID)) {
        auto oldComponent = getComponent(componentID);
        remove(oldComponent);
    } else bits.set(componentID);

    components.add(component);
}

void Entity::remove(Component component) {
    int componentID = ComponentMapper::getComponentID(typeid(&component));
    components.removeElement(component);
    delete component;
    bits.unset(componentID);
}

void Entity::removeAll() {
    for (int i = 0; i < components.size(); i++)
        auto* component = components.get(i);
        components.remove(i);
        bits.clear();
    }
}

bool Entity::hasComponent(int componentID) {
    return bits.get(componentID);
}

Entity::~Entity() {
    components.clear();
}
