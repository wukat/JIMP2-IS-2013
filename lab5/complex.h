#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Matrix;

class Complex
{
private:
  double im, re;

public:
  Complex();
  Complex(double, double);
  ~Complex();

  Complex add(Complex);
  Complex sub(Complex);
  Complex mul(Complex);
  Complex div(Complex);
  Complex operator+(Complex);
  Complex operator-(Complex);
  Complex operator*(Complex);
  Complex operator/(Complex);
  void operator+=(const Complex &);
  void operator-=(const Complex &);
  bool operator==(const Complex &);
  bool operator!=(const Complex &);
  bool operator>(Complex);
  bool operator<(Complex);
  operator Matrix() const;
  double abs();
  Complex pow(int);
  void show();
};
#endif
