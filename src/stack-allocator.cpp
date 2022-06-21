#include "stack-allocator.h"

struct StackAllocatorHeader
{
    byte_t padding;
    uintptr_t index;
};

StackAllocator::StackAllocator(const std::size_t &size)
    : Allocator(size)
{
}

StackAllocator::StackAllocator(const StackAllocator &allocator)
    : Allocator(allocator)
{
}

StackAllocator &StackAllocator::operator=(const StackAllocator &allocator)
{
    Allocator::operator=(allocator);

    return (*this);
}

StackAllocator::~StackAllocator()
{
}

void StackAllocator::deallocate(void *p)
{
    Allocator::deallocate(p);
    StackAllocatorHeader *header = reinterpret_cast<StackAllocatorHeader *>(reinterpret_cast<byte_t*>(p) - sizeof(StackAllocatorHeader));
    m_used = reinterpret_cast<uintptr_t>(p) - reinterpret_cast<uintptr_t>(m_start) - header->padding;
    m_allocationSize = header->index;
}

void *StackAllocator::allocate_(const std::size_t &size)
{
    byte_t *currentPos = m_start + m_used;
    byte_t adjustment = alignForwardAdjustmentWithHeader(currentPos, sizeof(StackAllocatorHeader));

    if (m_used + adjustment + size > m_size)
        return nullptr;

    void *alignedAddress = currentPos + adjustment;

    // Add Allocation Header
    StackAllocatorHeader *header = reinterpret_cast<StackAllocatorHeader *>(static_cast<byte_t *>(alignedAddress) - sizeof(StackAllocatorHeader));
    header->padding = adjustment;
    header->index = m_allocationSize;
    m_used += adjustment + size;
    ++m_allocationSize;
    
    return alignedAddress;
}