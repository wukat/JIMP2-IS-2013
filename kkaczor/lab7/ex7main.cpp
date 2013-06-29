#include "aghInclude.h"
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void) {
   cout << "main by kk. Last updated 15.04.2013\n";

   aghVector<int> a, b;
   aghContainer<int>* cptr = &a;
   aghIterator<int> iter1(&a), iter2(&b), iter3(cptr);

   a.append(1);
   a.append(2);
   a.append(3);
   a.append(4);
   a.append(5);

   b.append(6);
   b.append(7);
   b.append(8);
   b.append(9);
   b.append(10);

   // 1st test - iterators setting up v1
   showTestResult(1, iter1.current() == a.at(0));

   // 2nd test - iterators setting up v2
   showTestResult(2, iter2.current() == b.at(0));

   // 3rd test - next method
   iter1.next();
   showTestResult(3, iter1.current() == a.at(1));

   // 4th test - prev method
   iter2.prev();
   try {
      iter2.current();
      showTestResult(4, false);
   } catch (aghException& e) {
      showTestResult(4, true);
   } catch (...) {
      showTestResult(4, false);
   }

   // 5th test - first method
   showTestResult(5, (iter1.first().current() == a.at(0)) && (iter1.current() == a.at(1)));

   // 6th test - last method
   showTestResult(6, (iter3.last().current() == a.at(a.size() - 1)) && (iter3.current() == a.at(0)));

   // 7th test - atFirst method
   iter1.atFirst();
   showTestResult(7, iter1.current() == a.at(0));

   // 8th test - atLast method
   iter2.atLast();
   showTestResult(8, iter2.current() == b.at(b.size() - 1));

   // 9th method - size method
   iter3.atFirst();
   iter3.next().next();
   showTestResult(9, iter3.size() == (a.size() - 2));

   // 10th test - operator []
   iter3.atFirst();
   bool t10 = (iter3[2] == a.at(2));
   t10 = t10 && (iter3.current() == a.at(0));
   t10 = t10 && (iter3.next().next()[1] == a.at(3));
   t10 = t10 && (iter3.current() == a.at(2));
   t10 = t10 && (iter3[-1] == a.at(1));
   showTestResult(10, t10);

   // 11th test - operator int
   iter3.atFirst();
   iter3.prev();
     bool t11 = ((int)iter3 == NULL);
   iter3.next().next().next();
     t11 = t11 && ((int)iter3 != NULL);
   iter3.atLast();
   iter3.next();
    t11 = t11 && ((int)iter3 == NULL);
    showTestResult(11, t11);

   // 12th - test operator*
   iter1.atFirst();
   bool t12 = (*iter1 == a.at(0));
   t12 = t12 && (*iter1.next().last() == a.at(a.size() - 1));
   t12 = t12 && (*iter1 == a.at(1));
   *iter1 += 10;
   t12 = t12 && (a.at(1) == 12);
   iter1.current() = 2;
   t12 = t12 && (*iter1 == 2);
   showTestResult(12, t12);

   // 13th test - operator+
   iter2.atFirst();
   bool t13 = (*(iter2 + 2) == b.at(2));
   try {
      *(iter2.atLast() + 1);
   } catch (aghException& e) {
      t13 = t13 && true;
   } catch (...) {
      t13 = t13 && false;
   }
   showTestResult(13, t13);

   // 14th test - operator-
   iter2.atLast();
   bool t14 = (*(iter2 - 3) == b.at(1));
   try {
      *(iter2.first() - 1);
   } catch (aghException& e) {
      t14 = t14 && true;
   } catch (...) {
      t14 = t14 && false;
   }
   showTestResult(14, t14);

   // 15th test - operator += and -=
   iter1.atFirst();
   iter1 += 2;
   bool t15 = (*iter1 == a.at(2));
   iter1 += 1;
   t15 = t15 && (*iter1 == a.at(3));
   iter1 -= 3;
   t15 = t15 && (*iter1 == a.at(0));
   try {
      iter1 -= 1;
   } catch (...) {
      t15 = false;
   }
   showTestResult(15, t15);

   // 16th test - operators ++
   iter3.atFirst();
   bool t16 = (*iter3++ == cptr->at(0));
   t16 = t16 && (*iter3 == cptr->at(1));
   t16 = t16 && (*++iter3 == cptr->at(2));
   t16 = t16 && (*iter3 == cptr->at(2));
   showTestResult(16, t16);

   // 17th test - operators --
   iter3.atLast();
   bool t17 = (*iter3-- == cptr->at(cptr->size() - 1));
   t17 = t17 && (*iter3 == cptr->at(cptr->size() - 2));
   t17 = t17 && (*--iter3 == cptr->at(cptr->size() - 3));
   t17 = t17 && (*iter3 == cptr->at(cptr->size() - 3));
   showTestResult(17, t17);

   // 18th test - operator == and !=
   iter1.atFirst();
   iter2.atFirst();
   iter3.atFirst();
   bool t18 = (iter1 == iter3);
   t18 = t18 && (iter1 != iter2);
   t18 = t18 && (iter2 != iter3);
   t18 = t18 && (iter1 != (iter3 + 1));
   iter1.next();
   t18 = t18 && (iter1 == (iter3 + 1));
   iter2.next();
   t18 = t18 && (iter1 != iter2);
   iter1.atFirst();
   iter3.atLast();
   t18 = t18 && ((iter1 + 2) == (iter3 - 2));
   iter3.prev();
   t18 = t18 && (*(iter1 + 2) == *(iter3 - 1));
   showTestResult(18, t18);

   // 19th test - operator =
   iter1.atFirst();
   iter2.atFirst().next();
   iter3.atLast();
   iter1 = iter3;
   bool t19 = (iter1 == iter3);
   t19 = t19 && (iter1 != iter2);
   t19 = t19 && (iter1.size() == 1);
   iter1 = iter2;
   t19 = t19 && (iter1 == iter2);
   t19 = t19 && (*iter1 == b.at(1));
   showTestResult(19, t19);

   // 20th test - operator =
   iter1.atLast();
   iter2.atLast();
   iter3.atLast();
   bool t20 = (iter1 == iter2);
   iter1 = cptr;
   t20 = t20 && (iter1 != iter2);
   t20 = t20 && (iter1 != iter3);
   t20 = t20 && (iter1 == iter3.first());
   t20 = t20 && (*iter1 == a.at(0));
   iter1.atLast();
   t20 = t20 && (iter1 == iter3);
   t20 = t20 && (iter1 != iter2);
   showTestResult(20, t20);

   cout << "Finally, this is the end...\n";

   return 0;
}
// ---------------------------------------------------------

void showTestResult(int _ti, bool _r) {
   if(_r)
      cout << "Test" << _ti << " PASSED\n";
   else
      cout << "Test" << _ti << " FAILED\n";
}
// ---------------------------------------------------------
