/**
 *@file aghFibGen.h
 *@author Wojciech Kasperek
 *@date 09-05-2013
 *@brief The definition of aghFibGen class, which is Fibonacci generator
 */

#ifndef AGHFIBGEN_H_
#define AGHFIBGEN_H_

#include "aghGenerator.h"

/**
 *@class aghFibGen
 *@author Wojciech Kasperek
 *@date 09-05-2013
 *@brief The definition of aghFibGen class, which is Fibonacci generator
 */
class aghFibGen: public aghGenerator {
   private:

      int size; ///size of array
      int step; ///step
      int* state; ///array with generator state

      static int i; ///counter

      /**
       * @brief Function that allocates and initializes generators state
       * @return No value returns
       */
      void initializeGenerator(void);

   public:
      /**
       * @brief The default constructor
       */
      aghFibGen(void);

      /**
       * @brief Constructor
       * @param _beg - beginning
       * @param _end - end
       * @param _size - size of array
       * @param _step - step
       * @param _seed - seed
       */
      aghFibGen(int, int, int, int, int = time(0));

      /**
       * @brief The default destructor
       */
      virtual ~aghFibGen(void);

      /**
       * @brief Method that resets all parameters
       * @param _beg - beginning
       * @param _end - end
       * @param _size - size of array
       * @param _step - step
       * @param _seed - seed
       * @return No value returns
       */
      void resetGenerator(int, int, int, int, int = time(0));

      /**
       * @brief Function that generates random number
       * @return No value returns
       */
      void generate(void);

      /**
       * @brief Seed1 size getter
       * @return size of array
       */
      int getSize(void) const;

      /**
       * @brief Generator size setter
       * @param _size - size of array
       * @return No value returns
       */
      void setSize(int);

      /**
       * @brief Step getter
       * @return step
       */
      int getStep(void) const;

      /**
       * @brief Generator step setter
       * @param _step - step
       * @return No value returns
       */
      void setStep(int);

      /**
       * @brief Seed setter
       * @param _seed - seed
       * @return No value returns
       */
      void setSeed(int);
};

#endif /* AGHFIBGEN_H_ */
