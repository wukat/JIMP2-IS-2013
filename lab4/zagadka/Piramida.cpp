#include "Piramida.h"
#include <list>

using namespace std; 

Piramida::Piramida():wysokosc(0)
{}

Piramida::Piramida(int wys):wysokosc(wys)
{
  for (int i = 1; i <= wysokosc; i++)
  {
    list<Bloczek> iter1;
    for (int j = 1; j <= i; j++)
      iter1.push_back(Bloczek());
    zawartosc.push_back(iter1);
    iter1.clear();
  }

  list<int> pusta;
  kolory.push_back(pusta);
  kolory.push_back(pusta);
  kolory.push_back(pusta);  
}

Piramida::~Piramida()
{
  for (list< list<Bloczek> >::iterator iter = zawartosc.begin(); iter != zawartosc.end(); ++iter)
    (*iter).clear();
  zawartosc.clear();
  for (list< list<int> >::iterator iter= kolory.begin(); iter != kolory.end(); ++iter)
    (*iter).clear();
  kolory.clear();
}

void Piramida::pokaz()
{
  for (list< list<Bloczek> >::iterator iter= zawartosc.begin(); iter != zawartosc.end(); ++iter)
  {
    for (list<Bloczek>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); ++iter1)
      (*iter1).pokaz();
    cout << endl;
  }
}

void Piramida::pokaz_kolory()
{
  int i = 1;
  for (list< list<int> >::iterator iter= kolory.begin(); iter != kolory.end(); ++iter, i++)
  {
    if (i == 1) cout << "ZOLTY: ";
    else if (i == 2) cout << "NIEBIESKI: ";
    else if (i == 3) cout << "ROZOWY: ";
    for (list<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); ++iter1)
      cout << (*iter1) << " ";
    cout << endl;
  }
}

void Piramida::ustaw_cyfre(int wiersz, int pozycja, int cyfra)
{
  int i = 1;
  for (list< list<Bloczek> >::iterator iter= zawartosc.begin(); i <= wiersz && iter != zawartosc.end(); ++iter, i++)
  {
    if (i == wiersz)
    {
      int j = 1;
      for (list<Bloczek>::iterator iter1 = (*iter).begin(); j <= pozycja && iter1 != (*iter).end(); ++iter1, j++)
      if (j == pozycja)
        (*iter1).ustaw_cyfre(cyfra);
    }
  }
}

void Piramida::ustaw_kolor_wiersza(int wiersz, kolor_b kolor)
{
  int i = 1;
  for (list< list<Bloczek> >::iterator iter= zawartosc.begin(); i <= wiersz && iter != zawartosc.end(); ++iter, i++)
  {
    if (i == wiersz)
    {
      for (list<Bloczek>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); ++iter1)
        (*iter1).ustaw_kolor(kolor);
    }
  }

  switch (kolor)
  {
    case ZOLTY:
      i = 1;
      for (list< list<int> >::iterator iter= kolory.begin(); i <= 1 && iter != kolory.end(); ++iter, i++)
        if (i == 1)
          (*iter).push_back(wiersz);
    break;
    
    case NIEBIESKI:
      i = 1;
      for (list< list<int> >::iterator iter= kolory.begin(); i <= 2 && iter != kolory.end(); ++iter, i++)
        if (i == 2)
          (*iter).push_back(wiersz);
    break;
   
    case ROZOWY:
      i = 1;
      for (list< list<int> >::iterator iter= kolory.begin(); i <= 3 && iter != kolory.end(); ++iter, i++)
        if (i == 3)
          (*iter).push_back(wiersz);
    break;

    default:
    break;
  }
}
