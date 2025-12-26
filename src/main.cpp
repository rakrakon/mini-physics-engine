#include <iostream>

#include "mini_physics_engine/WorldConstants.h"
#include "mini_physics_engine/math/Point2.h"
#include "mini_physics_engine/physics/Particle.h"

int main() {
    namespace math = miniPhysicsEngine::math;
    namespace physics = miniPhysicsEngine::physics;

    physics::Particle testParticle{10};

    testParticle.applyForce(math::Vector2{0,-miniPhysicsEngine::GRAVITY_FORCE});

    for (int i = 0; i < 5; i++) {
        testParticle.step(1);

        std::cout << "Position: " << testParticle.position << "\n";
        std::cout << "Velocity: " << testParticle.velocity << "\n";
        std::cout << "Acceleration: " << testParticle.acceleration << "\n";
    }

    return 0;
}
