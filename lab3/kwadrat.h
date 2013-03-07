#ifndef KWADRAT_H
#define KWADRAT_H
#include "punkt.h"

class Kwadrat
{
private:
  Punkt w1, w2, w3, w4;

public:
  Kwadrat();
  Kwadrat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
  ~Kwadrat();

  double obwod();
  double pole();
};
#endif
