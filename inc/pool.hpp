#ifndef POOL_HPP
# define POOL_HPP

# include <cstddef>

template<typename TType>
class Pool
{
private:

public:
  class Object
  {
  private:
    TType *pointer;

  public:

    Object() : pointer(nullptr) {}
    Object(const Object& other) : pointer(other.pointer) {}

    ~Object()
    {
      if (pointer != nullptr)
        pointer = nullptr;
    }

    Object&
    operator=(const Object& other)
    {
      pointer = other.pointer;
      return *this;
    }

    TType *
    operator->()
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
};

#endif
