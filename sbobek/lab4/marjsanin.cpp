#include "marjsanin.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <time.h>

using namespace std;

Marsjanin::Marsjanin() {
   licznik++;
}

Marsjanin::Marsjanin(const Marsjanin &other) {
   licznik++;
}

Marsjanin::~Marsjanin() {
   licznik--;
}

void Marsjanin::atakuj() {
   cout << "----->" << endl;
}

void Marsjanin::ukryj() {
   cout << " H ";
}

int Marsjanin::licznik = 0;
