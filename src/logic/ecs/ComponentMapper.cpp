//
// Created by goon on 18.08.2021.
//

#include "ComponentMapper.h"

void ComponentMapper::start() {
    index = 1;
    componentMap = std::unordered_map<unsigned long, int>();
}

int ComponentMapper::getComponentID(const std::type_info &componentClass) {
    auto hash = componentClass.hash_code();
    int value = componentMap[hash];
    if (value == 0) {
        componentMap[hash] = index;
        value = index++;
    }
    return value - 1;
}
