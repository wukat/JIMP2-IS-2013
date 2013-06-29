/**
* @file aghFib.h
* @author Wojciech Kasperek
* @date 25-04-2013
* @version 1.0
* @brief The definition of aghFib class - Fibonacci's series
*/

#ifndef AGHFIB_H_
#define AGHFIB_H_

/**
* @class aghFib
* @author Wojciech Kasperek
* @date 25-04-2013
* @brief The definition of aghFib class - Fibonacci's series
 */
class aghFib {
   public:
      /**
       * @brief The default constructor
       */
      aghFib(void);

      /**
       * @brief Virtual default destructor
       */
      virtual ~aghFib(void);

      /**
       * @brief An overloaded operator [] that gives n-th element of Fibonacci's series
       *
       * @param n - number of  element
       * @return value of n-th element of Fib's series
       */
      int operator[](unsigned int);
};

#endif /* AGHFIB_H_ */
