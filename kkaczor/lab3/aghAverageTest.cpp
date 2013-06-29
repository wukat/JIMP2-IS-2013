/**
 * @file aghAverageTest.cpp
 * @author Marcin Lachowicz
 * @date 13-05-2013
 * @brief
 */

#include "aghInclude.h"

aghAverageTest::aghAverageTest(aghGenerator* _generator, int _repeats, int _sampleSize) :
      aghGenTest(_generator, _repeats, _sampleSize) {
}

aghAverageTest::~aghAverageTest(void) {

}

void aghAverageTest::test(void) {
   for(int i = 0; i < repeats; i++) {
      double average = 0;
      for(int j = 0; j < sampleSize; j++) {
         generator->generate();
         average += (static_cast<double>(generator->getVar()) / static_cast<double>(sampleSize));
      }

      setResult(i, (average - (generator->getRange() / 2.)));
   }
   return;
}

void aghAverageTest::print(ostream & stream) const {
   stream << "Wynik testu średniej: \n";
   aghGenTest::print(stream);
   return;
}
