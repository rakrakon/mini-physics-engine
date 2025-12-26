//
// Created by rakra on 12/26/2025.
//

#include "mini_physics_engine/physics/Particle.h"

namespace miniPhysicsEngine::physics {
    void Particle::step(const double deltaTime) {
        acceleration = totalForce * (1 / mass);
        velocity = velocity + acceleration * deltaTime;
        position = position + (velocity * deltaTime).asPoint();
    }

    // Should usually call step method after this call
    void Particle::applyForce(const math::Vector2 force) {
        totalForce = totalForce + force;
    }

    void Particle::clearForces() {
        totalForce = math::Vector2{};
    }
}
