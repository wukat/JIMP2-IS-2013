#include "aghInclude.h"

aghChiSqr::aghChiSqr(aghGenerator* generator, int repeats, int sampleSize) :
      aghGenTest(generator, repeats, sampleSize), intervalsNumber(0) {
   setIntervalsNumber();
}

int aghChiSqr::getIntervalsNumber(void) const {
   return intervalsNumber;
}

void aghChiSqr::setIntervalsNumber(void) {
   if(5 * generator->getRange() < sampleSize)
      this->intervalsNumber = generator->getRange();
   else
      this->intervalsNumber = generator->getRange() / 5;
   return;
}

aghChiSqr::~aghChiSqr(void) {
   generator = NULL;
}

void aghChiSqr::test(void) {
   int* histogram = new int[intervalsNumber];
   for(int i = 0; i < repeats; i++) {
      for(int j = 0; j < intervalsNumber; j++)
         histogram[j] = 0;
      for(int j = 0; j < sampleSize; j++) {
         generator->generate();
         (histogram[generator->getVar() % intervalsNumber])++;
      }
      double sumOfSquares = 0.0;
      for(int j = 0; j < intervalsNumber; j++) {
         sumOfSquares += (histogram[j] - sampleSize / generator->getRange())
               * (histogram[j] - sampleSize / generator->getRange());
      }
      setResult(i, sumOfSquares / (sampleSize / generator->getRange()));
   }
   delete[] histogram;
   return;
}

void aghChiSqr::print(ostream& str) const {
   str << "Wyniki testu Chi Square:" << endl;
   aghGenTest::print(str);
   return;
}
