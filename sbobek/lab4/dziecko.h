#ifndef DZIECKO_H
#define DZIECKO_H
#include <iostream>

class Dziecko {
   private:
      std::string imie, nazwisko;
      int wiek;
      std::string szkola;

   public:
      friend class Rodzic;
      Dziecko();
      Dziecko(std::string, std::string, int, std::string);
      Dziecko(const Dziecko &);
      ~Dziecko();
};

#endif
