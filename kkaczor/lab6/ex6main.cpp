#include "aghInclude.h"
// ---------------------------------------------------------

void showTestResult(int, bool);
// ---------------------------------------------------------

int main(void)
{
    cout << "main by kk. Last updated 15.04.2013\n";

    aghVector<aghVector<int> > a;
    aghContainer<int>* c1 = new aghVector<int>;
    aghTree<int>* c2;
    a << *((aghVector<int>*)c1);

    // 1st test - dodawanie do pojemnika stalych, zmiennych, tymczasowych
    c1->append(3);
    c1->insert(0, 1+4);
    c1->insert(c1->size(), c1->size());

    bool t1 = c1->size() == 3;
    int ttab1[] = {5, 3, 2};
    for(int i=0;i<3;i++)
        t1 = t1 && (ttab1[i] == c1->at(i));
    showTestResult(1, t1);

    // 2nd test - konstruktor
    c2 = new aghTree<int>(*c1);
    bool t2 = c2->size() == 3;
    int ttab2[] = {2, 3, 5};
    for(int i=0;i<3;i++)
      t2 = t2 && (ttab2[i] == c2->at(i));
    showTestResult(2, t2);

    // 3rd test - odwolania
    try
    {
        c2->at(-1);
        c2->at(100);
        (*c2)[-10];
        (*c2)[100];
        showTestResult(3, true);
    }
    catch(aghException& e)
    {
        showTestResult(3, true);
    }
    catch(...)
    {
        showTestResult(3, false);
    }

    // 4th test - usuwanie z pojemnika
    c2->clear();
    for(int i=0;i<5;i++)
      *c2 += i;
   *c2 << 4 << 2+3 << -5 << 3;
   c2->remove(2);


    int ttab4[] = {-5, 0, 2, 3, 3, 4, 4, 5};
    bool t4 = c2->size() == 8;
    for(int i=0;t4 && i<8;i++)
        t4 = t4 && (ttab4[i] == c2->at(i));
    showTestResult(4, t4);

    // 5th test
    a.at(0).clear();
    a.at(0) << *c2;
    bool t5 = a.at(0).size() == 8;
    int ttab5[] = {-5, 0, 2, 3, 3, 4, 4, 5};
    for(int i=0;i<8;i++)
        t5 = t5 && (ttab5[i] == a.at(0).at(i));
    showTestResult(5, t5);

    // 6th test - metoda indexOf
    showTestResult(6, c2->indexOf(3) == 3);

    // 7th test - metoda indexOf
    showTestResult(7, c2->indexOf(3, 4) == 4);

    // 8th test - metoda indexOf
    showTestResult(8, c2->indexOf(0, 3) == -1);

    // 9th test - metoda contains
    showTestResult(9, !c2->contains(-6));


    // 10th test - sortowanie
    c1->clear();
    bool t10 = (c1->size() == 0) && (c2->size() == 8);
    int ttab10_1[] = {7, -5, 12, 15, 9, -10, -20, -8, 1, -3, 2};
    int ttab10_2[] = {-20, -10, -8, -5, -3, 1, 2, 7, 9, 12, 15};
    for(int i=0;i<11;i++)
        c1->append(ttab10_1[i]);
    for(int i=0;i<11;i++)
        t10 = t10 && (c1->at(i) == ttab10_1[i]);
    *c2 = *c1;
    c1->clear();
    *c1 << *c2;
    for(int i=0;i<11;i++)
        t10 = t10 && (c1->at(i) == ttab10_2[i]);
    showTestResult(10, t10);

    // 11th test - dzialanie operatora przypisania
    a.at(0) = *c1;
    showTestResult(11, a.at(0) == *c2);

    // 12th test - operator przypisania
    *c2 = *c2;
    try
    {
        showTestResult(12, a.at(0) == *c2);
    }
    catch(...)
    {
        showTestResult(12, false);
    }

    // 13th test - usuwanie z pojemnika
    c2->remove(2);    // -8
    c2->remove(0);    // -20
    c2->remove(1);    // -5
    c2->remove(5);    // 9
    c2->remove(5);    // 12
    c2->remove(4);    // 7
    showTestResult(13, c2->size() == 5);

    // 14th test
    bool t14 = c2->size() == 5;
    int ttab14[] = {-10, -3, 1, 2, 15};
    for(int i=0;i<5;i++)
        t14 = t14 && (c2->at(i) == ttab14[i]);
    showTestResult(14, t14);

    // 15th test - zwalnianie paieci
    try
    {
        delete c1;
        delete c2;
        showTestResult(15, true);
    }
    catch(...)
    {
        showTestResult(15, false);
    }

    cout << "Finally, this is the end...\n";

    return 0;
}
// ---------------------------------------------------------

void showTestResult(int _ti, bool _r)
{
    if(_r)
        cout << "Test" << _ti << " PASSED\n";
    else
        cout << "Test" << _ti << " FAILED\n";
}
// ---------------------------------------------------------
