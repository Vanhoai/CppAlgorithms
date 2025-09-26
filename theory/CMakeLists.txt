project(theory LANGUAGES CXX)

add_subdirectory(01_foundations)
add_subdirectory(02_data_structure)
add_subdirectory(07_graph)

message(STATUS "+--------------------- THEORY MODULE ------------------------+")
message(STATUS "| 1: Foundations                                             |")
message(STATUS "| 2: Data Structure                                          |")
message(STATUS "| 7: Graph                                                   |")
message(STATUS "+------------------------------------------------------------+")