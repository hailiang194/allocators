#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include "allocation-math.h"

#ifdef _MSC_VER
#define RESET_CODE 0xcd
#else
#define RESET_CODE 0x00
#endif

class Allocator
{
public:
    Allocator(const std::size_t& size);
    Allocator(const Allocator& allocator);
    Allocator& operator=(const Allocator& allocator);
    virtual ~Allocator();
    
    template<typename T, std::size_t size = 1, typename ...Args>
    T* allocate(Args... args);

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

template<typename T, std::size_t size, typename ...Args>
inline T* Allocator::allocate(Args... args)
{
    T* t = static_cast<T*>(allocate_(size * sizeof(T)));
    for(std::size_t i = 0; i < size; ++i)
    {
        *(t + i) = T(std::forward<Args>(args)...);
    }

    return t;
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