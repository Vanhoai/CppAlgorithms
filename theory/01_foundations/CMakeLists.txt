file(GLOB_RECURSE FOUNDATION_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (sourcefiles ${FOUNDATION_SOURCES})

    string(REPLACE ".cpp" "" filename ${sourcefiles})
    add_executable(${filename} ${sourcefiles})
    set_target_properties(${filename} PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(${filename} PRIVATE core)
    install(TARGETS ${filename} DESTINATION "bin/theory/01_foundations")

endforeach (sourcefiles ${FOUNDATION_SOURCES})
