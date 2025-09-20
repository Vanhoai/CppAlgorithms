find_package(GTest QUIET)
if(NOT GTest_FOUND)
    message(STATUS "GTest Not Found, Please install GTest to enable unit tests.")
else()
    message(STATUS "Google Test found")

    # Prefer static libraries
    set_target_properties(GTest::gtest 
        PROPERTIES
        INTERFACE_LINK_LIBRARIES 
        pthread
    )
    
    set_target_properties(GTest::gtest_main 
        PROPERTIES
        INTERFACE_LINK_LIBRARIES 
        "GTest::gtest;pthread"
    )
endif()

option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    message(STATUS "Building with OpenMP Multithreading.")
else()
    message(STATUS "No OpenMP found, no multithreading.")
endif()
