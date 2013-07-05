#include "kwadrat.h"
#include <math.h>
#include <iostream>

using namespace std;

Punkt::Punkt() :
      x(0), y(0) {
}

Punkt::Punkt(double _x, double _y) {
   x = _x;
   y = _y;
}

Punkt::~Punkt() {
}

double Punkt::distance(Punkt inny) {
   return sqrt(pow(x - inny.x, 2) + pow(y - inny.y, 2));
}

void Punkt::wyswietl() {
   cout << "(" << x << ";" << y << ")";
}

Kwadrat::Kwadrat() :
      w1(0, 0), w2(0, 0), w3(0, 0), w4(0, 0) {
}

Kwadrat::Kwadrat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
   Punkt _w1(x1, y1);
   Punkt _w2(x2, y2);
   Punkt _w3(x3, y3);
   Punkt _w4(x4, y4);
   w1 = _w1;
   w2 = _w2;
   w3 = _w3;
   w4 = _w4;
}

Kwadrat::~Kwadrat() {
}

double Kwadrat::obwod() {
   return w1.distance(w2) * 4;
}

double Kwadrat::pole() {
   return pow(w1.distance(w2), 2);
}

