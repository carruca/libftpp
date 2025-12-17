#include "data_buffer.hpp"

DataBuffer::DataBuffer() {}

DataBuffer::DataBuffer(const DataBuffer& other)
{
    if (this != &other) {}
}

DataBuffer::DataBuffer(DataBuffer&& other) noexcept
{
    if (this != &other) {}
}

DataBuffer& DataBuffer::operator=(const DataBuffer& other)
{
    if (this != &other) {}
    return *this;
}

DataBuffer& DataBuffer::operator=(DataBuffer&& other) noexcept
{
    if (this != &other) {}
    return *this;
}

DataBuffer::~DataBuffer() {}

