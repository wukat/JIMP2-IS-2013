/**
 *@file aghChiSqr.h
 *@author Wojciech Kasperek
 *@date 12-05-2013
 *@brief The definition of aghChiSqr test class
 */

#ifndef AGHCHISQR_H_
#define AGHCHISQR_H_

/**
 *@class aghChiSqr
 *@author Wojciech Kasperek
 *@date 12-05-2013
 *@brief The definition of aghChiSqr test class
 */
class aghChiSqr: public aghGenTest {
   private:

      int intervalsNumber; /// number of intervals

   public:
      /**
       * @brief Constructor
       * @param gen - generator
       * @param repeats - test repeats
       * @param sampleSize - number of attempts in test
       */
      aghChiSqr(aghGenerator*, int, int);

      /**
       * @brief The default destructor
       */
      virtual ~aghChiSqr(void);

      /**
       * @brief Intervals number getter
       * @return Intervals number
       */
      int getIntervalsNumber(void) const;

      /**
       * @brief Calculates intervals number setter
       */
      void setIntervalsNumber(void);

      /**
       * @brief Chi square test
       */
      void test(void);

      /**
       * @brief Function that prints result to output stream
       * @param  str - output stream, default: cout
       * @return No value returns
       */
      void print(ostream& = cout) const;
};

#endif /* AGHCHISQR_H_ */
