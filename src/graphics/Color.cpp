//
// Created by goon on 7/7/21.
//

#include "Color.h"

Color::Color(uint32_t colorHex) {
    r = (float) ((colorHex & 0xFF0000) >> 16) * 0.003921568f;
    g = (float) ((colorHex & 0x00FF00) >> 8) * 0.003921568f;
    b = (float) (colorHex & 0x0000FF) * 0.003921568f;
}
