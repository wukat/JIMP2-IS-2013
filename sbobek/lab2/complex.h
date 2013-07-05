#ifndef COMLEX_H
#define COMLEX_H

class Complex {
      double im, re;

   public:
      Complex();
      Complex(double _re, double _im);
      virtual ~Complex();

      Complex add(Complex);
      Complex sub(Complex);
      Complex mul(Complex);
      Complex div(Complex);
      double abs();
      Complex pow(int);
      void show();
};
#endif
