find_package(GTest REQUIRED)
if (GTest_FOUND)
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
endif ()

find_package(OpenMP REQUIRED)
if (OpenMP_CXX_FOUND)
    message(STATUS "Building with OpenMP Multithreading.")
else ()
    message(STATUS "No OpenMP found, no multithreading.")
endif ()
