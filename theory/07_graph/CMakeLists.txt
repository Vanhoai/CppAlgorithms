file(GLOB_RECURSE GRAPH_SOURCES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp"
)

foreach (sourcefiles ${GRAPH_SOURCES})
    string(REPLACE "/" "_" filename ${sourcefiles})
    string(REPLACE ".cpp" "" filename ${filename})

    add_executable(${filename} ${sourcefiles})
    set_target_properties(${filename} PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(${filename} PRIVATE core)
    install(TARGETS ${filename} DESTINATION "bin/theory/07_graph")

endforeach (sourcefiles ${GRAPH_SOURCES})
