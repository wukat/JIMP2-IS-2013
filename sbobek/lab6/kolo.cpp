#include "kolo.h"
#include <math.h>

Kolo::Kolo() :
      x(0), y(0), r(0) {
}

Kolo::Kolo(double x, double y, double r) :
      x(x), y(y), r(r) {
}

Kolo::~Kolo() {
}

double Kolo::pole() {
   return M_PI * r * r;
}
