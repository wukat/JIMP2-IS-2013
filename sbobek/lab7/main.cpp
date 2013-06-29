#include "pracownik.h"

using namespace std;

int main()
{
  UmowaDzielo dzielo(2000);
  UmowaPraca praca(2000);

  Pracownik Kowalski("Jan", "Kowalski", "93070232120", &dzielo);
  cout << Kowalski;

  Pracownik Nowak("Maciej", "Nowak", "93020431324", &praca);  
  cout << Nowak;
}
