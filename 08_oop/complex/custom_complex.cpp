#include <cmath>
#include "custom_complex.h"

double Complex::getRe()
{
  return x;
}

double Complex::getIm()
{
  return y;
}

Complex Complex::operator+(Complex other)
{
  return Complex(x + other.getRe(), y + other.getIm());
}

Complex Complex::operator-(Complex other)
{
  return Complex(x - other.getRe(), y - other.getIm());
}

bool Complex::operator==(Complex other) const
{
  return x == other.getRe() && y == other.getIm();
}

// модуль комплексного числа
double Complex::abs()
{
  return sqrt(x * x + y * y);
}