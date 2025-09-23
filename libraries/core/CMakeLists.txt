project(core LANGUAGES CXX)

file(GLOB_RECURSE CORE_HEADERS "include/core/*.hpp")
file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")

# Create core library
add_library(${PROJECT_NAME} ${CORE_HEADERS} ${CORE_SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compiler features
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Add target definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE CORE_EXPORTS=1)

# Set properties
set_target_properties(${PROJECT_NAME} PROPERTIES
        POSITION_INDEPENDENT_CODE ON
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN ON
)

# Installation rules
# if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
#     include(GNUInstallDirs)
#
#     install(TARGETS ${PROJECT_NAME}
#         EXPORT CoreTargets
#         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     )
#
#     install(DIRECTORY include/DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# endif ()
