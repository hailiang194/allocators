#include <iostream>
#include <cstring>
#include <iomanip>
#include "stack-allocator.h"

void displayStack(const StackAllocator& allocator)
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
    StackAllocator allocator(256);

    int *a = allocator.allocate<int>(5);

    std::cout << "a=" << *a << std::endl;

    float* b = allocator.allocate<float>(10.5f);

    std::cout << "b=" << *b << std::endl;

    double* d = allocator.allocate<double>(8.25f);

    std::cout << "d=" << *d << std::endl;

    std::cout << "Before deallocate" << std::endl;

    displayStack(allocator);

    allocator.deallocate(b);

    std::cout << "After deallocate" << std::endl;
    displayStack(allocator);
}