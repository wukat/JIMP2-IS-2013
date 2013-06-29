#include "punkt.h"
#include "punkt3D.h"
#include <math.h>
 
Punkt3D::Punkt3D() : Punkt(),z(0)
{}

Punkt3D::Punkt3D(double x, double y, double _z) : Punkt(x,y) 
{
  std::cout << "konst 3d" << endl;
  z = _z;
}

Punkt3D::~Punkt3D()
{
  std::cout << "Usuwam Punkt3D" << std::endl;
}

double Punkt3D::distance(Punkt3D inny)
{
  return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2) + pow(z - inny.z, 2));
}

void Punkt3D::wyswietl()
{
  std::cout << "(" << x << ", " << y << ", " << z << ")";
}
