project(examples)

add_executable(examples main.cpp)
target_link_libraries(examples PUBLIC allocators)
target_link_directories(examples PUBLIC ${allocators_BINARY_DIR}/include)