#ifndef ALLOCATION_MATH_H
#define ALLOCATION_MATH_H

#include <cstdint>

typedef unsigned char byte_t;

#define ALLOCATOR_ALIGNMENT static_cast<byte_t>(sizeof(int))

byte_t alignForwardAdjustment(const void* address);


#endif //ALLOCATION_MATH_H