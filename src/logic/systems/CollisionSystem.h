//
// Created by JJBla on 9/6/2021.
//

#ifndef MOWERENGINE_COLLISIONSYSTEM_H
#define MOWERENGINE_COLLISIONSYSTEM_H

#include "../ecs/System.h"
#include "../ecs/Coordinator.h"
#include "../components/Collider.h"
#include "../components/Position.h"

class CollisionSystem : public System {
public:
    //TODO: add initialize to base System class
    static void initialize();
    void render() override;
    void update() override;
};

void CollisionSystem::initialize() {
    auto& coordinator = Coordinator::getInstance();
    coordinator.registerSystem<CollisionSystem>();
    coordinator.registerComponent<Collider>();
    coordinator.observeComponentType<CollisionSystem>(coordinator.getComponentType<Collider>());
    coordinator.observeComponentType<CollisionSystem>(coordinator.getComponentType<Position>());
}

void CollisionSystem::update() {
    auto& coordinator = Coordinator::getInstance();
    std::set<EntityID>::iterator it;
    std::set<EntityID>::iterator other;
    for (it = entities.begin(); it != entities.end(); it++) {
        auto& it_position = coordinator.getComponent<Position>(*it);
        auto& it_collider = coordinator.getComponent<Collider>(*it);
        for ((other = it)++; other != entities.end(); other++) {
            auto& other_position = coordinator.getComponent<Position>(*other);
            auto& other_collider = coordinator.getComponent<Collider>(*other);

            if ( std::abs((it_position.x + it_collider.x) - (other_position.x + other_collider.x)) < it_collider.r + other_collider.r
            &&   std::abs((it_position.y + it_collider.y) - (other_position.y + other_collider.y)) < it_collider.r + other_collider.r)
                std::cout << "collsion!" << std::endl;
        }
    }
}

void CollisionSystem::render() {}


#endif //MOWERENGINE_COLLISIONSYSTEM_H
