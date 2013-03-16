#include "punkt.h"
#include "punkt3D.h"


int main()
{
  Punkt3D pierwszy(1,4,6);
  Punkt3D drugi(2,3,1);
  
  std::cout << pierwszy.distance(drugi) << std::endl;
  pierwszy.wyswietl();
  drugi.wyswietl();

  Punkt trzeci(1,4);
  std::cout << trzeci.distance(pierwszy) << endl;
  std::cout << pierwszy;

}
