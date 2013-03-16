#ifndef PUNKT_H
#define PUNKT_H
#include <iomanip>
#include <iostream>

using namespace std;

class Punkt
{
private:
  double x, y;
public:
  Punkt();
  Punkt(double _x, double _y);
  Punkt(const Punkt &punkt);
  ~Punkt();

  double distance(Punkt inny);
  void wyswietl();
  friend istream & operator>>(istream &, Punkt &);
  friend ostream & operator<<(ostream &, Punkt &);
  double getX(){return x;}
  double getY(){return y;}
  void setX(double _x){x=_x;}
  void setY(double _y){y=_y;}
};

#endif
