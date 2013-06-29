#include "aghInclude.h"

int aghFibGen::i = 0;

aghFibGen::aghFibGen(void) :
      aghGenerator(0,1,0, "Generator Fibonacciego") {
   size = 0;
   step = 0;
   state = NULL;
}

aghFibGen::aghFibGen(int _beg, int _end, int _size, int _step, int _seed) {  //_beg < _end, _size > _step > 0, _seed > 0
   state = NULL;
   resetGenerator(_beg, _end, _size, _step, _seed);
   setGeneratorName("Generator Fibonacciego");
}

aghFibGen::~aghFibGen() {
   if(state != NULL)
      delete[] state;
   state = NULL;
}

void aghFibGen::initializeGenerator(void) {
   if(size <= 1) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      if(state != NULL)
         delete[] state;
      state = new int[size];

      srand(seed);
      for(int i = 0; i < size; i++)
         state[i] = rand() % getRange() + beginning;
   }
}

void aghFibGen::generate(void) {
   state[i] = ((state[(size + i - step) % size] ^ state[i]) % getRange()) + beginning;
   r_variable = state[i];
   i = (i + 1) % size;
   return;
}

int aghFibGen::getSize(void) const {
   return size;
}

void aghFibGen::setSize(int _size) {
   if(_size <= 1) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      size = _size;
      initializeGenerator();
      return;
   }
}

int aghFibGen::getStep(void) const {
   return step;
}

void aghFibGen::setStep(int _step) {
   if(_step <= 0 || _step > size) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      step = _step;
      return;
   }
}

void aghFibGen::setSeed(int _seed) {
   if(_seed < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      seed = _seed;
      initializeGenerator();
      return;
   }
}

void aghFibGen::resetGenerator(int _beg, int _end, int _size, int _step, int _seed) { //_beg > _end, _size > _step > 0, _seed > 0
   if(_step >= _size) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      setSize(_size);
      setStep(_step);
      setRange(_beg, _end);
      setSeed(_seed);
      initializeGenerator();
   }
   return;
}

