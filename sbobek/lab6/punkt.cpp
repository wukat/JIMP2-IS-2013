#include <math.h>
#include "punkt.h"

using namespace std;

istream & operator>>(istream & input, Punkt & p)
{
  input.ignore();
  input >> p.x;
  input.ignore();
  input >> p.y;
  input.ignore();
  
  return input; 
}

ostream & operator<<(ostream & output, Punkt & p)
{
  output << "(" << p.x << "," << p.y << ")";

  return output;
}

Punkt::Punkt():x(0),y(0)
{}

Punkt::Punkt(double _x, double _y)
{
  x = _x;
  y = _y;
  cout << "konst 2d" << endl;
}

Punkt::Punkt(const Punkt &punkt)
{
  this->x = punkt.x;
  this->y = punkt.y;
}

Punkt::~Punkt()
{
  cout << "dest 2d" << endl;
}

double Punkt::distance(Punkt inny)
{
  return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2));
}

void Punkt::wyswietl()
{
  cout << "(" << x << ";" << y << ")";
}
