#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

enum NumberType { CHAR, INT, DOUBLE, FLOAT };

static NumberType getNumberType(const std::string &number) {
  if (number.length() == 1 && !std::isdigit(number[0]))
    return CHAR;

  if (number == "nanf" || number == "+inff" || number == "-inff")
    return FLOAT;
  if (number == "nan" || number == "+inf" || number == "-inf")
    return DOUBLE;
  if (!number.empty() && number[number.size() - 1] == 'f')
    return FLOAT;
  if (number.find('.') != std::string::npos)
    return DOUBLE;

  return INT;
}

static void printChar(double value) {
  if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
    std::cout << "char:   impossible\n";
  else if (!std::isprint(static_cast<int>(value)))
    std::cout << "char:   Non displayable\n";
  else
    std::cout << "char:   '" << static_cast<char>(value) << "'\n";
}

static void printInt(double value) {
  if (std::isnan(value) || std::isinf(value) || value < INT_MIN ||
      value > INT_MAX)
    std::cout << "int:    impossible\n";
  else
    std::cout << "int:    " << static_cast<int>(value) << "\n";
}

static void printFloat(double value) {
  if (std::isnan(value)) {
    std::cout << "float:  nanf\n";
  } else if (std::isinf(value)) {
    std::cout << "float:  " << (value > 0 ? "+inff" : "-inff") << "\n";
  } else {
    std::cout << std::fixed << std::setprecision(1)
              << "float:  " << static_cast<float>(value) << "f\n";
  }
}

static void printDouble(double value) {
  if (std::isnan(value)) {
    std::cout << "double: nan\n";
  } else if (std::isinf(value)) {
    std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << "\n";
  } else {
    std::cout << std::fixed << std::setprecision(1) << "double: " << value
              << "\n";
  }
}

static void printImpossible() {
  std::cout << "char:   impossible\n";
  std::cout << "int:    impossible\n";
  std::cout << "float:  impossible\n";
  std::cout << "double: impossible\n";
}

void ScalarConverter::convert(const std::string &number) {
  NumberType type = getNumberType(number);
  double value;

  switch (type) {
  case CHAR:
    value = static_cast<double>(number[0]);
    break;

  case INT: {
    char *end;
    long val = strtol(number.c_str(), &end, 10);
    if (*end != '\0') {
      printImpossible();
      return;
    }
    value = static_cast<double>(val);
    break;
  }

  case FLOAT: {
    if (number == "nanf")
      value = std::numeric_limits<double>::quiet_NaN();
    else if (number == "+inff")
      value = std::numeric_limits<double>::infinity();
    else if (number == "-inff")
      value = -std::numeric_limits<double>::infinity();
    else {
      std::string stripped = number.substr(0, number.size() - 1);
      char *end;
      value = strtod(stripped.c_str(), &end);
      if (*end != '\0') {
        printImpossible();
        return;
      }
    }
    break;
  }

  case DOUBLE: {
    if (number == "nan")
      value = std::numeric_limits<double>::quiet_NaN();
    else if (number == "+inf")
      value = std::numeric_limits<double>::infinity();
    else if (number == "-inf")
      value = -std::numeric_limits<double>::infinity();
    else {
      char *end;
      value = strtod(number.c_str(), &end);
      if (*end != '\0') {
        printImpossible();
        return;
      }
    }
    break;
  }

  default:
    return;
  }

  printChar(value);
  printInt(value);
  printFloat(value);
  printDouble(value);
}
