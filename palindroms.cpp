#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;


string na_dwoj(int n)
{
  char a;
  string wynik = "";

  if (n % 2 == 0)
    a = '0';
  else
    a = '1';

  if (n > 1)
  {
    n /= 2;
    wynik = na_dwoj(n);
  }
  wynik += a;

  return wynik;
}

bool sprawdz(string wyraz)
{
  int i = 0;
  while (wyraz[i] != '\0')
    i++;
  int ostatni = i - 1;

  bool ok = true;

  for(i = 0; i <= ostatni; i++)
  {
    if ((wyraz[ostatni - i] == wyraz[i]) && ok)
      ok = true;
    else
      ok = false;
  }

  return ok;
}


int main()
{
  int liczba_palindromow = 0;
  string liczba;

  for (int  i = 1; i < 1000000; i++)
  {
    if (i % 10 != 0)
    {
      ostringstream ss;
      ss << i;
      string liczba = ss.str();
      if (sprawdz(liczba))
      {
        string liczba2 = "";
        liczba2 = na_dwoj(i);
        if (sprawdz(liczba2))
        {
          cout << liczba << " ; " << liczba2 << endl;
          liczba_palindromow++;
        }
      }
    }
  }

  cout << "Liczba palindromow < 1000000 baza 2 i 10 wynosi " << liczba_palindromow << endl;

  return 0;
}
