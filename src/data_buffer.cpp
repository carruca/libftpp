#include "data_buffer.hpp"

DataBuffer::DataBuffer() : buffer(), pos(0) {}

DataBuffer::DataBuffer(const DataBuffer& other) : buffer(other.buffer), pos(other.pos) {}

DataBuffer::DataBuffer(DataBuffer&& other) noexcept : buffer(std::move(other.buffer)), pos(other.pos)
{
  other.pos = 0;
}

DataBuffer&
DataBuffer::operator=(const DataBuffer& other)
{
  if (this != &other)
  {
    buffer = other.buffer;
    pos = other.pos;
  }
  return *this;
}

DataBuffer&
DataBuffer::operator=(DataBuffer&& other) noexcept
{
  if (this != &other)
  {
    buffer = std::move(other.buffer);
    pos = other.pos;
    other.pos = 0;
  }
  return *this;
}

DataBuffer::~DataBuffer() {}

template<>
DataBuffer&
DataBuffer::operator<<(const std::string& value)
{
  *this << value.size();
  buffer.insert(buffer.end(), value.begin(), value.end());
  return *this;
}

template<>
DataBuffer&
DataBuffer::operator>>(std::string& value)
{
  size_t size;

  *this >> size;
  value.assign(buffer.begin() + pos, buffer.begin() + pos + size);
  pos += size;
  return *this;
}
