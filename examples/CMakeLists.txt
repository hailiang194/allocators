project(examples)

add_executable(arena arena.cpp)
target_link_libraries(arena PUBLIC allocators)
target_link_directories(arena PUBLIC ${allocators_BINARY_DIR}/include)

add_executable(stack stack.cpp)
target_link_libraries(stack PUBLIC allocators)
target_link_directories(stack PUBLIC ${allocators_BINARY_DIR}/include)