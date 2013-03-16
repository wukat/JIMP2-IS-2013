#include "matrix.h"

using namespace std;

Matrix::Matrix():matr(NULL),size1(0),size2(0)
{}

Matrix::Matrix(int size1, int size2, string c)
{
  this->size1 = size1;
  this->size2 = size2;
  matr = new string*[size1];
  for (int i = 0; i < size1; i++)
  {
    matr[i] = new string[size2];
    for (int j = 0; j < size2; j++)
      matr[i][j] = c;
  }
}

Matrix::Matrix(const Matrix & m)
{
  this->size1 = size1;
  this->size2 = size2;
  matr = new string*[size1];
  for (int i = 0; i < size1; i++)
    matr[i] = new string[size2];
  
  for (int i = 0; i < size1; i++)
    for (int j = 0; j < size2; j++)
      matr[i][j] = m.matr[i][j]; 
}


Matrix::~Matrix()
{
  for (int i = 0; i < size1; i++)
    delete [] matr[i];
  delete [] matr;
}
