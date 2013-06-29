/**
 *@file aghLFGen.h
 *@author Wojciech Kasperek
 *@date 11-05-2013
 *@brief The definition of aghLFGen class, which is L'Ecuyer-Fishman generator
 */
#ifndef AGHLFGEN_H_
#define AGHLFGEN_H_

#include "aghGenerator.h"

/**
 *@class aghLFGen
 *@author Wojciech Kasperek
 *@date 11-05-2013
 *@brief The definition of aghLFGen class, which is L'Ecuyer-Fishman generator
 */
class aghLFGen: public aghGenerator {
   private:

      int seed2; ///second seed
      int state1, state2; /// generator's actual states

   public:

      /**
       * @brief The default constructor
       */
      aghLFGen(void);

      /**
       * @brief Constructor
       *
       * @param _beg - range beginning
       * @param _end - range end
       * @param _seed1 - first seed
       * @param _seed2 - second seed
       */
      aghLFGen(int, int, int = time(0), int = time(0));

      /**
       * @brief The default destructor
       */
      virtual ~aghLFGen(void);

      /**
       * @brief Seed setter
       * @param _seed - seed
       * @return No value returns
       */
      void setSeed(int);

      /**
       * @brief Seed2 getter
       * @return Seed2
       */
      int getSeed2(void) const;

      /**
       * @brief Seed2 setter
       * @param _seed2 - seed2
       * @return No value returns
       */
      void setSeed2(int);

      /**
       * @brief Function that generates random number
       * @return No value returns
       */
      void generate(void);

      /**
       * @brief Method that resets all parameters
       * @param _beg - range beginning
       * @param _end - range end
       * @param _seed1 - first seed
       * @param _seed2 - second seed
       * @return No value returns
       */
      void resetGenerator(int, int, int = time(0), int = time(0));
};

#endif /* AGHLFGEN_H_ */
