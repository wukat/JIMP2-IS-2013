#include "complex.h"
#include <math.h>
#include <iostream>

Complex::Complex():re(0),im(0)
{}

Complex::Complex(double _re, double _im)
{
  re = _re;
  im = _im;
}

Complex::~Complex()
{}

Complex Complex::add(Complex c)
{
  Complex result(c.re + re, c.im + im);
  return result;
}

Complex Complex::sub(Complex c)
{
  Complex result(re - c.re, im - c.im);
  return result;
}

Complex Complex::mul(Complex c)
{
  Complex result(re*c.re - im*c.im, c.im*re + im*c.re);
  return result;
}

Complex Complex::div(Complex c)
{
  double temp = c.re*c.re + c.im*c.im;
  if (temp != 0)
  {
    Complex result((re*c.re + im*c.im)/temp, (im*c.re - re*c.im)/temp);
    return result;
  }
  else
    std::cout << "Nie dziel przez zero";
}

void Complex::show()
{
  std::cout << re << " ";
  if (im > 0)
    std::cout << "+ " << im << "i";
  else if (im < 0)
    std::cout << "- " << -im << "i";
}

int main()
{
  Complex first_c(2,3);
  Complex second_c(5,8);
  Complex result;

  result = first_c.add(second_c);
  result.show();

  return 0;
}
