//
// Created by JJBla on 8/31/2021.
//

#ifndef MOWERENGINE_SYSTEMMANAGER_H
#define MOWERENGINE_SYSTEMMANAGER_H


#include <iostream>
#include "System.h"
#include "../../util/ExtendingBitset.h"

//TODO: check how Ashley handles it

class SystemManager {
private:
    std::unordered_map<const char*, System*> systems{};
    //TODO: test if those are destroyed
    std::unordered_map<const char*, ExtendingBitset*> bitsets{};
public:
    template<typename S>
    S& registerSystem() {
        //TODO: throw exception if system is already registered
        const char* type_name = typeid(S).name();
        //TODO: investigate a possibility of using a shared pointer hare
        systems[type_name] = new S();
        bitsets[type_name] = new ExtendingBitset();
        return *system;
    }

    template<typename S>
    void observeComponentType(ComponentType componentType) {
        //TODO: throw exception if system is not registered
        const char* type_name = typeid(S).name();
        auto &bitset = bitsets[type_name];
        bitset->set(componentType);
    }

    void entityDestroyed(EntityID entityID) {
        for (auto const& pair : systems)
        {
            auto const& system = pair.second;
            system->entities.remove(entityID);
        }
    }

    //TODO: add "entitySignatureChanges(EntityID entityID)"

    void update() {
        for (auto const& pair : systems) {
            auto const& system = pair.second;
            system->update();
        }
    }
    
    void render() {
        for (auto const& pair : systems) {
            auto const& system = pair.second;
            system->render();
        }
    }

    ~SystemManager() = default;
//Singleton:
private:
    SystemManager() = default;
public:
    static SystemManager& getInstance() {
        static SystemManager instance;
        return instance;
    }
    SystemManager(SystemManager const&) = delete;
    void operator=(SystemManager const&) = delete;
};


#endif //MOWERENGINE_SYSTEMMANAGER_H
