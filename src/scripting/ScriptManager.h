//
// Created by JJBla on 9/12/2021.
//

#ifndef MOWERENGINE_SCRIPTMANAGER_H
#define MOWERENGINE_SCRIPTMANAGER_H


#include <sol/sol.hpp>

class ScriptManager {
public:
    //TODO: consider adding init and cleanup to SystemManager and System
    void init();
    void update();
    void render();
    void cleanup();
private:
    sol::state lua;
    sol::function fun_init;
    sol::function fun_update;
    sol::function fun_render;

//Singleton:
private:
    ScriptManager() = default;
public:
    static ScriptManager& getInstance() {
        static ScriptManager instance;
        return instance;
    }
    ScriptManager(ScriptManager const&) = delete;
    void operator=(ScriptManager const&) = delete;
};


#endif //MOWERENGINE_SCRIPTMANAGER_H
