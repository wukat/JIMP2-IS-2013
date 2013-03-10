#ifndef PIRAMIDA_H
#define PIRAMIDA_H
#include "Bloczek.h"
#include <list>


class Piramida
{
private:
  int wysokosc;
  list< list<Bloczek> > zawartosc;
  list< list<int> > kolory;

public:
  Piramida();
  Piramida(int);
  //Piramida(const Piramida &);
  ~Piramida();

  void pokaz();
  void pokaz_kolory();
  void ustaw_cyfre(int, int, int);
  void ustaw_kolor_wiersza(int, kolor_b);
};

#endif
