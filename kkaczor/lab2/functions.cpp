/**
 * @file functions.cpp
 * @author Marcin Lachowicz
 * @date 07-05-2013
 * @brief Implementation of functions for char* collections
 */

#include "aghInclude.h"

char* getSumOfCollections(const char* c1, const char* c2) {
   char* result = NULL;

   int c1Length, c2Length;

   if(c1 != NULL || c2 != NULL) {
      if(c1 == NULL) {
         c1Length = 0;
      } else {
         c1Length = strlen(c1);
      }
      if(c2 == NULL) {
         c2Length = 0;
      } else {
         c2Length = strlen(c2);
      }

      char* buffer = new char[c1Length + c2Length + 1];

      int counter = 0;
      for(int i = 0; i < c1Length; i++) {
         if(strchr(buffer, c1[i]) == NULL) {
            buffer[counter++] = c1[i];
         }
      }
      for(int i = 0; i < c2Length; i++) {
         if(strchr(buffer, c2[i]) == NULL) {
            buffer[counter++] = c2[i];
         }
      }

      buffer[counter] = '\0';
      result = new char[counter + 1];
      strcpy(result, buffer);
      delete[] buffer;
   }

   return result;
}

char* getIntersectionOfCollections(const char* c1, const char* c2) {
   char* result = NULL;

   if((c1 != NULL) && (c2 != NULL)) {
      int c1Length = strlen(c1);
      int c2Length = strlen(c2);

      char* buffer = new char[((c1Length > c2Length) ? c1Length : c2Length) + 1];

      int counter = 0;
      for(int i = 0; i < c1Length; i++) {
         char temp = c1[i];
         if(strchr(c2, temp) != NULL) {
            if(strchr(buffer, temp) == NULL) {
               buffer[counter++] = temp;
            }
         }
      }
      buffer[counter] = '\0';
      result = new char[counter + 1];
      strcpy(result, buffer);
      delete[] buffer;
   }

   return result;
}

bool compareCollections(const char* c1, const char* c2) {
   bool flag = true;

   if(c1 != NULL && c2 != NULL) {
      for(unsigned int i = 0; i < strlen(c1) && flag; i++) {
         flag = (strchr(c2, c1[i]) != NULL);
      }
      for(unsigned int i = 0; i < strlen(c2) && flag; i++) {
         flag = (strchr(c1, c2[i]) != NULL);
      }
   } else if(c1 == NULL && c2 == NULL) {
      flag = true;
   } else {
      flag = false;
   }

   return flag;
}
