#core

include_directories( include )
include_directories( ../CLi/include )

add_library( core source/axis.cpp
                  source/spin.cpp
                  )

link_directories( ../build/CLi )
