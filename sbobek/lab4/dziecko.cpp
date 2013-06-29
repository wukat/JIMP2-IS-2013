#include "dziecko.h"

using namespace std;

Dziecko::Dziecko():imie(""),nazwisko(""),wiek(0),szkola("")
{}

Dziecko::Dziecko(string _imie, string _nazwisko, int _wiek, string _szkola):imie(_imie),nazwisko(_nazwisko),wiek(_wiek),szkola(_szkola)
{}

Dziecko::Dziecko(const Dziecko &stary)
{
  this->imie = stary.imie;
  this->nazwisko = stary.nazwisko;
  this->wiek = stary.wiek;
  this->szkola = stary.szkola;
}

Dziecko::~Dziecko()
{}


