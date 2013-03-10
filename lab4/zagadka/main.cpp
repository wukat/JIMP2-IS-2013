#include <iostream>
#include "Piramida.h"
#include "Bloczek.h"

int main()
{
  Piramida pierwsza(6);
  pierwsza.ustaw_cyfre(1,1,2);
  pierwsza.ustaw_cyfre(4,1,5);
  pierwsza.ustaw_cyfre(4,4,4);
  pierwsza.ustaw_cyfre(5,3,8);
  pierwsza.ustaw_cyfre(6,2,1);
  pierwsza.ustaw_cyfre(6,5,6);
  pierwsza.ustaw_kolor_wiersza(1,NIEBIESKI);
  pierwsza.ustaw_kolor_wiersza(2,NIEBIESKI);
  pierwsza.ustaw_kolor_wiersza(6,NIEBIESKI);
  pierwsza.ustaw_kolor_wiersza(3,ROZOWY);
  pierwsza.ustaw_kolor_wiersza(4,ROZOWY);
  pierwsza.ustaw_kolor_wiersza(5,ROZOWY);
  pierwsza.pokaz_kolory();
  pierwsza.pokaz();
  



  return 0;
}
