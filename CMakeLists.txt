cmake_minimum_required(VERSION 4.1)
project(mini_physics_engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(mini_physics_engine
        src/main.cpp
        src/math/Point2.cpp
        include/mini_physics_engine/math/Point2.h
        include/mini_physics_engine/physics/Particle.h
        include/mini_physics_engine/math/Vector2.h
        src/math/Vector2.cpp
        include/mini_physics_engine/WorldConstants.h
        src/physics/Particle.cpp
        include/mini_physics_engine/math/Rotation2.h
)
