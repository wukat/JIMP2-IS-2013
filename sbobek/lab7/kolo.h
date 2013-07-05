#ifndef KOLO_H
#define KOLO_H

class Ksztalt;

class Kolo: public Ksztalt {
   public:
      Kolo() :
            Ksztalt() {
      }
      void rysuj() const;
      virtual ~Kolo() {
      }
};

#endif
