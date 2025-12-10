#ifndef POOL_HPP
# define POOL_HPP

# include <cstddef>

  template<typename TType>
class Pool
{
public:
  template<TType>
  class Object
  {
    Object() : pointer{nullptr} {}

    TType *pointer;

    TType *
    operator->()
    {
      return pointer;
    }
  };

  void
  resize(const size_t& numberOfObjectStored)
  {
    (void)numberOfObjectStored;
  }

  template<typename ... TArgs>
  Object<TType>
  acquire(TArgs&&... p_args)
  {
    ((void)p_args, ...);
    return Object<TType>{};
  }
};

#endif
