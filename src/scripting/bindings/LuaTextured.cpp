//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/components/Textured.h"

void LuaTextured::bind(sol::state &lua) {
    lua.new_enum("ScalingType",
                 "NONE", NONE,
                 "FRACTIONAL", FRACTIONAL,
                 "CONSTANT", CONSTANT);

    lua.new_usertype<Textured>("Textured",
                               "texture", &Textured::texture,
                               "scalingType", &Textured::scalingType,
                               "scalingA", &Textured::scalingA,
                               "scalingB", &Textured::scalingB);
}
