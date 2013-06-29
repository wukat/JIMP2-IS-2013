#include "aghFib.h"

aghFib::aghFib() {
}

aghFib::~aghFib() {
}

int aghFib::operator[](unsigned int n) {
  int result = 0;
  if (n == 1) result = 1;
  else if (n == 0) result = 0;
  else result = this->operator[](n - 1) + this->operator[](n - 2);
  return result;
}
