cmake_minimum_required(VERSION 3.22)
project(ComputationalGeometry C)


set(CMAKE_C_STANDARD 11)
add_executable(ComputationalGeometry main.c list.c structs.c qSort.c algorithms.c)
target_link_libraries(ComputationalGeometry m)
