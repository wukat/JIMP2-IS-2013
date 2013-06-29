/**
 * @file aghLehmer.cpp
 * @author Marcin Lachowicz
 * @date 11-05-2013
 * @brief
 */

#include "aghInclude.h"

aghLehmer::aghLehmer(void) :
      aghGenerator(0, 1, 0, "Generator Lehmera") {
   setModulus(1);
   setMultiplier(0);
}

aghLehmer::aghLehmer(int _beginning, int _end, int _seed, int _modulus, int _multiplier) :
      aghGenerator(_beginning, _end, _seed, "Generator Lehmera") {
   setModulus(_modulus);
   setMultiplier(_multiplier);
}

aghLehmer::~aghLehmer(void) {

}

void aghLehmer::generate(void) {
   r_variable = ((((multiplier ^ seed) % modulus) % getRange()) + beginning);

   if(r_variable > 0)
      seed = r_variable;
   else
      seed = -r_variable;
   return;
}

int aghLehmer::getModulus(void) const {
   return modulus;
}

void aghLehmer::setModulus(int modulus) {
   if(modulus < 0) {
      throw aghException(0, "incorrect values", __FILE__, __LINE__);
   } else {
      this->modulus = modulus;
   }
   return;
}

int aghLehmer::getMultiplier(void) const {
   return multiplier;
}

void aghLehmer::setMultiplier(int multiplier) {
   if(modulus < 0) {
      throw aghException(0, "incorrect values", __FILE__, __LINE__);
   } else {
      this->multiplier = multiplier;
   }
   return;
}

