project(libraries LANGUAGES CXX)

# Submodules
add_subdirectory(core)

# Create an interface library to aggregate all libraries
add_library(libraries INTERFACE)

# Link all submodules to the interface library
target_link_libraries(${PROJECT_NAME}
        INTERFACE
        core
)

# Set include directories for the interface library
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
)
