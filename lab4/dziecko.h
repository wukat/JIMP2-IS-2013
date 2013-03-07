#ifndef DZIECKO_H
#define DZIECKO_H
#include <iostream>

using namespace std;

class Dziecko
{
private:
  string imie, nazwisko;
  int wiek; 
  string szkola;

public:
  friend class Rodzic;
  Dziecko();
  Dziecko(string, string, int, string);
  Dziecko(const Dziecko &);
  ~Dziecko();
};

#endif
