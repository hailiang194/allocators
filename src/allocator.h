#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include "allocation-math.h"

class Allocator
{
public:
    Allocator(const std::size_t& size);
    Allocator(const Allocator& allocator);
    Allocator& operator=(const Allocator& allocator);
    virtual ~Allocator();

    template<class T>
    T* allocate(const std::size_t& size);

    virtual void deallocate(void* p) = 0;

    void reset();

    const byte_t* start() const;
    const byte_t* start();

    const std::size_t& size() const;
    const std::size_t& size();

    const std::size_t& used() const;
    const std::size_t& used();

    const std::size_t& allocationsize() const;
    const std::size_t& allocationsize();
     

protected:

    virtual void* allocate_(const std::size_t& size) = 0;

    byte_t* m_start;
    std::size_t m_size; 
    std::size_t m_used;
    std::size_t m_allocationSize;
};

template<class T>
inline T* Allocator::allocate(const std::size_t& size)
{
    return static_cast<T*>(allocate_(size));
}

inline const byte_t* Allocator::start() const
{
    return m_start;
}

inline const byte_t* Allocator::start()
{
    return const_cast<const Allocator&>(*this).start();
}

inline const std::size_t& Allocator::size() const
{
    return m_size;
}

inline const std::size_t& Allocator::size()
{
    return const_cast<const Allocator&>(*this).size();
}

inline const std::size_t& Allocator::used() const
{
    return m_used;
}

inline const std::size_t& Allocator::used()
{
    return const_cast<const Allocator&>(*this).used();
}

inline const std::size_t& Allocator::allocationsize() const
{
    return m_allocationSize;
}

inline const std::size_t& Allocator::allocationsize()
{
    return const_cast<const Allocator&>(*this).allocationsize();
}

#endif //!ALLOCATOR_H