#include <iostream>

using namespace std;


bool sprawdz()
{
	char wyraz[50];
	
	cout << "Podaj wyraz: ";
	cin >> wyraz;
	
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
  int opcja;
  cout << "[1] Sprawdz palindrom" << endl;
  cout << "[2] Wyjdz " << endl;
  cin >> opcja;
  
  switch (opcja)
  {
    case 1:
      if (sprawdz()) cout << "Slowo jest palindromem" << endl;
      else cout << "Slowo nie jest palindromem" << endl;
      main();
    break;
    
    case 2:
      return 0;
    break;
    
    default:
      cout << "Podaj poprawna wartosc";
      main();
    break;		
  }
}