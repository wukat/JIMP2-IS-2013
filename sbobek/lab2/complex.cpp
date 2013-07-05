#include "complex.h"
#include <math.h>
#include <iostream>

using namespace std;

Complex::Complex() :
      re(0), im(0) {
}

Complex::Complex(double _re, double _im) {
   re = _re;
   im = _im;
}

Complex::~Complex() {
}

Complex Complex::add(Complex c) {
   Complex result(c.re + re, c.im + im);
   return result;
}

Complex Complex::sub(Complex c) {
   Complex result(re - c.re, im - c.im);
   return result;
}

Complex Complex::mul(Complex c) {
   Complex result(re * c.re - im * c.im, c.im * re + im * c.re);
   return result;
}

Complex Complex::div(Complex c) {
   double temp = c.re * c.re + c.im * c.im;
   if(temp != 0) {
      Complex result((re * c.re + im * c.im) / temp, (im * c.re - re * c.im) / temp);
      return result;
   } else
      cout << "Nie dziel przez zero";
}

double Complex::abs() {
   return sqrt(re * re + im * im);
}

Complex Complex::pow(int n) {
   double o = abs();
   double fi = asin(im / o);
   double powered = 1;

   for(int i = 0; i < n; i++) {
      powered *= o;
   }

   Complex result(powered * cos(n * fi), powered * sin(n * fi));

   return result;
}

void Complex::show() {
   cout.precision(3);
   cout << re << " ";
   if(im > 0)
      cout << "+ " << im << "i";
   else if(im < 0)
      cout << "- " << -im << "i";
}

