#include "aghInclude.h"

aghPITest::aghPITest(aghGenerator* gen, int repeats, int sampleSize) : //gen != NULL, repeat > 0, sampleSize > 0
      aghGenTest(gen, repeats, sampleSize) {
}

aghPITest::~aghPITest() {
}

void aghPITest::test(void) {
   int r = generator->getRange();
   int y = 0;
   for(int i = 0; i < repeats; i++) {
      int counter = 0;
      int inCircle = 0;
      while(counter < sampleSize) {
         generator->generate();
         int x = generator->getVar() - generator->getBeginning();
         counter = counter + 1;
         if(x * x + y * y <= r * r)
            inCircle++;
         y = x;
      }
      if(counter > 0) {
         double pi = 4.0 * inCircle / counter;
         setResult(i, pi);
      } else
         setResult(i, 100);
   }
   return;
}

void aghPITest::print(ostream& str) const {
   str << "Wyniki testu Pi:" << endl;
   aghGenTest::print(str);
   return;
}
