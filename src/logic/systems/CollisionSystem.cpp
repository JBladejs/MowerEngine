//
// Created by JJBla on 9/8/2021.
//

#include "CollisionSystem.h"
#include "../components/Collision.h"

void CollisionSystem::initialize() {
    auto& coordinator = Coordinator::getInstance();
    coordinator.registerSystem<CollisionSystem>();

    coordinator.registerComponent<CircleCollider>();
    coordinator.registerComponent<BoxCollider>();
    coordinator.registerSystem<Collision>();

    coordinator.observeComponentType<CollisionSystem>(coordinator.getComponentType<Position>());
}

//TODO: make it less chaotic

//TODO: implement sort and sweep
//TODO: remove double "hasComponent" checks
void CollisionSystem::update() {
    auto& coordinator = Coordinator::getInstance();
    std::set<EntityID>::iterator it;
    std::set<EntityID>::iterator other;

    for (it = entities.begin(); it != entities.end(); it++) {
        auto& entity1 = coordinator.getEntity(*it);
        if (!entity1.hasComponent<CircleCollider>() && !entity1.hasComponent<BoxCollider>()) continue;

        for ((other = it)++; other != entities.end(); other++) {
            auto& entity2 = coordinator.getEntity(*other);
            if (!entity2.hasComponent<CircleCollider>() && !entity2.hasComponent<BoxCollider>()) continue;

            if (are_colliding(entity1, entity2)) {
                entity1.addComponent<Collision>({&entity2});
                entity2.addComponent<Collision>({&entity1});
            }
        }
    }
}

bool CollisionSystem::are_boxes_colliding(BoxCollider colliderA, BoxCollider colliderB) {
    float dx = std::abs(colliderA.x - colliderB.x);
    float dy = std::abs(colliderA.y - colliderB.y);
    return dx <= (colliderA.w + colliderB.w) * .5f && dy < (colliderA.h + colliderB.h);
}

bool CollisionSystem::are_circles_colliding(CircleCollider colliderA, CircleCollider colliderB) {
    float dx = colliderA.x - colliderB.x;
    float dy = colliderA.y - colliderB.y;

    float a = colliderA.r + colliderB.r;

    if (dx > a) return false;
    if (dy > a) return false;

    return dx * dx + dy * dy <= a * a;
}

bool CollisionSystem::are_circle_and_box_colliding(CircleCollider colliderA, BoxCollider colliderB) {
    float distance_x = std::abs(colliderA.x - colliderB.x);
    float distance_y = std::abs(colliderA.y - colliderB.y);

    if (distance_x > (colliderB.w * .5f + colliderA.r)) return false;
    if (distance_y > (colliderB.h * .5f + colliderA.r)) return false;

    if (distance_x <= colliderB.w * .5f) return true;
    if (distance_y <= colliderB.h * .5f) return true;

    float dx = distance_x - colliderB.w * .5f;
    float dy = distance_y - colliderB.h * .5f;

    return dx * dx + dy * dy <= colliderA.r * colliderA.r;
}

bool CollisionSystem::are_colliding(Entity &entityA, Entity &entityB) {
    if (entityA.hasComponent<CircleCollider>())
        if (entityB.hasComponent<CircleCollider>()) {
            auto circle1 = get_absolute(entityA.getComponent<CircleCollider>(), entityA.getComponent<Position>());
            auto circle2 = get_absolute(entityB.getComponent<CircleCollider>(), entityB.getComponent<Position>());

            return are_circles_colliding(circle1, circle2);
        } else {
            auto circle = get_absolute(entityA.getComponent<CircleCollider>(), entityA.getComponent<Position>());
            auto box = get_absolute(entityB.getComponent<BoxCollider>(), entityB.getComponent<Position>());

            return are_circle_and_box_colliding(circle, box);
        }
    else
    if (entityB.hasComponent<CircleCollider>()) {
        auto circle = get_absolute(entityB.getComponent<CircleCollider>(), entityB.getComponent<Position>());
        auto box = get_absolute(entityA.getComponent<BoxCollider>(), entityA.getComponent<Position>());

        return are_circle_and_box_colliding(circle, box);
    } else {
        auto box1 = get_absolute(entityA.getComponent<BoxCollider>(), entityA.getComponent<Position>());
        auto box2 = get_absolute(entityB.getComponent<BoxCollider>(), entityB.getComponent<Position>());

        return are_boxes_colliding(box1, box2);
    }
}

void CollisionSystem::render() { }

BoxCollider CollisionSystem::get_absolute(const BoxCollider &collider, const Position &position) {
    return BoxCollider
    {
        collider.x + position.x,
        collider.y + position.y,
        collider.w,
        collider.h
    };
}


CircleCollider CollisionSystem::get_absolute(const CircleCollider &collider, const Position &position) {
    return CircleCollider
    {
        collider.x + position.x,
        collider.y + position.y,
        collider.r
    };
}