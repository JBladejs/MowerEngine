//
// Created by JJBla on 8/31/2021.
//
#ifndef MOWERENGINE_SYSTEMMANAGER_H
#define MOWERENGINE_SYSTEMMANAGER_H

//TODO: check how Ashley handles it

#include <unordered_map>
#include "../../util/ExtendingBitset.h"
#include "System.h"

class SystemManager {
public:
    template<typename S>
    S& registerSystem();
    template<typename S>
    void observeComponentType(ComponentType componentType);
    void entityDestroyed(EntityID entityID);
    void entitySignatureChanged(EntityID entityID, const ExtendingBitset& signature);
    void update();
    void render();
    ~SystemManager() = default;

private:
    std::unordered_map<const char*, System*> systems{};
    std::unordered_map<const char*, ExtendingBitset> bitsets{};

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


template<typename S>
inline S& SystemManager::registerSystem() {
    //TODO: throw exception if system is already registered
    const char* type_name = typeid(S).name();
    //TODO: investigate a possibility of using a shared pointer hare
    System *system = new S();
    systems[type_name] = system;
    bitsets[type_name] = ExtendingBitset();
    return (S&) *system;
}

template<typename S>
inline void SystemManager::observeComponentType(ComponentType componentType) {
    //TODO: throw exception if system is not registered
    const char* type_name = typeid(S).name();
    auto &bitset = bitsets[type_name];
    bitset.set(componentType);
}

inline void SystemManager::entityDestroyed(EntityID entityID) {
    for (auto const& pair : systems)
    {
        auto const& system = pair.second;
        system->entities.erase(entityID);
    }
}

inline void SystemManager::entitySignatureChanged(EntityID entityID, const ExtendingBitset& signature) {
    for (auto const& pair : systems) {
        auto const& type = pair.first;
        auto const& system = pair.second;
        auto const& system_signature = bitsets[type];

        if ((system_signature & signature) == system_signature)
            system->entities.insert(entityID);
        else system->entities.erase(entityID);
    }
}

inline void SystemManager::update() {
    for (auto const& pair : systems) {
        auto const& system = pair.second;
        system->update();
    }
}

inline void SystemManager::render() {
    for (auto const& pair : systems) {
        auto const& system = pair.second;
        system->render();
    }
}


#endif //MOWERENGINE_SYSTEMMANAGER_H
