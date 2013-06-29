#include <iostream>

using namespace std;

int silnia_it(int a)
{
  for (int i = a - 1; i >= 1; i--)
  {
    a = a * i;
  }
  return a;  
}

int silnia_rek(int a)
{	
  int wynik;
  
  if (a > 0)
    wynik = silnia_rek(a-1) * a;
  else
    wynik = 1;
    
  return wynik; 	
}

int main()
{
  int a;
  cout << "Podaj liczbe: ";
  cin >> a;
  int silnia = silnia_it(a);
  int silnia1 = silnia_rek(a);
  cout << "Wynik " << silnia << endl;
  cout << "Wynik " << silnia1 << endl;
  return 0;	
}