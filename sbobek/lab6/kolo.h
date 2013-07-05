#ifndef KOLO_H
#define KOLO_H

class Kolo {
   protected:
      double x, y, r;

   public:
      Kolo();
      Kolo(double, double, double);
      ~Kolo();

      double pole();
};

#endif
