#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include "./allocator.h"

class PoolAllocator: public Allocator
{
public:
    PoolAllocator(const std::size_t& size, const std::size_t& chunkSize);
    PoolAllocator(const PoolAllocator& allocator);
    PoolAllocator& operator=(const PoolAllocator& allocator);
    virtual ~PoolAllocator();

    void deallocate(void* p) override;

    const std::size_t& objectSize() const;
    const std::size_t& objectSize();

    const std::size_t& chunkSize() const;
    const std::size_t& chunkSize();
protected:
    void* allocate_(const std::size_t& size) override;

    std::size_t m_objectSize;
    std::size_t m_chunkSize;

    char** m_free; //where is free to allocate
};

inline const std::size_t& PoolAllocator::objectSize() const
{
    return m_objectSize;
}

inline const std::size_t& PoolAllocator::objectSize()
{
    return static_cast<const PoolAllocator&>(*this).objectSize();
}

inline const std::size_t& PoolAllocator::chunkSize() const
{
    return m_chunkSize;
}

inline const std::size_t& PoolAllocator::chunkSize()
{
    return static_cast<const PoolAllocator&>(*this).chunkSize();
}

#endif //!POOL_ALLOCATOR_H