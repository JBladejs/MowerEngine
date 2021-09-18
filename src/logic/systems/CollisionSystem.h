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
    //TODO: make render and update only available to SystemManager
    void render() override;
    void update() override;
private:
    static CircleCollider get_absolute(const CircleCollider& collider, const Position& position);
    static BoxCollider get_absolute(const BoxCollider& collider, const Position& position);
    static bool are_boxes_colliding(BoxCollider colliderA, BoxCollider colliderB);
    static bool are_circles_colliding(CircleCollider colliderA, CircleCollider colliderB);
    static bool are_circle_and_box_colliding(CircleCollider colliderA, BoxCollider colliderB);
    static bool are_colliding(Entity &entityA, Entity &entityB);
};

#endif //MOWERENGINE_COLLISIONSYSTEM_H
