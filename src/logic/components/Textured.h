//
// Created by JJBla on 9/4/2021.
//

#ifndef MOWERENGINE_TEXTURED_H
#define MOWERENGINE_TEXTURED_H

#include "../../graphics/texturing/Image.h"

enum ScalingType {
    NONE, FRACTIONAL, CONSTANT
};

//TODO: remove Image classes and store all information here
//TODO: make sure the system destroys the texture properly
struct Textured {
    Image* texture;
    ScalingType scalingType;
    float scalingA;
    float scalingB;
};

#endif //MOWERENGINE_TEXTURED_H
