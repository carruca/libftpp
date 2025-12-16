#ifndef POOL_HPP
# define POOL_HPP

# include <cstddef>
# include <vector>
# include <stack>

template<typename TType>
class Pool
{
private:
  std::vector<TType*> allocated;
  std::stack<TType*> available;

public:
  class Object
  {
  private:
    TType* pointer;
    Pool* pool;

  public:
    Object() : pointer(nullptr), pool(nullptr) {}
    Object(TType* pointer, Pool *pool) : pointer(pointer), pool(pool) {}
    Object(const Object& other) : pointer(other.pointer), pool(other.pool) {}
    Object(Object&& other) : pointer(other.pointer), pool(other.pool)
    {
      other.pointer = nullptr;
      other.pool = nullptr;
    }
    ~Object()
    {
      if (pointer != nullptr && pool != nullptr)
        pool->release(pointer);
      pointer = nullptr;
      pool = nullptr;
    }

    Object&
    operator=(const Object& other)
    {
      if (this != &other)
      {
        pointer = other.pointer;
        pool = other.pool;
      }
      return *this;
    }

    Object&
    operator=(Object&& other)
    {
      if (this != &other)
      {
        pointer = other.pointer;
        pool = other.pool;
        other.pointer = nullptr;
        other.pool = nullptr;
      }
      return *this;
    }

    TType*
    operator->()
    {
      return pointer;
    }

    const TType*
    operator->() const
    {
      return pointer;
    }
  };

  Pool() {}
  Pool(const Pool& other) = delete;
  Pool&
  operator=(const Pool& other) = delete;


  ~Pool()
  {
    for (TType* pointer : allocated)
    {
      ::operator delete(pointer);
    }
  }

  void
  resize(const std::size_t& numberOfObjectStored)
  {
    for (std::size_t i = 0; i < numberOfObjectStored; ++i)
    {
      TType* pointer = static_cast<TType*>(::operator new(sizeof(TType)));
      allocated.push_back(pointer);
      available.push(pointer);
    }
  }

  template<typename ... TArgs>
  Object
  acquire(TArgs&&... p_args)
  {
    TType* pointer = nullptr;

    if (!available.empty())
    {
      pointer = available.top();
      available.pop();
    }
    else
    {
      pointer = static_cast<TType*>(::operator new(sizeof(TType)));
      allocated.push_back(pointer);
    }
    new (pointer) TType(std::forward<TArgs>(p_args)...);
    return Object(pointer, this);
  }

private:
  void
  release(TType* pointer)
  {
    pointer->~TType();
    available.push(pointer);
  }
};

#endif
