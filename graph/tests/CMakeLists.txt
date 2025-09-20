# Find all test files
file(GLOB TEST_SOURCES "*.cpp")

# Create test executable for each test file
foreach(testsourcefiles ${TEST_SOURCES})
    get_filename_component(test_name ${testsourcefiles} NAME_WE)
    
    # Create test executable
    add_executable(${test_name} ${testsourcefiles})

    # Link with Google Test and your library
    target_link_libraries(${test_name}
        GTest::gtest_main
        graph
    )

    # Set RPATH to find dynamic libraries
    set_target_properties(${test_name} PROPERTIES
        INSTALL_RPATH "/opt/homebrew/Caskroom/miniconda/base/lib"
        BUILD_WITH_INSTALL_RPATH TRUE
    )

    # Add test to CTest
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach(testsourcefiles ${TEST_SOURCES})
