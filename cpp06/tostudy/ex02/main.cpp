#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
  std::srand(std::time(NULL));

  for (int i = 0; i < 6; i++) {
    Base *p = generate();
    std::cout << "pointer: ";
    identify(p);
    std::cout << "reference: ";
    identify(*p);
    delete p;
  }
  return 0;
}
