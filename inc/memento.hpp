#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <vector>
#include <stddef.h>

class Memento
{
public:

  class Snapshot
  {
  private:
    std::vector<std::any> state_;
    std::size_t index_;

  public:
    Snapshot();
    Snapshot(const Snapshot& other);
    Snapshot(Snapshot&& other) noexcept;
    Snapshot& operator=(const Snapshot& other);
    Snapshot& operator=(Snapshot&& other) noexcept;
    ~Snapshot();

    void save(const std::string& key, const std::string& value);
    std::string load(const std::string& key) const;
  };

  Memento();
  Memento(const Memento& other);
  Memento(Memento&& other) noexcept;
  Memento& operator=(const Memento& other);
  Memento& operator=(Memento&& other) noexcept;
  ~Memento();
};

#endif

