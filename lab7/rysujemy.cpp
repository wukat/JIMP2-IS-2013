#include "ksztalt.h"
#include "kolo.h"
#include "trojkat.h"
#include "kwadrat.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <time.h>

using namespace std;

void Kolo::rysuj() const 
{
  cout << " *" << endl << "***" << endl << " *" << endl << endl;
}

void Trojkat::rysuj() const
{
  cout << "  *" << endl << " ***" << endl << "*****" << endl << endl;
}

void Kwadrat::rysuj() const
{
  cout << "***" << endl << "***" << endl << "***" << endl << endl;
}

int main()
{
  srand(time(NULL));
  list<Ksztalt*> figury;
  
  for (int i = 0; i < 20; i++)
    switch (rand() % 3)
    {
      case 0:
        figury.push_back(new Kolo());
        break;
      case 1:
        figury.push_back(new Kwadrat());
        break;
      case 2:
        figury.push_back(new Trojkat());
        break;
    }

  for (list<Ksztalt*>::iterator iter = figury.begin(); iter != figury.end(); iter++)
    (*iter)->rysuj();
}
