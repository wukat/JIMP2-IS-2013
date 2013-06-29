/**
 * @file aghAverageTest.h
 * @author Marcin Lachowicz
 * @date 13-05-2013
 * @brief
 */

#ifndef AGHAVERAGETEST_H_
#define AGHAVERAGETEST_H_

class aghAverageTest: public aghGenTest {
   public:
      /**
       * @brief Parametric constructor
       * @param _generator - generator to test
       * @param _repeats - number of repeats
       * @param _sampleSize - size of single repeat
       */
      aghAverageTest(aghGenerator*_generator, int _repeats, int _sampleSize);

      /**
       * @brief virtual destructor
       */
      virtual ~aghAverageTest(void);

      /**
       * @brief method tests generator
       */
      void test(void);

      /**
       * @brief method prints results on stream
       * @param stream - stream
       */
      void print(ostream & stream = cout) const;
};

#endif /* AGHAVERAGETEST_H_ */
