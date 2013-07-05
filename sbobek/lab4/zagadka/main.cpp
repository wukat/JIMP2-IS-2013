#include "Pyramid.h"
#include "Block.h"
#include "Floor.h"

using namespace std;

int main() {
   bool done = false;
   Pyramid pierwsza(6);
   pierwsza.set(1, 1, 2);
   pierwsza.set(4, 1, 5);
   pierwsza.set(4, 4, 4);
   pierwsza.set(5, 3, 8);
   pierwsza.set(6, 2, 1);
   pierwsza.set(6, 5, 6);
   pierwsza.color_set(1, 1);
   pierwsza.color_set(2, 1);
   pierwsza.color_set(6, 1);
   pierwsza.color_set(3, 2);
   pierwsza.color_set(4, 2);
   pierwsza.color_set(5, 2);
   pierwsza.show();
   for(int i = 1; i <= 9; i++) {
      if(!done) {
         pierwsza.set(6, 1, i);
         done = pierwsza.solve_pyramid();
      }
   }

   done = false;
   Pyramid druga(9);
   druga.set(9, 1, 6);
   druga.set(9, 5, 5);
   druga.set(9, 9, 7);
   druga.set(8, 3, 8);
   druga.set(8, 6, 6);
   druga.set(7, 1, 5);
   druga.set(7, 4, 5);
   druga.set(7, 7, 1);
   druga.set(6, 2, 5);
   druga.set(6, 5, 2);
   druga.set(4, 1, 7);
   druga.set(4, 4, 2);
   druga.set(3, 2, 2);
   druga.color_set(9, 1);
   druga.show();
   for(int i = 1; i <= 9; i++) {
      if(!done) {
         druga.set(9, 2, i);
         done = druga.solve_pyramid();
      }
   }

   return 0;
}
