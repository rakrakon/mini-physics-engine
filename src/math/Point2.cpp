//
// Created by rakra on 12/26/2025.
//

#include "mini_physics_engine/math/Point2.h"

#include <complex>

#include "mini_physics_engine/math/Vector2.h"

namespace miniPhysicsEngine::math {
    Point2 Point2::operator+(const Point2 &other) const {
        return Point2{x + other.x, y + other.y};
    }

    Point2 Point2::operator+(const Vector2 &other) const {
        return Point2{x + other.x, y + other.y};
    }

    Vector2 Point2::operator-(const Point2 &other) const {
        return Vector2{x - other.x, y - other.y};
    }

    std::ostream &operator<<(std::ostream &os, const Point2 &point2) {
        os << "Point2(x=" << point2.x << ", y=" << point2.y << ")";
        return os;
    }
} // math
