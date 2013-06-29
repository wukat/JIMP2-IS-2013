/**
 * @file aghLehmer.h
 * @author Marcin Lachowicz
 * @date 11-05-2013
 * @brief Implementation of Lehmer RNG
 */

#ifndef AGHLEHMER_H_
#define AGHLEHMER_H_

#include "aghGenerator.h"

/**
 * @class aghLehmer
 * @author Marcin Lachowicz
 * @date 11-05-2013
 * @brief Class represents RNG based on Lehmer algorithm
 */
class aghLehmer: public aghGenerator {
   public:

      /**
       * @brief Default constructor
       */
      aghLehmer(void);

      /**
       * @brief Parametric constructor
       * @param _beginning - beginning of range
       * @param _end - end of range
       * @param _seed - seed
       * @param _modulus - modulus
       * @param _multiplier - multiplier
       */
      aghLehmer(int _beginning, int _end, int _modulus, int _multiplier, int _seed = time(NULL));

      /**
       * @brief Virtual destructor
       */
      virtual ~aghLehmer(void);

      /**
       * @brief Method generate and store random variable
       */
      void generate(void);

      /**
       * @brief modulus getter
       * @return modulus
       */
      int getModulus(void) const;

      /**
       * @brief modulus setter
       * @param modulus - modulus
       */
      void setModulus(int modulus);

      /**
       * @brief multiplier getter
       * @return multiplier
       */
      int getMultiplier(void) const;

      /**
       * @brief multiplier setter
       * @param multiplier - multiplier
       */
      void setMultiplier(int multiplier);

   private:
      int modulus;
      int multiplier;
};

#endif /* AGHLEHMER_H_ */
