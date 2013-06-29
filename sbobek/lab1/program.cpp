#include <iostream> // Dołączamy bibliotekę odpowiedzialna za
                    // operacje wejścia i wyjścia
 
using namespace std;
 
int main(int argv, char* arg[]){
  char imie[20];
  cout << "Podaj swoje imie: ";
  cin >> imie;
  cout << "Witaj " << imie << endl;
  return 0;
}