/**
 * @file aghComplex.cpp
 * @author Marcin Lachowicz
 * @date 10-05-2013
 * @brief source file for aghComplex class
 */

#include "aghInclude.h"

aghComplex::aghComplex() {
   re = 0;
   im = 0;
}

aghComplex::~aghComplex() {

}

aghComplex::aghComplex(double re, double im) {
   this->re = re;
   this->im = im;
}

const aghComplex aghComplex::operator+(const aghComplex & component){
   return aghComplex(re + component.re, im + component.im);
}

const aghComplex aghComplex::operator*(const aghComplex & factor) {
   return aghComplex(re * factor.re - im * factor.im, re * factor.im + im * factor.re);
}

void aghComplex::operator+=(const aghComplex & term) {
   this->re += term.re;
   this->im += term.im;
}

bool aghComplex::operator==(const aghComplex & pattern) {
   return ((re == pattern.re) && (im == pattern.im));
}

bool aghComplex::operator!=(const aghComplex & pattern) {
  return !(*this == pattern);
}
