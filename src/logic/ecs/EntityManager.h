//
// Created by goon on 16.07.2021.
//

#ifndef MOWERENGINE_ENTITYMANAGER_H
#define MOWERENGINE_ENTITYMANAGER_H


#include <vector>
#include "Entity.h"

class EntityManager {
private:
    std::vector<Entity*> entites;
public:
    void add(Entity* entity);
    void remove(Entity* entity);
    void remove(int i);
    Entity* get(int i);
};


#endif //MOWERENGINE_ENTITYMANAGER_H
