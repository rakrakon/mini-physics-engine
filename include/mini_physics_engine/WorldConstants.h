//
// Created by rakra on 12/26/2025.
//

#ifndef MINI_PHYSICS_ENGINE_WORLDCONSTANTS_H
#define MINI_PHYSICS_ENGINE_WORLDCONSTANTS_H
#include "math/Vector2.h"
#include "math/Rotation2.h"

namespace miniPhysicsEngine {
    const math::Vector2 GRAVITY_FORCE{9.8, math::Rotation2::negativeQuarterTurn()}; // (N)
}

#endif //MINI_PHYSICS_ENGINE_WORLDCONSTANTS_H
