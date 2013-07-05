#ifndef PUNKT_H
#define PUNKT_H
#include <iomanip>
#include <iostream>

class Punkt {
   protected:
      double x, y;

   public:
      Punkt();
      Punkt(double, double);
      Punkt(const Punkt &);
      ~Punkt();

      double distance(Punkt);
      void wyswietl();
      friend std::istream & operator>>(std::istream &, Punkt &);
      friend std::ostream & operator<<(std::ostream &, Punkt &);
      double getX() {
         return x;
      }
      double getY() {
         return y;
      }
      void setX(double _x) {
         x = _x;
      }
      void setY(double _y) {
         y = _y;
      }
};

#endif
