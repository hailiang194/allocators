#include "allocator.h"

Allocator::Allocator(const std::size_t& size)
{
    m_start = new byte_t[size];
    m_size = size;
    m_used = 0;
    m_allocationSize = 0;
}

Allocator::Allocator(const Allocator& allocator)
    :m_start(allocator.m_start), m_size(allocator.m_size), m_used(allocator.m_used), m_allocationSize(allocator.m_allocationSize)
{

}

Allocator& Allocator::operator=(const Allocator& allocator)
{
    m_start = allocator.m_start; 
    m_size = allocator.m_size;
    m_used = allocator.m_used; 
    m_allocationSize = allocator.m_allocationSize;

    return (*this);
}

Allocator::~Allocator()
{
    delete[] m_start;
    m_start = nullptr;
}

void Allocator::deallocate(void* p)
{
    assert(p != nullptr && p > m_start && (byte_t*)p - m_start < m_size);
}

void Allocator::reset()
{
    memset(m_start, RESET_CODE, m_size);
    m_used = 0;
    m_allocationSize = 0;
}