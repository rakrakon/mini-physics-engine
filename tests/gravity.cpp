#include <gtest/gtest.h>
#include <mini_physics_engine/physics/Particle.h>
#include <mini_physics_engine/WorldConstants.h>

namespace physics = miniPhysicsEngine::physics;
namespace math = miniPhysicsEngine::math;

class GravityTest : public testing::Test {
protected:
    physics::Particle particle = physics::Particle{1};

    void SetUp() override {
        particle.applyForce(miniPhysicsEngine::GRAVITY_FORCE);
        particle.step(1.0);
    }
};

TEST_F(GravityTest, Acceleration) {
    EXPECT_NEAR(-9.8, particle.acceleration.y, 0.0001);
}

TEST_F(GravityTest, Velocity) {
    EXPECT_NEAR(-9.8, particle.velocity.y, 0.0001);
}

TEST_F(GravityTest, Position) {
    EXPECT_NEAR(-4.9, particle.position.y, 0.0001);
}
