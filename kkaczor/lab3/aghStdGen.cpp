/**
 * @file aghStdGen.cpp
 * @author Marcin Lachowicz
 * @date 13-05-2013
 * @brief
 */

#include "aghInclude.h"

aghStdGen::aghStdGen(void) :
      aghGenerator(0, 1, 0, "Generator standardowy") {
   srand(seed);
}

aghStdGen::aghStdGen(int _beginning, int _end, int _seed) :
      aghGenerator(_beginning, _end, _seed, "Generator standardowy") {
   srand(seed);
}

aghStdGen::~aghStdGen(void) {
}

void aghStdGen::generate(void) {
   r_variable = (rand() % getRange()) + beginning;
   return;
}

