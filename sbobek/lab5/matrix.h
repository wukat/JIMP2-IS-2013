#ifndef MATRIX_H
#define MARTIX_H
#include <iostream>
#include "complex.h"

class Matrix
{
private:
  Complex ** matr;
  int size1, size2;

public:
  Matrix();
  Matrix(int, int, Complex);
  Matrix(const Matrix &);
  ~Matrix();
};

#endif
