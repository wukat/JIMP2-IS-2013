#include "rodzic.h"

using namespace std;

Rodzic::Rodzic() :
      imie(""), nazwisko(""), wiek(0), potomek() {
}

Rodzic::Rodzic(string _imie, string _nazwisko, int _wiek, Dziecko _potomek) :
      imie(_imie), nazwisko(_nazwisko), wiek(_wiek), potomek(_potomek) {
}

Rodzic::Rodzic(const Rodzic &stary) {
   this->imie = stary.imie;
   this->nazwisko = stary.nazwisko;
   this->wiek = stary.wiek;
   this->potomek = stary.potomek;
}

Rodzic::~Rodzic() {
}

void Rodzic::PrzepiszDoInnejSzkoly(string inna) {
   potomek.szkola = inna;
}
