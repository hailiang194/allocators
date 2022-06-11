#include "allocation-math.h"

byte_t alignForwardAdjustment(const void* address)
{
    byte_t adjustment = ALLOCATOR_ALIGNMENT - (reinterpret_cast<uintptr_t>(address) & (ALLOCATOR_ALIGNMENT - 1));

    if(adjustment == ALLOCATOR_ALIGNMENT)
        return 0;

    return adjustment;
}