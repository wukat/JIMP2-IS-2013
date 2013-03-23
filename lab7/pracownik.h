#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include <iostream>
 
using namespace std;
 
class Umowa
{
  protected:
    double wynagrodzenieBrutto;
  public:
    Umowa(double pensja) : wynagrodzenieBrutto(pensja){};
    virtual double pobierzNetto() = 0;
    double pobierzBrutto();
    virtual ~Umowa(){};
};
 
class UmowaDzielo: public Umowa
{
  public:
    UmowaDzielo(double pensja) : Umowa(pensja){};
    virtual double pobierzNetto();
    virtual ~UmowaDzielo(){};
};
 
class UmowaPraca: public Umowa
{
  public:
    UmowaPraca(double pensja) : Umowa(pensja){};
    virtual double pobierzNetto();
    virtual ~UmowaPraca(){};
};
 
class Pracownik
{
  private:
    string imie, nazwisko, pesel;
    Umowa* umowa;
  public:
    Pracownik(string i, string n, string p, Umowa* u) : imie(i),nazwisko(n),pesel(p),umowa(u){};
    Pracownik(const Pracownik &);
    ~Pracownik(){};
    double pobierzPensje();
    friend ostream & operator<<(ostream &, Pracownik &);
};

#endif
