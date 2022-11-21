cmake_minimum_required(VERSION 3.23)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures lab2/main.cpp lab2/List.cpp lab2/List.h lab2/Node.cpp lab2/Node.h lab2/MergeSort.cpp lab2/MergeSort.h lab2/Test.cpp lab2/Test.h)
