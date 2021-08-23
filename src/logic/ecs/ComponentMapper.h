//
// Created by goon on 18.08.2021.
//

#ifndef MOWERENGINE_COMPONENTMAPPER_H
#define MOWERENGINE_COMPONENTMAPPER_H

#include <unordered_map>
#include <typeinfo>

class ComponentMapper {
private:
    static int index;
    static std::unordered_map<unsigned long, int> componentMap;
public:
    static void start();
    static int getComponentID(const std::type_info& componentClass);
private:
    ComponentMapper() = default;
};


#endif //MOWERENGINE_COMPONENTMAPPER_H
