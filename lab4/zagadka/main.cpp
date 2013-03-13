#include <iostream>
#include "Pyramid.h"
#include "Block.h"
#include "Floor.h"

using namespace std;


int main()
{
  Pyramid pierwsza(6);
  pierwsza.set(1,1,2);
  pierwsza.set(4,1,5);
  pierwsza.set(4,4,4);
  pierwsza.set(5,3,8);
  pierwsza.set(6,2,1);
  pierwsza.set(6,5,6);
  pierwsza.color_set(1,1);
  pierwsza.color_set(2,1);
  pierwsza.color_set(6,1);
  pierwsza.color_set(3,2);
  pierwsza.color_set(4,2);
  pierwsza.color_set(5,2);
  pierwsza.show();

  return 0;
}
