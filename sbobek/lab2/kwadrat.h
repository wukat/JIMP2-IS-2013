#ifndef KWADRAT_H
#define KWADRAT_H
#include "punkt.h"

class Kwadrat {
      Punkt w1, w2, w3, w4;

   public:
      Kwadrat();
      Kwadrat(double, double, double, double, double, double, double, double);
      ~Kwadrat();

      double obwod();
      double pole();
};
#endif
