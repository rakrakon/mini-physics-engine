cmake_minimum_required(VERSION 4.1)
project(mini_physics_engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

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

target_link_libraries(mini_physics_engine PRIVATE SDL3::SDL3)