#include <iostream>

using namespace std;

void wyswietl(int tablica[10][10])
{
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      cout << tablica[i][j] << "  ";
    }
    cout << endl;
  }
}

int main()
{
  int tablica[10][10];

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      tablica[i][j] = (i + 1)*(j + 1);
    }
  }
  wyswietl(tablica);

  return 0;
}
