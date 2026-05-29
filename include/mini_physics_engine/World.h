//
// Created by rakra on 5/28/2026.
//

#ifndef MINI_PHYSICS_ENGINE_WORLD_H
#define MINI_PHYSICS_ENGINE_WORLD_H

#include "physics/Particle.h"
#include <vector>

namespace physics = miniPhysicsEngine::physics;
namespace math = miniPhysicsEngine::math;

namespace miniPhysicsEngine {
    class World {
    private:
        void applyCollisionForces(const physics::Particle& particleA, const physics::Particle& particleB);

    public:
        std::vector<physics::Particle> particles = {};

        void addParticle(const physics::Particle &particle);

        void clearAllParticles();

        void step(double deltaTime);


    };
}

#endif //MINI_PHYSICS_ENGINE_WORLD_H