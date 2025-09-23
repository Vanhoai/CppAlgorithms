cmake_minimum_required(VERSION 4.0)
project(CppAlgorithms
        LANGUAGES CXX
        VERSION 1.0.0
        DESCRIPTION "Set of algorithms implemented in C++."
)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define library aliases as variables
# set(CORE_LIBRARY "CppAlgorithms:core")

# Add cmake modules path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Options
option(BUILD_TESTS "Build Testing Feature" ON)
option(BUILD_BENCHMARKS "Build Benchmarks Feature" OFF)

if (BUILD_TESTS)
    enable_testing()
    message(STATUS "Testing Feature are enabled.")
else ()
    message(STATUS "Testing Feature are disabled.")
endif ()

if (BUILD_BENCHMARKS)
    message(STATUS "Benchmarks are enabled.")
else ()
    message(STATUS "Benchmarks are disabled.")
endif ()

# Include custom cmake files
include(cmake/Dependencies.cmake)
include(cmake/CompilerFlags.cmake)

# Add subdirectories
add_subdirectory(libraries)
add_subdirectory(theory)
add_subdirectory(leetcode)

# add_subdirectory(graph)
# add_subdirectory(discrete_mathematics)
# add_subdirectory(design-patterns)

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)

# Installation
include(GNUInstallDirs)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
