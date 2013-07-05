#include "dtab.h"
#include <iostream>

using namespace std;

void DTab::resize(int newsize) {
   double * buf = new double[newsize];
   for(int i = 0; i < length; i++)
      buf[i] = tab[i];
   if(tab != NULL)
      delete[] tab;
   tab = buf;
   length = newsize;
}

DTab::DTab() :
      length(10), last(0), tab(NULL) {
   resize (length);
}

DTab::DTab(int initLength) {
   length = 0;
   tab = NULL;
   resize(initLength);
   last = 0;
}

DTab::~DTab() {
   delete[] tab;
   cout << "usuwam";
}

void DTab::add(double element) {
   if(last == length) {
      resize(length + 1);
      tab[last] = element;
      last = length;
   } else {
      tab[last] = element;
      last++;
   }
}

double DTab::get(int index) {
   if(index < last)
      return tab[index];
   else {
      cout << "Blad" << endl;
      return 0.0;
   }
}

void DTab::set(double element, int index) {
   if(index < last)
      tab[index] = element;
}

void DTab::print() {
   cout << "Twoja tablica: ";
   for(int i = 0; i < last; i++)
      cout << tab[i] << endl;
   cout << "jej koniec" << endl;
}