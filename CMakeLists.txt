cmake_minimum_required(VERSION 4.1)
project(mini_physics_engine)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/googletest EXCLUDE_FROM_ALL)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE TEST_FILES tests/*.cpp)

add_executable(mini_physics_engine ${SRC_FILES}
        include/mini_physics_engine/World.h
        src/World.cpp
        src/World.h)
target_include_directories(mini_physics_engine PRIVATE include)
target_link_libraries(mini_physics_engine PRIVATE SDL3::SDL3)

# Exclude main.cpp from the tests executables
list(FILTER SRC_FILES EXCLUDE REGEX ".*main\\.cpp$")

add_executable(tests ${SRC_FILES} ${TEST_FILES})
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE gtest_main)