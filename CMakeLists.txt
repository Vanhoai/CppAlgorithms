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

# Include custom cmake files
include(cmake/Dependencies.cmake)
include(cmake/CompilerFlags.cmake)

# CMake options for the project
option(USE_OPENMP "Use OpenMP for multithreading" ON)
option(BUILD_TESTING "Build Testing Features" ON)

if (BUILD_TESTING)
    enable_testing()
endif ()

# Add subdirectories
add_subdirectory(libraries)
add_subdirectory(theory)
add_subdirectory(leetcode)

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)

# Installation
include(GNUInstallDirs)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Information
message(STATUS "+---------------------- CPP ALGORITHMS ----------------------+")
message(STATUS "| Version: 1.0.0                                             |")
message(STATUS "| CMake Version: ${CMAKE_VERSION}                                       |")
message(STATUS "| C++ Standard: C++17                                        |")
message(STATUS "| Build Type: Release                                        |")
if (USE_OPENMP)
    message(STATUS "| OpenMP: Enabled                                            |")
else ()
    message(STATUS "| OpenMP: Disabled                                           |")
endif ()
if (BUILD_TESTING)
    message(STATUS "| Testing: Enabled                                           |")
else ()
    message(STATUS "| Testing: Disabled                                          |")
endif ()
message(STATUS "+------------------------------------------------------------+")
