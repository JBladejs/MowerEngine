//
// Created by JJBla on 9/14/2021.
//

#include "LuaBindings.h"
#include "../../logic/components/Textured.h"
#include "../../graphics/texturing/Sprite.h"

void LuaTextured::bind(sol::state &lua) {
    lua.new_enum("ScalingType",
                 "NONE", NONE,
                 "FRACTIONAL", FRACTIONAL,
                 "CONSTANT", CONSTANT);

    lua.new_usertype<Textured>("Textured",
                               sol::call_constructor,
                               sol::factories([]() {
                                   return Textured { new Sprite("assets/crate.jpg") };
                               }),
                               "texture", &Textured::texture,
                               "scalingType", &Textured::scalingType,
                               "scalingA", &Textured::scalingA,
                               "scalingB", &Textured::scalingB);
}
