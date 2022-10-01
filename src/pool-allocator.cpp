#include "./pool-allocator.h"

PoolAllocator::PoolAllocator(const std::size_t &size, const std::size_t &chunkSize)
    : Allocator(size)
{
    m_chunkSize = chunkSize;
    m_used = alignForwardAdjustment(m_start);
    m_objectSize = (m_size - m_used) / chunkSize;
    assert(m_objectSize >= sizeof(void *));

    m_free = reinterpret_cast<char**>(m_start + m_used);

    // set the header of each chunk
    char **p = reinterpret_cast<char**>(m_free);
    for (std::size_t i = 0; i < chunkSize - 1; ++i)
    {
        *p = reinterpret_cast<char*>(reinterpret_cast<std::uintptr_t>(p) + m_objectSize);
        //*p = (char *)(p + m_objectSize);
        p = (char**)(reinterpret_cast<std::uintptr_t>(*p));
        //p = (char **)(*p);
    }

    *p = nullptr;
}

PoolAllocator::PoolAllocator(const PoolAllocator &allocator)
    : Allocator(allocator), m_chunkSize(allocator.m_chunkSize), m_objectSize(allocator.m_objectSize)
{
}

PoolAllocator &PoolAllocator::operator=(const PoolAllocator &allocator)
{
    Allocator::operator=(allocator);
    m_chunkSize = allocator.m_chunkSize;
    m_objectSize = allocator.m_objectSize;

    return (*this);
}

PoolAllocator::~PoolAllocator()
{
}

void PoolAllocator::deallocate(void *p)
{
    *((void **)p) = m_free;
    m_free = (char **)p;
    m_used -= m_objectSize;
    --m_allocationSize;
}

void *PoolAllocator::allocate_(const std::size_t &size)
{
    assert(size == m_objectSize);
    if (m_free == nullptr)
        return nullptr;

    void *p = m_free;
    // go to the next free
    m_free = (char **)(*m_free);
    m_used += m_objectSize;
    ++m_allocationSize;

    return p;
}
