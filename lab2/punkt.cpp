#include <math.h>
#include <iostream>
#include "punkt.h"

Punkt::Punkt():x(0),y(0)
{}

Punkt::Punkt(double _x, double _y)
{
  x = _x;
  y = _y;
}

Punkt::~Punkt()
{
}

double Punkt::distance(Punkt inny)
{
  return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2));
}

void Punkt::wyswietl()
{
  cout << "(" << x << ";" << y << ")";
}
