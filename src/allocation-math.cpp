#include "allocation-math.h"

byte_t alignForwardAdjustment(const void *address)
{
    byte_t adjustment = ALLOCATOR_ALIGNMENT - (reinterpret_cast<uintptr_t>(address) & (ALLOCATOR_ALIGNMENT - 1));

    if (adjustment == ALLOCATOR_ALIGNMENT)
        return 0;

    return adjustment;
}

byte_t alignForwardAdjustmentWithHeader(const void *address, const byte_t &headerSize)
{
    byte_t adjustment = alignForwardAdjustment(address);
    byte_t neededSpace = headerSize;

    if (adjustment < neededSpace)
    {
        neededSpace -= adjustment;

        // Increase adjustment to fit header
        adjustment += ALLOCATOR_ALIGNMENT * (neededSpace / ALLOCATOR_ALIGNMENT);

        if (neededSpace % ALLOCATOR_ALIGNMENT > 0)
            adjustment += ALLOCATOR_ALIGNMENT;
    }

    return adjustment;
}