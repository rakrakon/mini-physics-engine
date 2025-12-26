//
// Created by rakra on 12/26/2025.
//

#ifndef MINI_PHYSICS_ENGINE_VECTOR2_H
#define MINI_PHYSICS_ENGINE_VECTOR2_H
#include <cmath>
#include <iosfwd>

#include "Point2.h"
#include "Rotation2.h"

namespace miniPhysicsEngine::math {
    struct Vector2 {
        double x;
        double y;
        double angleRadians;
        double magnitude;

        explicit Vector2(const double x = 0, const double y = 0) : x(x), y(y), angleRadians(atan2(y, x)),
                                                                   magnitude(sqrt(x * x + y * y)) {
        }

        explicit Vector2(const double magnitude, const Rotation2 angle) : x(magnitude * cos(angle.radians)),
                                                                          y(magnitude * sin(angle.radians)),
                                                                          angleRadians(angle.radians),
                                                                          magnitude(magnitude) {
        }

        [[nodiscard]] Vector2 inverse() const;

        [[nodiscard]] Point2 asPoint() const;

        Vector2 operator+(const Vector2 &other) const;

        Vector2 operator-(const Vector2 &other) const;

        Vector2 operator*(double scalar) const;

        friend std::ostream &operator<<(std::ostream &os, const Vector2 &vector2);
    };
}

#endif //MINI_PHYSICS_ENGINE_VECTOR2_H
