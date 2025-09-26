project(libraries LANGUAGES C CXX)

# Submodules
add_subdirectory(core)
add_subdirectory(graph)

# Create an interface library to aggregate all libraries
add_library(${PROJECT_NAME} INTERFACE)

# Link all submodules to the interface library
target_link_libraries(${PROJECT_NAME}
    INTERFACE
    core
    graph
)

# Set include directories for the interface library
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
)

message(STATUS "+--------------------- LIBRARY MODULE -----------------------+")
message(STATUS "| 1: Core (Macros)                                           |")
message(STATUS "+------------------------------------------------------------+")
