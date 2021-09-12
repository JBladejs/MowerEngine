//
// Created by JJBla on 9/12/2021.
//

#ifndef MOWERENGINE_SCRIPTMANAGER_H
#define MOWERENGINE_SCRIPTMANAGER_H


class ScriptManager {
public:


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
