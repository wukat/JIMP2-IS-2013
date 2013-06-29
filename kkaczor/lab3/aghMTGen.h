/**
 *@file aghMTGen.h
 *@author Wojciech Kasperek
 *@date 10-05-2013
 *@brief The definition of aghMTGen class, which is Mersen Twister generator
 */

#ifndef AGHMTGEN_H_
#define AGHMTGEN_H_

#include "aghGenerator.h"

/**
 *@class aghMTGen
 *@author Wojciech Kasperek
 *@date 10-05-2013
 *@brief The definition of aghMTGen class, which is Mersen Twister generator
 */
class aghMTGen: public aghGenerator {
   private:
      unsigned int state[624]; ///array with generator state
      static int i; ///counter

      /**
       * @brief Function that initializes generators state
       * @return No value returns
       */
      void initializeGenerator(void);

      /**
       * @brief Function that generates generators state
       * @return No value returns
       */
      void generateState(void);

   public:

      /**
       * @brief The default constructor
       */
      aghMTGen(void);

      /**
       * @brief Constructor
       * @param _beg - range beginning
       * @param _end - range end
       * @param _seed - seed
       */
      aghMTGen(int, int, int = time(0));

      /**
       * @brief The default destructor
       */
      virtual ~aghMTGen(void) {
      }

      /**
       * @brief Function that generates random number
       * @return No value returns
       */
      void generate(void);

      /**
       * @brief Function that resets all generator's fields
       * @param _beg - range beginning
       * @param _end - range end
       * @param _seed - seed
       */
      void resetGenerator(int, int, int = time(0));

      /**
       * @brief Seed setter
       * @param _seed - seed
       * @return No value returns
       */
      void setSeed(int);
};

#endif /* AGHMTGEN_H_ */
