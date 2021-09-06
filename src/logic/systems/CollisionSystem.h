//
// Created by JJBla on 9/6/2021.
//

#ifndef MOWERENGINE_COLLISIONSYSTEM_H
#define MOWERENGINE_COLLISIONSYSTEM_H

#include <cmath>
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
        float it_x = it_position.x + it_collider.x;
        float it_y = it_position.y + it_collider.y;
        float it_r = it_collider.r;
        for ((other = it)++; other != entities.end(); other++) {
            auto& other_position = coordinator.getComponent<Position>(*other);
            auto& other_collider = coordinator.getComponent<Collider>(*other);
            float other_x = other_position.x + other_collider.x;
            float other_y = other_position.y + other_collider.y;
            float other_r = other_collider.r;

//            sqrt((collider.x - x).pow(2) + (collider.y - y).pow(2)) < radius + collider.radius

            if (std::sqrt( powf(it_x - other_x, 2.f) + powf(it_y - other_y, 2.f)) < it_r + other_r )
                std::cout << "collsion!" << std::endl;
        }
    }
}

void CollisionSystem::render() {}


#endif //MOWERENGINE_COLLISIONSYSTEM_H
