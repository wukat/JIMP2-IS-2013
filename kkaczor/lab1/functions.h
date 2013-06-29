/**
 * @file functions.h
 * @author Wojciech Kasperek
 * @date 26-04-2013
 * @brief File including template and specialized functions
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "aghException.h"

/**
 * @brief Function that sums given arguments
 *
 * @param arg - an array of arguments
 * @param length - length of array
 * @return sum of arguments
 */
template<class T>
double suma(T arg, int length) {
   double result = 0;
   if(length <= 0)
      throw(aghException(0, "Index out of range", __FILE__, __LINE__));
   else {     
      for(int i = 0; i < length; i++) {
         result += arg[i];
      }
      for(int i = 0; i < length - 1; i++) {
         cout << arg[i];
         cout << " + ";
      }
      cout << arg[length-1];
      cout << " = " << result << endl;     
   }
   return result;
}

/**
 * @brief Function that sums given words
 *
 * @param arg - an array of words
 * @param length - number of words in array
 * @return summary length
 */
double suma(char ** arg, int length);

#endif /* FUNCTIONS_H_ */
