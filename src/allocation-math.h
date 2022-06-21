#ifndef ALLOCATION_MATH_H
#define ALLOCATION_MATH_H

#include <cstdint>

typedef unsigned char byte_t;

#define ALLOCATOR_ALIGNMENT static_cast<byte_t>(sizeof(int))

byte_t alignForwardAdjustment(const void* address);

byte_t alignForwardAdjustmentWithHeader(const void* address, const byte_t& headerSize);

#endif //ALLOCATION_MATH_H