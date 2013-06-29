/**
 *@file aghPITest.h
 *@author Wojciech Kasperek
 *@date 12-05-2013
 *@brief The definition of aghPITest test class
 */

#ifndef AGHPITEST_H_
#define AGHPITEST_H_

/**
 *@class aghPITest
 *@author Wojciech Kasperek
 *@date 12-05-2013
 *@brief The definition of aghPITest test class
 */
class aghPITest: public aghGenTest {
   public:
      /**
       * @brief Constructor
       * @param gen - generator
       * @param repeats - test repeats
       * @param sampleSize - number of attempts in test
       */
      aghPITest(aghGenerator*, int, int);

      /**
       * @brief The default destructor
       */
      virtual ~aghPITest(void);

      /**
       * @brief Test Pi
       * @return No value returns
       */
      void test(void);

      /**
       * @brief Function that prints result to output stream
       * @param  str - output stream, default: cout
       * @return No value returns
       */
      void print(ostream& = cout) const;

};

#endif /* AGHPITEST_H_ */
