#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <cfloat>
#include <climits>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);

public:
  static void convert(const std::string &number);
};

#endif
