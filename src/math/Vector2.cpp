//
// Created by rakra on 12/26/2025.
//

#include "mini_physics_engine/math/Vector2.h"

#include <complex>

namespace miniPhysicsEngine::math {
    Vector2 Vector2::inverse() const {
        return Vector2{-x, -y};
    }

    Point2 Vector2::asPoint() const {
        return Point2(x, y);
    }

    Vector2 Vector2::operator+(const Vector2 &other) const {
        return Vector2{x + other.x, y + other.y};
    }

    Vector2 Vector2::operator-(const Vector2 &other) const {
        return Vector2{x - other.x, y - other.y};
    }

    Vector2 Vector2::operator*(const double scalar) const {
        return Vector2{x * scalar, y * scalar};
    }

    std::ostream &operator<<(std::ostream &os, const Vector2 &vector2) {
        os << "Vector2(x=" << vector2.x << ", y=" << vector2.y << ")";
        return os;
    }
}
