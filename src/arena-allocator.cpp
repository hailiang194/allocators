#include "arena-allocator.h"

ArenaAllocator::ArenaAllocator(const std::size_t& size)
    :Allocator(size)
{

}

ArenaAllocator::ArenaAllocator(const ArenaAllocator& allocator)
    :Allocator(allocator)
{

}

ArenaAllocator& ArenaAllocator::operator=(const ArenaAllocator& allocator)
{
    Allocator::operator=(allocator);
    
    return (*this);
}

ArenaAllocator::~ArenaAllocator()
{

}

void ArenaAllocator::deallocate(void* p)
{
    //arena allocator doesn't deallocate
}

void* ArenaAllocator::allocate_(const std::size_t& size)
{
    if(size == 0)
    {
        return nullptr;
    }

    byte_t* currentPost = m_start + m_used;
    auto alignment = alignForwardAdjustment(currentPost);
    if(m_used + alignment + size  > m_size)
    {
        return nullptr;
    }
    
    m_used += alignment + size;
    ++m_allocationSize;

    return (void*)(currentPost + alignment);
}