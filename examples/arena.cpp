#include <iostream>
#include <cstring>
#include  <iomanip>
#include "arena-allocator.h"

void displayArena(const ArenaAllocator& allocator)
{
    std::cout << "Memory: " << std::endl;
    for(auto i = 0; i < allocator.size(); ++i)
    {
        std::cout << "0x" << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(*(allocator.start() + i)) << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Size: " << allocator.size() << std::endl;
    std::cout << "Used: " << allocator.used() << std::endl;
    std::cout << "Num allocator: " << allocator.allocationsize() << std::endl;
}

int main()
{
    ArenaAllocator allocator(20);
    int* a = allocator.allocate<int>(0xffff);
    std::cout << *a << std::endl;

    char* b = allocator.allocate<char, 3>();
    strcpy(b, "Hi");

    std::cout << b << std::endl;

    float* c = allocator.allocate<float>(0xff + 1.5f);

    std::cout << *c << std::endl;

    displayArena(allocator);

    allocator.reset();

    std::cout << "Reseted" << std::endl;

    displayArena(allocator);

    *a = 10;

    return 0;
}