//
// Created by goon on 7/7/21.
//

#include "Color.h"

Color::Color(uint16_t colorHex) {
    r = (float) (colorHex & 0xFF0000) / 255.f;
    g = (float) (colorHex & 0x00FF00) / 255.f;
    b = (float) (colorHex & 0x0000FF) / 255.f;
}
