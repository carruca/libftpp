#include "memento.hpp"

Memento::Memento() {}

Memento::Memento(const Memento& other) {}

Memento::Memento(Memento&& other) noexcept {}

Memento& Memento::operator=(const Memento& other)
{
  if (this != &other)
  {
  }
  return *this;
}

Memento& Memento::operator=(Memento&& other) noexcept
{
  if (this != &other)
  {
  }
  return *this;
}

Memento::~Memento() {}

