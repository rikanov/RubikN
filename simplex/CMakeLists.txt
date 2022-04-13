#core

include_directories( include )
include_directories( ../CLi/include )

add_library( simplex source/axis.cpp
                       source/spin.cpp
                       source/turn.cpp
                  )

link_directories( ../build/CLi )
