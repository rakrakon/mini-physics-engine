//
// Created by rakra on 12/27/2025.
//

#ifndef MINI_PHYSICS_ENGINE_ROTATION2_H
#define MINI_PHYSICS_ENGINE_ROTATION2_H
#include <complex>

namespace miniPhysicsEngine::math {
    struct Rotation2 {
        double radians;

        explicit Rotation2(const double angleRads = 0) : radians(angleRads) {
        }

        static Rotation2 fromVector(const double x, const double y) {
            return Rotation2(std::atan2(y, x));
        }

        static Rotation2 fromDegrees(const double degrees) {
            return Rotation2(degrees * M_PI / 180.0);
        }

        static Rotation2 zero() {
            return Rotation2{};
        }

        static Rotation2 quarterTurn() {
            return Rotation2{M_PI / 2};
        }

        static Rotation2 halfTurn() {
            return Rotation2{M_PI};
        }

        static Rotation2 negativeQuarterTurn() {
            return Rotation2{-M_PI / 2};
        }

        [[nodiscard]] double toDegrees() const {
            return radians * 180.0 / M_PI;
        }
    };
}

#endif //MINI_PHYSICS_ENGINE_ROTATION2_H
