#include "pracownik.h"

using namespace std;

Pracownik::Pracownik(const Pracownik & inny)
{
  this->imie = inny.imie;
  this->nazwisko = inny.nazwisko;
  this->pesel = inny.pesel;
  this->umowa = inny.umowa;
}

double Pracownik::pobierzPensje()
{
  return umowa->pobierzNetto();
}

ostream & operator<<(ostream & output, Pracownik & on)
{
  output << on.imie << " " << on.nazwisko << " " << on.pesel << "." << endl;
  output << "Dostaje na reke " << on.pobierzPensje() << " zl." << endl;

  return output;
}

double UmowaPraca::pobierzNetto()
{
  return wynagrodzenieBrutto * 0.6;
}

double UmowaDzielo::pobierzNetto()
{
  return wynagrodzenieBrutto * 0.8;
}
