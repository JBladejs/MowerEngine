//
// Created by goon on 15.07.2021.
//

#ifndef MOWERENGINE_SYSTEM_H
#define MOWERENGINE_SYSTEM_H

#include <vector>
#include <cstdint>
#include <set>
#include "ECSTypes.h"
#include "../../util/Bag.h"

class System {
public:
    //TODO: implement signal to automatically update entities
    //TODO: change set to Bag
   std::set<EntityID> entities;
    virtual void update() {}
    virtual void render() {}
};


#endif //MOWERENGINE_SYSTEM_H
