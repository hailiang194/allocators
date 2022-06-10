#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>

typedef char byte_t;

class Allocator
{
public:
    Allocator(std::size_t size);
    Allocator(const Allocator& allocator);
    Allocator& operator=(const Allocator& allocator);
    virtual ~Allocator();

    

protected:
    byte_t* m_start;
    std::size_t m_size; 
    std::size_t m_used;
    std::size_t m_allocationSize;
};

#endif //!ALLOCATOR_H