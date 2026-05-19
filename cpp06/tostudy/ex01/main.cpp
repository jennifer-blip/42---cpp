#include "Serializer.hpp"
#include <iostream>

int main(void) {
  Data d;
  d.id   = 42;
  d.name = "hello";

  uintptr_t raw      = Serializer::serialize(&d);
  Data     *returned = Serializer::deserialize(raw);

  std::cout << "original address  : " << &d       << "\n";
  std::cout << "serialized value  : " << raw       << "\n";
  std::cout << "deserialized addr : " << returned  << "\n";
  std::cout << "pointers equal    : " << (&d == returned ? "yes" : "no") << "\n";
  std::cout << "id                : " << returned->id   << "\n";
  std::cout << "name              : " << returned->name << "\n";
  return 0;
}
