file(GLOB_RECURSE DATA_STRUCTURE_SOURCES 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp"
)

foreach (sourcefiles ${DATA_STRUCTURE_SOURCES})
    string(REPLACE "/" "_" filename ${sourcefiles})
    string(REPLACE ".cpp" "" filename ${filename})
    
    add_executable(${filename} ${sourcefiles})
    set_target_properties(${filename} PROPERTIES LINKER_LANGUAGE CXX)
    target_link_libraries(${filename} PRIVATE core)
    install(TARGETS ${filename} DESTINATION "bin/theory/02_data_structure")

endforeach (sourcefiles ${DATA_STRUCTURE_SOURCES})