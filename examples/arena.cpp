#include <iostream>
#include <cstring>
#include "arena-allocator.h"

int main()
{
    ArenaAllocator allocator(20);
    int* a = allocator.allocate<int>(sizeof(int));
    *a = 1000;
    std::cout << *a << std::endl;

    char* b = allocator.allocate<char>( 3 * sizeof(char));
    strcpy(b, "Hi");

    std::cout << b << std::endl;

    std::cout << "Memory: " << std::endl;
    for(auto i = 0; i < 20; ++i)
    {
        std::cout << std::hex << static_cast<int>(*(allocator.start() + i)) << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << allocator.size() << std::endl;
    std::cout << "Used: " << allocator.used() << std::endl;
    std::cout << "Num allocator: " << allocator.allocationsize() << std::endl;

    return 0;
}