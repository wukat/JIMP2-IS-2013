#ifndef PUNKT_H
#define PUNKT_H

class Punkt
{
  double x, y;

public:
  Punkt();
  Punkt(double, double);
  Punkt(const Punkt &);
  ~Punkt();

  double distance(Punkt);
  void wyswietl();

  double getX(){return x;}
  double getY(){return y;}
  void setX(double _x){x=_x;}
  void setY(double _y){y=_y;}
};

#endif
