#ifndef KWADRAT_H
#define KWADRAT_H

class Ksztalt;

class Kwadrat: public Ksztalt {
   private:
      int g;
   public:
      Kwadrat() :
            Ksztalt() {
      }
      void rysuj() const;
      virtual ~Kwadrat() {
      }
};

#endif
