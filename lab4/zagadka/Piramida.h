#ifndef PIRAMIDA_H
#define PIRAMIDA_H
#include "Bloczek.h"


class Piramida
{
private:
  int wysokosc;
  list<list<Bloczek>> zawartosc;

public:
  Piramida();
  Piramida(const Piramida &);
  ~Piramida();


};

#endif
