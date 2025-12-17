#ifndef DATABUFFER_HPP
#define DATABUFFER_HPP

class DataBuffer
{
public:
    DataBuffer();
    DataBuffer(const DataBuffer& other);
    DataBuffer(DataBuffer&& other) noexcept;
    DataBuffer& operator=(const DataBuffer& other);
    DataBuffer& operator=(DataBuffer&& other) noexcept;
    ~DataBuffer();
};

#endif

