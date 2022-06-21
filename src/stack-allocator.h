#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "allocator.h"

class StackAllocator: public Allocator
{
public:
    StackAllocator(const std::size_t& size);
    StackAllocator(const StackAllocator& allocator);
    StackAllocator& operator=(const StackAllocator& allocator);
    virtual ~StackAllocator();

    void deallocate(void* p) override;
protected:
    void* allocate_(const std::size_t& size) override;
};

#endif //STACK_ALLOCATOR_H