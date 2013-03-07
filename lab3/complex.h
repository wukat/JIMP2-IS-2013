#ifndef COMLEX_H
#define COMLEX_H


class Complex
{
private:
  double im, re;

public:
  Complex();
  Complex(double _re, double _im);
  ~Complex();

  Complex add(Complex c);
  Complex sub(Complex c);
  Complex mul(Complex c);
  Complex div(Complex c);
  double abs();
  Complex pow(int n);
  void show();
};
#endif
