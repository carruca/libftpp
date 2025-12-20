#ifndef DATABUFFER_HPP
#define DATABUFFER_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class DataBuffer
{
  std::vector<unsigned char> buffer;
  size_t pos;

public:
  DataBuffer();
  DataBuffer(const DataBuffer& other);
  DataBuffer(DataBuffer&& other) noexcept;

  DataBuffer&
  operator=(const DataBuffer& other);
  DataBuffer&
  operator=(DataBuffer&& other) noexcept;

  virtual ~DataBuffer();

  template<typename T>
  DataBuffer&
  operator<<(const T& data)
  {
    const unsigned char* dataPtr = reinterpret_cast<const unsigned char*>(&data);
    buffer.insert(buffer.end(), dataPtr, dataPtr + sizeof(T));
    return *this;
  }

  template<typename T>
  DataBuffer&
  operator>>(T& data)
  {
    size_t size;
    unsigned char* ptr;

    size = sizeof(T);
    if (pos + size > buffer.size())
      throw std::out_of_range("DataBuffer: Not enough data to read");
    ptr = reinterpret_cast<unsigned char*>(&data);
    std::copy(buffer.begin() + pos, buffer.begin() + pos + size, ptr);
    pos += size;
    return *this;
  }
};

// Specialization for std::string

template<>
DataBuffer&
DataBuffer::operator<<(const std::string& data);

template<>
DataBuffer&
DataBuffer::operator>>(std::string& data);

#endif

