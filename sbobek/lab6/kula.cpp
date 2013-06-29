#include "kula.h"
#include <math.h>

Kula::Kula() : Kolo(),z(0)
{}

Kula::Kula(double x, double y, double z, double r) : Kolo(x,y,r),z(z)
{}

Kula::~Kula()
{}

double Kula::pole()
{
  return 4 * M_PI * r * r;
}

