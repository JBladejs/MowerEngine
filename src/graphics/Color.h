//
// Created by goon on 7/7/21.
//

#ifndef MOWERENGINE_COLOR_H
#define MOWERENGINE_COLOR_H


#include <cstdint>

struct Color {
    float r;
    float b;
    float g;
    explicit Color(uint16_t colorHex);
};


#endif //MOWERENGINE_COLOR_H
