//
// Created by goon on 15.07.2021.
//

#ifndef MOWERENGINE_ENTITY_H
#define MOWERENGINE_ENTITY_H


#include <cstdint>
#include "Component.h"

class Entity {
private:
    uint64_t id;
public:
    Entity();
    ~Entity();
    void add(Component component);
    void remove(Component component);

};


#endif //MOWERENGINE_ENTITY_H
