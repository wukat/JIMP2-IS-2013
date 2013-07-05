#ifndef RODZIC_H
#define RODZIC_H
#include <iostream>
#include "dziecko.h"

class Rodzic {
      std::string imie, nazwisko;
      int wiek;
      Dziecko potomek;

   public:
      Rodzic();
      Rodzic(std::string, std::string, int, Dziecko);
      Rodzic(const Rodzic &);
      ~Rodzic();

      void PrzepiszDoInnejSzkoly(std::string);
};

#endif
