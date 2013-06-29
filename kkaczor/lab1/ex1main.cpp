#include "aghInclude.h"
// -------------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void) {
   cout << "main by kk. Last updated 15.04.2013\n";

   int i_tab[] = { 5, 4, 12, -4, 0 };
   char c_tab[] = { '\"', 'a', 'b', 'c', 'z', '\"' };
   char* c_ptr_tab[] = { "to", "jest", "moj", "pierwszy", "program", "na", "zajeciach" };
   aghFib fib;

   bool t1 = (suma(i_tab, 5) == 17);
   bool t2 = suma(c_tab, 6) == 484;
   bool t3 = (suma(c_ptr_tab, 7) == 35);
   bool t4 = suma(fib, 5) == 7;

   for(int i = 0; i < 6; i++)
      cout << c_tab[i] << " = " << (int) c_tab[i] << endl;

   showTestResult(1, t1);
   showTestResult(2, t2);
   showTestResult(3, t3);
   showTestResult(4, t4);

   cout << "Finally, this is the end...\n";

   return 0;
}
// -------------------------------------------------------------

void showTestResult(int _ti, bool _r) {
   if(_r)
      cout << "Test" << _ti << " PASSED\n";
   else
      cout << "Test" << _ti << " FAILED\n";
}
// ---------------------------------------------------------
