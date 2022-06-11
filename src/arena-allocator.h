#ifndef ARENA_ALLOCATOR_H
#define ARENA_ALLOCATOR_H

#include "allocator.h"

class ArenaAllocator: public Allocator
{
public:
    ArenaAllocator(const std::size_t& size);
    ArenaAllocator(const ArenaAllocator& allocator);
    ArenaAllocator& operator=(const ArenaAllocator& allocator);
    ~ArenaAllocator();

    void deallocate(void* p) override;
protected:
    void* allocate_(const std::size_t& size) override;
};

#endif //ARENA_ALLOCATOR_H