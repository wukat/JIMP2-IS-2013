#include "Bloczek.h"

using namespace std;

Bloczek::Bloczek():kolor(-1),liczba(0)
{}

Bloczek::Bloczek(kolor_b kolor, int liczba)
{
  this->kolor = kolor;
  this->liczba = liczba;
}

Bloczek::Bloczek(const Bloczek &inny)
{
  this->kolor = inny.kolor;
  this->liczba = inny.liczba;
}

Bloczek::~Bloczek()
{}
