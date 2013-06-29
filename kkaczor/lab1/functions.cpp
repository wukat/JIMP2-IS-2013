/*
 * functions.cpp
 *
 *  Created on: 24-04-2013
 *      Author: Wojciech Kasperek
 */
#include <iostream>
#include <string.h>

using namespace std;
#include "functions.h"
#include "aghException.h"



double suma(char ** arg, int length) {
   double r_length = 0;
   if(length <= 0)
      throw(aghException(0, "Index out of range", __FILE__, __LINE__));
   else if(arg == NULL)
      throw(aghException(1, "Empty array", __FILE__, __LINE__));
   else {   
      for(int i = 0; i < length - 1; i++) {
         cout << arg[i] << " + ";
         r_length += strlen(arg[i]);
      }
      r_length += strlen(arg[length - 1]);
      cout << arg[length - 1] << " = ";
      for(int i = 0; i < length; i++) {
         cout << arg[i];
      }
      cout << "(" << r_length << ")" << endl;     
   }
   return r_length;
}

