//
// Created by rakra on 5/28/2026.
//

#include "mini_physics_engine/World.h"

namespace miniPhysicsEngine {
    void World::addParticle(const physics::Particle &particle) {
        particles.push_back(particle);
    }

    void World::clearAllParticles() {
        particles.clear();
    }

    void World::step(const double deltaTime) {
        // Collisions
        for (int i = 0; i < particles.size(); i++) {
            for (int j = i + 1; j < particles.size(); j++) {
                if (particles[i].position.isNear(particles[j].position, 1)) {
                    applyCollisionForces(particles[i], particles[j]);
                }
            }
        }

        for (auto& particle : particles) {
            particle.step(deltaTime);
        }
    }

    void World::applyCollisionForces(const physics::Particle &particleA, const physics::Particle &particleB) {
        const double massA = particleA.mass;
        const double massB = particleB.mass;

        const auto velocityA = particleA.velocity;
        const auto velocityB = particleB.velocity;

        const math::Vector2 collisionNormal = (particleA.position - particleB.position) * (1.0 / (particleA.position - particleB.position).magnitude);

        const double velocityANormal = velocityA * collisionNormal;
        const double velocityBNormal = velocityB * collisionNormal;

        const double newVelocityANormal = (velocityANormal * (massA - massB) + 2 * massB * velocityBNormal) / (massA + massB);
        const double newVelocityBNormal = (velocityBNormal * (massB - massA) + 2 * massA * velocityANormal) / (massA + massB);

        const math::Vector2 newVelocityA = velocityA + collisionNormal * (newVelocityANormal - velocityANormal);
        const math::Vector2 newVelocityB = velocityB + collisionNormal * (newVelocityBNormal - velocityBNormal);

        particleA.velocity = newVelocityA;
        particleB.velocity = newVelocityB;
    }
}
