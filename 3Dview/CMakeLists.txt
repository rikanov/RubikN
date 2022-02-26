#rubik3d

include_directories( include )
include_directories( ../CLi/include )

add_library( rubik3d source/rubik3d.cpp
                  )

link_directories( ../build/CLi )
