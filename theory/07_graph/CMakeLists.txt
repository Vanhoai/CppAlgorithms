project(07_graph LANGUAGES CXX)

# Collect source files
file(GLOB_RECURSE GRAPH_HEADERS "include/07_graph/*.hpp")
file(GLOB_RECURSE GRAPH_SOURCES "src/*.cpp")

# Create graph library
add_library(${PROJECT_NAME} ${GRAPH_HEADERS} ${GRAPH_SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link dependencies
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        core
        PRIVATE
)

# Add tests subdirectory
if (BUILD_TESTING)
    add_subdirectory(tests)
    message(STATUS "Building tests for graph module.")
else ()
    message(STATUS "Skipping tests for graph module.")
endif ()