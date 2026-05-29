//
// Created by rakra on 12/26/2025.
//

#ifndef MINI_PHYSICS_ENGINE_POINT2_H
#define MINI_PHYSICS_ENGINE_POINT2_H
#include <iosfwd>

#include "Vector2.h"

namespace miniPhysicsEngine::math {
    struct Point2 {
        double x;
        double y;

        explicit Point2(const double x = 0, const double y = 0) : x(x), y(y) {
        }

        Point2 operator+(const Point2 &other) const;

        Point2 operator+(const Vector2 &other) const;

        Vector2 operator-(const Point2 &other) const;

        [[nodiscard]] bool isNear(const Point2 &other, double tolerance) const;

        friend std::ostream &operator<<(std::ostream &os, const Point2 &point2);
    };
} // math

#endif //MINI_PHYSICS_ENGINE_POINT2_H
