//
// Created by JJBla on 9/12/2021.
//

#include "ScriptManager.h"

void ScriptManager::init() {
    lua.open_libraries(sol::lib::base,
                       sol::lib::package,
                       sol::lib::math,
                       sol::lib::table);
    //TODO: bind classes here

}
