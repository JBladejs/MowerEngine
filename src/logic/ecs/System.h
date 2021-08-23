//
// Created by goon on 15.07.2021.
//

#ifndef MOWERENGINE_SYSTEM_H
#define MOWERENGINE_SYSTEM_H


#include <vector>

class System {
public:
    virtual void update() = 0;
    virtual void render() = 0;
};


#endif //MOWERENGINE_SYSTEM_H
