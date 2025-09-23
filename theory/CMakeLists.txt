project(theory LANGUAGES CXX)

add_subdirectory(01_foundations)
add_subdirectory(02_data_structure)

# add_custom_target(${PROJECT_NAME})
# add_dependencies(${PROJECT_NAME} 01_foundations 02_data_structure)

# Print information about the project
message(STATUS "+----------------------------- THEORY -----------------------------+")
message(STATUS "| 1: Foundations                                                   |")
message(STATUS "| 2: Data Structure                                                |")
message(STATUS "+------------------------------------------------------------------+")