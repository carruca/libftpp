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
  Pool(const Pool& other) { (void)other; }

  ~Pool() {}

  Pool&
  operator=(const Pool& other)
  {
    (void)other;
    return *this;
  }

  void
  resize(const std::size_t& numberOfObjectStored)
  {
    (void)numberOfObjectStored;
  }

  template<typename ... TArgs>
  Object
  acquire(TArgs&&... p_args)
  {
    ((void)p_args, ...);
    return Object{};
  }

private:
  void
  release(TType* pointer)
  {
    (void)pointer;
  }
};

#endif
