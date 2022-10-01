#include <iostream>
#include <iomanip>
#include "pool-allocator.h"

void displayPool(const PoolAllocator& allocator)
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
    PoolAllocator allocator(16, 4);
    displayPool(allocator);

    int* a = allocator.allocate<int>(0);
    *a = 1000;
    displayPool(allocator);

    char* b = allocator.allocate<char>('c');
    displayPool(allocator);
    return 0;
}