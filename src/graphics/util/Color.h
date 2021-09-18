//
// Created by Alan Ćwiek on 7/7/21.
//

#ifndef MOWERENGINE_COLOR_H
#define MOWERENGINE_COLOR_H


#include <cstdint>

struct Color {
    float fR;
    float fB;
    float fG;
    uint8_t iR;
    uint8_t iB;
    uint8_t iG;
    explicit Color(uint32_t colorHex);
};


#endif //MOWERENGINE_COLOR_H
