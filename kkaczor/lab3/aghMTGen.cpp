#include "aghInclude.h"

int aghMTGen::i = 0;

aghMTGen::aghMTGen(void) :
      aghGenerator(0, 1, 0, "Generator Mersen Twister") {
   r_variable = 0;
   for(int j = 0; j < 624; j++)
      state[j] = 0;
}

aghMTGen::aghMTGen(int _beg, int _end, int _seed) { //_beg < _end, _seed >= 0
   resetGenerator(_beg, _end, _seed);
   setGeneratorName("Generator Mersen Twister");
}

void aghMTGen::initializeGenerator(void) {
   state[0] = seed;
   for(int j = 1; j < 624; j++) {
      state[j] = (1812433253UL * (state[j - 1] ^ (state[j - 1] >> 30)) + j) % 4294967296UL;
   }
   return;
}

void aghMTGen::generateState(void) {
   for(int j = 1; j < 624; j++) {
      unsigned int temp = ((state[j] >> 31) % 2) + (state[(j + 1) % 624]) % 2147483648UL;
      state[j] = state[(j + 397) % 624] ^ (temp >> 1);
      if((temp % 2) == 1)
         state[j] = state[j] ^ 2567483615UL;
   }
   return;
}

void aghMTGen::generate(void) {
   if(i == 0)
      generateState();

   unsigned int temp = state[i];
   temp = temp ^ (temp >> 11);
   temp = temp ^ ((temp << 7) & 2636928640UL);
   temp = temp ^ ((temp << 15) & 4022730752UL);
   temp = temp ^ (temp >> 18);

   i = (i + 1) % 624;
   r_variable = (temp % getRange()) + beginning;
   return;
}

void aghMTGen::resetGenerator(int _beg, int _end, int _seed) { //_beg < _end
   if(_seed < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      setRange(_beg, _end);
      setSeed(_seed);
      r_variable = 0;
   }
   return;
}

void aghMTGen::setSeed(int _seed) {
   if(_seed < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      seed = _seed;
      initializeGenerator();
   }
   return;
}
