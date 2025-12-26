//
// Created by rakra on 12/26/2025.
//

#ifndef MINI_PHYSICS_ENGINE_PARTICLE_H
#define MINI_PHYSICS_ENGINE_PARTICLE_H
#include "mini_physics_engine/math/Vector2.h"
#include "mini_physics_engine/math/Point2.h"

namespace miniPhysicsEngine::physics {
    // MKS - Meters, Kilograms, Seconds
    struct Particle {
        math::Point2 position; // m
        math::Vector2 velocity; // m/s
        math::Vector2 acceleration; // m/s^2
        math::Vector2 totalForce; // (N)
        double mass; // kg

        explicit Particle(const double massKg, const math::Point2 position = math::Point2{},
                          const math::Vector2 velocity = math::Vector2{},
                          const math::Vector2 acceleration = math::Vector2{},
                          const math::Vector2 totalForce = math::Vector2{}) : position(position), velocity(velocity),
                                                                              acceleration(acceleration),
                                                                              totalForce(totalForce), mass(massKg) {
        }

        void step(double deltaTime); //Seconds

        void applyForce(math::Vector2 force);

        void clearForces();
    };
}


#endif //MINI_PHYSICS_ENGINE_PARTICLE_H
