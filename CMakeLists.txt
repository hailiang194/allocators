cmake_minimum_required(VERSION 3.1)
project(allocators VERSION 1.0.0)

set(BUILD_EXAMPLES ON)

set(allocators_public_headers
    src/allocation-math.h
    src/allocator.h
    src/arena-allocator.h
    src/stack-allocator.h
    src/pool-allocator.h
)

set(allocators_sources
    src/allocation-math.cpp
    src/allocator.cpp
    src/arena-allocator.cpp
    src/stack-allocator.cpp
    src/pool-allocator.cpp
)

add_library(allocators ${allocators_public_headers} ${allocators_sources})
file(COPY ${allocators_public_headers} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

if(${BUILD_EXAMPLES} )
    add_subdirectory(examples)
endif()