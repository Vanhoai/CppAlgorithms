project(data_structure LANGUAGES CXX)

# Collect source files
file(GLOB_RECURSE DATA_STRUCTURE_HEADERS "include/data_structure/*.hpp")
file(GLOB_RECURSE DATA_STRUCTURE_SOURCES "src/*.cpp")

# Create data_structure library
add_library(${PROJECT_NAME} ${DATA_STRUCTURE_HEADERS} ${DATA_STRUCTURE_SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link dependencies
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    core
)

# Add tests subdirectory
if (BUILD_TESTS)
    add_subdirectory(tests)
    message(STATUS "Building tests for data_structure module.")
else ()
    message(STATUS "Skipping tests for data_structure module.")
endif ()
