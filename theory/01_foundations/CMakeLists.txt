file( GLOB_RECURSE THEORY_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

foreach(sourcefiles ${THEORY_SOURCES})
    
    string( REPLACE ".cpp" "" filename ${sourcefiles} )
    add_executable( ${filename} ${sourcefiles} )
    set_target_properties(${filename} PROPERTIES LINKER_LANGUAGE CXX)
    install(TARGETS ${filename} DESTINATION "bin/theory/01_foundations")

endforeach(sourcefiles ${THEORY_SOURCES})
