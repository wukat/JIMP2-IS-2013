#include "dtab.h"
#include <iostream>

using namespace std;

void DTab::resize(int newsize)
{
  double * buf = new double[newsize];
  for (int i = 0; i < length; i++)
    buf[i] = tab[i];
  delete tab;
  tab = buf;
  length = newsize;
}

DTab::DTab():length(10),last(0)
{
  resize(length);
}

DTab::DTab(int initLength)
{
  length = 0;
  resize(initLength);
  last = 0;
}

DTab::~DTab()
{
  delete tab;
  cout << "usuwam";
}

void DTab::add(double element)
{
  if (last == length)
  {
    resize(length + 1);
    tab[last] = element;
    last = length;
  }
  else
  {
    tab[last] = element;
    last++;
  }
}

double DTab::get(int index)
{
  if (index < last)
    return tab[index];
  else
    return 0.0;
}

void DTab::set(double element, int index)
{
  if (index < last)
    tab[index] = element;
}

void DTab::print()
{
  cout << "Twoja tablica: ";
  for (int i = 0; i < last; i++)
    cout << tab[i] << endl;
  cout <<"jej koniec" << endl;
}


int main()
{
  DTab tablica(3);
  cout << "Dodajemy elementy 3.4, 5.1, 6.7, 9.5" << endl;
  tablica.add(3.4);
  tablica.add(5.1);
  tablica.add(6.7);
  tablica.add(9.5);
  tablica.print();

  cout << "Pobieramy trzeci element " << tablica.get(2) << endl;
  cout << "Ustalamy trzeci element na 4.1" << endl;
  tablica.set(4.1, 2);
  tablica.print();

  //delete &tablica;
  return 0;
}
