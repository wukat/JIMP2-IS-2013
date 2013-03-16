#ifndef MATRIX_H
#define MARTIX_H
#include <iostream>

using namespace std;

class Matrix
{
private:
  string ** matr;
  int size1, size2;

public:
  Matrix();
  Matrix(int, int, string);
  Matrix(const Matrix &);
  ~Matrix();
};

#endif
