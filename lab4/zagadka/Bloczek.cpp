#include "Bloczek.h"

using namespace std;

Bloczek::Bloczek():kolor(UNDEF),cyfra(0)
{}

Bloczek::Bloczek(kolor_b kolor, int cyfra)
{
  this->kolor = kolor;
  this->cyfra = cyfra;
}

Bloczek::Bloczek(const Bloczek &inny)
{
  this->kolor = inny.kolor;
  this->cyfra = inny.cyfra;
}

Bloczek::~Bloczek()
{}

void Bloczek::pokaz()
{
  cout << cyfra;
}

void Bloczek::ustaw_cyfre(int cyfra)
{
  this->cyfra = cyfra;
}

void Bloczek::ustaw_kolor(kolor_b kolor)
{
  this->kolor = kolor;
}
