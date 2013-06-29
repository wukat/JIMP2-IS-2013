#include "aghInclude.h"

aghLFGen::aghLFGen(void) :
      aghGenerator(0, 1, 0, "Generator L'Ecuyer-Fishmana") {
   setSeed2(0);
}

aghLFGen::aghLFGen(int _beg, int _end, int _seed1, int _seed2) { //_beg < _end, _seed > 0
   resetGenerator(_beg, _end, _seed1, _seed2);
   setGeneratorName("Generator L'Ecuyer-Fishmana");
}

aghLFGen::~aghLFGen() {
}

void aghLFGen::setSeed(int _seed) {
   if(_seed < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      seed = _seed;
      state1 = seed;
   }
   return;
}

void aghLFGen::setSeed2(int _seed2) {
   if(_seed2 < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      seed2 = _seed2;
      state2 = seed2;
   }
   return;
}

int aghLFGen::getSeed2(void) const {
   return seed2;
}

void aghLFGen::generate(void) {
   state1 = (48271 * state1) % 2147483647UL;
   state2 = (40692 * state2) % 2147483399UL;

   r_variable = ((state1 - state2) % 2147483647UL) % getRange() + beginning;
   return;
}

void aghLFGen::resetGenerator(int _beg, int _end, int _seed1, int _seed2) { // _seed1 > 0, _seed2 > 0, _beg < _end
   setRange(_beg, _end);
   setSeed(_seed1);
   setSeed2(_seed2);
   return;
}
