#ifndef KULA_H
#define KULA_H
#include "kolo.h"

class Kula: public Kolo {
   protected:
      double z;

   public:
      Kula();
      Kula(double, double, double, double);
      ~Kula();

      double pole();
};

#endif
