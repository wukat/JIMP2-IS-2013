#include <iostream>

using namespace std;

void wspak(char wyraz[20], int i) {
   if(wyraz[i] != '\0') {
      wspak(wyraz, i + 1);
      cout << wyraz[i];
   }
}

int main() {
   char wyraz[20];

   cout << "Podaj wyraz: ";
   cin >> wyraz;
   wspak(wyraz, 0);
   cout << endl;

   return 0;
}