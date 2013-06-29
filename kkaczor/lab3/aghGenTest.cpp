#include "aghInclude.h"

aghGenTest::aghGenTest(aghGenerator* gen, int repeats, int sampleSize) { //gen != NULL, repeat > 0, sampleSize > 100
   setSampleSize(sampleSize);
   setGenerator(gen);
   results = NULL;
   setRepeats(repeats);
}

aghGenerator* aghGenTest::getGenerator(void) const {
   return generator;
}

void aghGenTest::setGenerator(aghGenerator* generator) {
   if(generator == NULL) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      this->generator = generator;
   }
   return;
}

int aghGenTest::getRepeats(void) const {
   return repeats;
}

void aghGenTest::setRepeats(int repeats) {
   if(repeats <= 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      this->repeats = repeats;
      deallocResults();
      allocResults();
   }
   return;
}

int aghGenTest::getSampleSize(void) const {
   return sampleSize;
}

void aghGenTest::setSampleSize(int sampleSize) {
   if(sampleSize < 100) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      this->sampleSize = sampleSize;
   }
   return;
}

void aghGenTest::setResult(int k, double result) {
   if(k >= repeats || results == NULL) {
      throw aghException(1, "Memory not allocated", __FILE__, __LINE__);
   } else
      results[k] = result;
   return;
}

double aghGenTest::getResult(int k) const {
   double result;
   if(k >= repeats || results == NULL) {
      throw aghException(1, "Memory not allocated", __FILE__, __LINE__);
   } else
      result = results[k];
   return result;
}

void aghGenTest::allocResults(void) {
   if(results != NULL) {
      throw aghException(2, "Memory already allocated", __FILE__, __LINE__);
   } else {
      results = new double[repeats];
      for(int i = 0; i < repeats; i++)
         results[i] = 0.0;
   }
   return;
}

void aghGenTest::deallocResults(void) {
   if(results != NULL)
      delete[] results;
   results = NULL;
   return;
}

aghGenTest::~aghGenTest(void) {
   deallocResults();
   generator = NULL;
}

void aghGenTest::print(ostream& str) const {
   str.precision(15);
   for(int i = 0; i < repeats; i++) {
      str << i + 1 << ". " << getResult(i) << endl;
   }
   str << endl;
}
