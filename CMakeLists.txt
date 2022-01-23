cmake_minimum_required(VERSION 3.0)

project(rubikn)

add_executable(rubikn main.cpp)

install(TARGETS rubikn RUNTIME DESTINATION bin)
