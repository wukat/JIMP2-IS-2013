/**
 * @file aghStdGen.h
 * @author Marcin Lachowicz
 * @date 13-05-2013
 * @brief Implementation of standard RNG
 */

#ifndef AGHSTDGEN_H_
#define AGHSTDGEN_H_

#include "aghGenerator.h"

class aghStdGen: public aghGenerator {
   public:

      /**
       * @brief Default constructor
       */
      aghStdGen(void);

      /**
       * @brief parametric constructor
       * @param _beginning - begin of range
       * @param _end - end of range
       * @param _seed - seed
       */
      aghStdGen(int _beginning, int _end, int _seed = time(NULL));

      /**
       * @brief Destructor
       */
      virtual ~aghStdGen(void);

      /**
       * @brief method generate and store random number
       */
      void generate(void);
};

#endif /* AGHSTDGEN_H_ */
