#include "dziecko.h"
#include "rodzic.h"
#include "marjsanin.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <time.h>

using namespace std;

int main()
{
  Dziecko Grodzka("Anna", "Grodzka", 55, "Wojnowo");
  Rodzic tatus("Ryszard", "Kalisz", 65, Grodzka);

  tatus.PrzepiszDoInnejSzkoly("Sejm");


  list<Marsjanin> obcy;
  srand(time(NULL));
  obcy.push_back(Marsjanin());
  obcy.push_back(Marsjanin());
  obcy.push_back(Marsjanin());
  obcy.push_back(Marsjanin());
  obcy.push_back(Marsjanin());
  while (1)
  {
    if (rand() % 2 == 1)
      obcy.push_back(Marsjanin());
    else if (Marsjanin::licznik > 0)
      obcy.pop_back();

    list<Marsjanin>::iterator iter;
    if (Marsjanin::licznik > 5)
      for(iter = obcy.begin(); iter != obcy.end(); ++iter)
        iter->atakuj();
    else
      for(iter = obcy.begin(); iter != obcy.end(); ++iter)
        iter->ukryj();
    cout << endl;
  }
}
