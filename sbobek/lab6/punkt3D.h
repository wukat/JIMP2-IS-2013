#ifndef PUNKT3D_H
#define PUNKT3D_H
#include "punkt.h"

class Punkt3D : public Punkt
{
  private:
    double z;
  
  public:
    Punkt3D();
    Punkt3D(double, double, double);
    ~Punkt3D();

    double distance(Punkt3D);
    void wyswietl();
};

#endif
