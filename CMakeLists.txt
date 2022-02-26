cmake_minimum_required(VERSION 3.0)

project(rubikn)

include_directories( group/include )
include_directories( cube_operations/include )
include_directories( cube_parts/ )
include_directories( core/include )
include_directories( CLi/include )
include_directories( 3Dview/include )


add_subdirectory( 3Dview )
add_subdirectory( CLi )
add_subdirectory( core )

add_executable( rubikn main.cpp )

set_property( TARGET rubikn PROPERTY CXX_STANDARD 17 )
target_link_libraries( rubikn cli core rubik3d )

install( TARGETS rubikn RUNTIME DESTINATION bin )
