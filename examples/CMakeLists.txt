project(examples)

add_executable(arena arena.cpp)
target_link_libraries(arena PUBLIC allocators)
target_link_directories(arena PUBLIC ${allocators_BINARY_DIR}/include)