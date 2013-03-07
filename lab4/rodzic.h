#ifndef RODZIC_H
#define RODZIC_H
#include <iostream>
#include "dziecko.h"

using namespace std;

class Rodzic
{
private:
  string imie, nazwisko;
  int wiek; 
  Dziecko potomek;  

public:
  Rodzic();
  Rodzic(string, string, int, Dziecko);
  Rodzic(const Rodzic &);
  ~Rodzic();

  void PrzepiszDoInnejSzkoly(string);  
};

#endif
