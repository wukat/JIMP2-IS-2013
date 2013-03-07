#ifndef PUNKT_H
#define PUNKT_H

class Punkt{
private:
  double x, y;
public:
  Punkt();
  Punkt(double _x, double _y);
  Punkt(const Punkt &punkt);
  ~Punkt();

  double distance(Punkt inny);
  void wyswietl();

  double getX(){return x;}
  double getY(){return y;}
  void setX(double _x){x=_x;}
  void setY(double _y){y=_y;}
};

#endif
