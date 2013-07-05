#include "punkt.h"
#include "dtab.h"
#include "list.h"
#include <math.h>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main() {
   Punkt nowy(1, 3);
   cout << "przypisanie 1: ";
   Punkt inny = nowy;
   cout << endl << "przypisanie 2: ";
   nowy = inny;

   DTab owa;
   DTab nowa = owa.wypelniona(1.1);
   nowa.print();
   nowa.set(4.1, 5);
   nowa.print();
   owa.print();

   List fajna;
   fajna.read();
   fajna.add_on_end("kot");
   fajna.add_on_end("pies");
   fajna.add_on_end("malpa ");
   fajna.read();
   List niefajna(fajna);
   niefajna.read();
   niefajna.add_on_pos(2, "kot");
   niefajna.read();
   niefajna.del_pos(3);
   niefajna.read();
   niefajna.add_on_pos(5, "lampart");
   niefajna.find("pies");

   return 0;
}

