cmake_minimum_required(VERSION 3.23)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures main.cpp lab3/stack/Stack.cpp lab3/stack/Stack.h lab3/buffer/RingBuffer.cpp lab3/buffer/RingBuffer.h lab3/queue/StackQueue.cpp lab3/queue/StackQueue.h lab3/queue/RingBufferQueue.cpp lab3/queue/RingBufferQueue.h)
