//
// Created by rakra on 5/29/2026.
//

#include "gtest/gtest.h"
#include "mini_physics_engine/World.h"

namespace math = miniPhysicsEngine::math;
namespace physics = miniPhysicsEngine::physics;

class CollisionsTest: public testing::Test {
protected:
    miniPhysicsEngine::World world = miniPhysicsEngine::World();

    void SetUp() override {
        world.clearAllParticles();
    }

    void setupAndCollide(const physics::Particle &p1, const physics::Particle &p2) {
        world.addParticle(p1);
        world.addParticle(p2);

        // If we put 1.0 here the particles will step onto the exact same location thus impossible.
        world.step(0.999);
        world.step(1.0);
    }
};

TEST_F(CollisionsTest, OneDimensionalSameMass) {
    const auto p1 = physics::Particle(1, math::Point2(0, 1), math::Vector2(0, -1));
    const auto p2 = physics::Particle(1, math::Point2(0, -1), math::Vector2(0, 1));

    setupAndCollide(p1, p2);

    EXPECT_NEAR(world.particles[0].velocity.y, 1.0, 0.001);
    EXPECT_NEAR(world.particles[1].velocity.y, -1.0, 0.001);
}

TEST_F(CollisionsTest, OneDimensionalDifferentMass) {
    const auto p1 = physics::Particle(1, math::Point2(0, 1), math::Vector2(0, -1));
    const auto p2 = physics::Particle(2, math::Point2(0, -1), math::Vector2(0, 1));

    setupAndCollide(p1, p2);

    EXPECT_NEAR(world.particles[0].velocity.y, 1.666666, 0.001);
    EXPECT_NEAR(world.particles[1].velocity.y, -0.33333, 0.001);
}

TEST_F(CollisionsTest, OneDimensionalDifferentMassDifferentVelocity) {
    const auto p1 = physics::Particle(1, math::Point2(0, 1), math::Vector2(0, -1));
    const auto p2 = physics::Particle(2, math::Point2(0, -1), math::Vector2(0, 2));

    setupAndCollide(p1, p2);

    EXPECT_NEAR(world.particles[0].velocity.y, 3, 0.001);
    EXPECT_NEAR(world.particles[1].velocity.y, 0, 0.001);
}