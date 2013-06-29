#include "kwadrat.h"
#include "dtab.h"
#include "complex.h"
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
  Kwadrat fajny(1,1,1,2,2,2,2,1);
  cout << "Nasz fajny kwadrat ma pole rowne " << fajny.pole() << " i odwod rowny " << fajny.obwod() << "." << endl;
  
  
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
  
  
  
  Complex first_c(2,3);
  Complex second_c(5,8);
  Complex result;

  result = first_c.add(second_c);
  cout << "Dodawanie, odejmowanie, mnozenie, dzielenie ";
  first_c.show();
  cout << " i ";
  second_c.show();
  cout << "." << endl;
  result.show();
  cout << endl;
  result = first_c.sub(second_c);
  result.show();
  cout << endl;
  result = first_c.mul(second_c);
  result.show();
  cout << endl;
  result = first_c.div(second_c);
  result.show();
  cout << endl;
  first_c.show();
  cout << " do potegi 3 wynosi ";
  result = first_c.pow(3);
  result.show();
  cout << endl;

  return 0;
}