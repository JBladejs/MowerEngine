//
// Created by Alan Ćwiek on 7/7/21.
//

#include "Color.h"

//TODO: make getting this values lazy
Color::Color(uint32_t colorHex) {
    iR = (colorHex & 0xFF0000) >> 16;
    fR = (float) iR * 0.003921568f;
    iB = (colorHex & 0x00FF00) >> 8;
    fB = (float) iB * 0.003921568f;
    iG = colorHex & 0x0000FF;
    fG = (float) iG * 0.003921568f;
}
