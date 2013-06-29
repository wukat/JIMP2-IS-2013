/**
 *@file aghGenTest.h
 *@author Wojciech Kasperek
 *@date 11-05-2013
 *@brief The definition of aghGenTest abstract class
 */

#ifndef AGHGENTEST_H_
#define AGHGENTEST_H_

/**
 *@class aghGenTest
 *@author Wojciech Kasperek
 *@date 11-05-2013
 *@brief The definition of aghGenTest abstract class
 */
class aghGenTest {
   protected:

      double * results; ///test results
      int repeats; /// test repeats
      aghGenerator* generator; ///tested generator
      int sampleSize; /// number of attempts in test

	     /**
       * @brief Results allocation
       * @return No value returns
       */
      void allocResults(void);

      /**
       * @brief Results deallocation
       * @return No value returns
       */
      void deallocResults(void);


   public:
      /**
       * @brief Constructor
       * @param gen - generator
       * @param repeats - test repeats
       * @param sampleSize - number of attempts in test
       */
      aghGenTest(aghGenerator* const, int, int);

      /**
       * @brief The default destructor
       */
      virtual ~aghGenTest(void);

      /**
       * @brief Test Chi Square
       * @return No value returns
       */
      virtual void test(void) = 0;

      /**
       * @brief Generator getter
       * @return Constant reference to generator pointer
       */
      aghGenerator* getGenerator(void) const;

      /**
       * @brief Generator setter
       * @param generator - constant reference to generator pointer
       * @return No value returns
       */
      void setGenerator(aghGenerator*);

      /**
       * @brief repeats getter
       * @return repeats
       */
      int getRepeats(void) const;

      /**
       * @brief repeats setter
       * @param repeats - number of repeats
       * @return No value returns
       */
      void setRepeats(int);

      /**
       * @brief sampleSize getter
       * @return sampleSize
       */
      int getSampleSize(void) const;

      /**
       * @brief sampleSize setter
       * @param sampleSize - number of attempts in test
       * @return No value returns
       */
      void setSampleSize(int);

      /**
       * @brief Result setter
       * @param k - which repeat
       * @param result - result of test
       * @return No value returns
       */
      void setResult(int, double);

      /**
       * @brief Result getter
       * @param k - which repeat
       * @return result
       */
      double getResult(int) const;

      /**
       * @brief Function that prints result to output stream
       * @param  str - output stream, default: cout
       * @return No value returns
       */
      virtual void print(ostream& = cout) const;
};

#endif /* AGHGENTEST_H_ */
