/**
 * @file aghMatrix.cpp
 * @author Marcin Lachowicz
 * @date 10-05-2013
 * @brief
 */

#include "aghInclude.h"

template<>
aghMatrix<char*>::~aghMatrix() {
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
         delete[] values[i][j];
      }
   }

   deAllocate();
}

template<>
void aghMatrix<char*>::setItem(int r, int c, char* value) {
   if((r < 0) || (r >= rows) || (c < 0) || (c >= columns)) {
      throw aghException(0, "Index out of range", __FILE__, __LINE__);
   } else {
      if(values[r][c] != NULL)
         delete[] values[r][c];
      if(value != NULL) {
         values[r][c] = new char[strlen(value) + 1];
         strcpy(values[r][c], value);
      }
   }
}

template<>
void aghMatrix<char*>::setItems(char** array) {
   if(array == NULL) {
      throw aghException(1, "NULL pointer passed to method", __FILE__, __LINE__);
   } else {
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            if(values[i][j] != NULL)
               delete[] values[i][j];
            values[i][j] = new char[strlen(*array) + 1];
            strcpy(values[i][j], *array);
            array++;
         }
      }
   }
}

template<>
void aghMatrix<char>::setItems(int r, int c, ...) {
   if(values != NULL) {
      deAllocate();
   }

   allocate(r, c);

   va_list vl;
   va_start(vl, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         values[i][j] = va_arg(vl, int);
      }
   }
   va_end(vl);

}

template<>
void aghMatrix<char*>::setItems(int r, int c, ...) {
   if(values != NULL) {
      deAllocate();
   }

   allocate(r, c);

   va_list vl;
   va_start(vl, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         values[i][j] = new char[strlen(va_arg(vl, char*)) + 1];
      }
   }
   va_start(vl, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         strcpy(values[i][j], va_arg(vl, char*));
      }
   }
   va_end(vl);

}

template<>
aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const& pattern) {
   if(&pattern != this) {
      if(values != NULL) {
         for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
               delete[] values[i][j];
            }
         }
         deAllocate();
      }
      allocate(pattern.rows, pattern.columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            values[i][j] = new char[strlen(pattern.values[i][j]) + 1];
            strcpy(values[i][j], pattern.values[i][j]);
         }
      }
   }
   return *this;
}

template<>
const aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> const & term) {
   aghMatrix result;
   if((columns != term.getColumns()) || (rows != term.getRows())) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            result.values[i][j] = ((values[i][j] - 2 * 'a' + term.values[i][j]) % (('z' - 'a') + 1)) + 'a';
         }
      }
   }
   return result;
}

template<>
const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const & term) {
   aghMatrix result;
   if((columns != term.getColumns()) || (rows != term.getRows())) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            result.values[i][j] = getSumOfCollections(values[i][j], term.values[i][j]);
         }
      }
   }
   return result;
}

template<>
const aghMatrix<char> aghMatrix<char>::operator*(aghMatrix<char> const& factor) {
   aghMatrix<char> result;
   if(columns != factor.getRows()) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, factor.getColumns());
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < factor.getColumns(); j++) {
            result.setItem(i, j, 0);
            for(int k = 0; k < columns; k++) {
               result.values[i][j] += ((values[i][k] - 'a') * (factor.values[k][j] - 'a')) % (('z' - 'a') + 1);
            }
            result.values[i][j] = result.values[i][j] % (('z' - 'a') + 1) + 'a';
         }
      }
   }
   return result;
}

template<>
const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const & factor) {
   aghMatrix result;
   if(columns != factor.getRows()) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, factor.columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < factor.columns; j++) {
            result.setItem(i, j, NULL);
            for(int k = 0; k < columns; k++) {
               result.values[i][j] = getSumOfCollections(result.values[i][j],
                     getIntersectionOfCollections(values[i][k], factor.values[k][j]));
            }
         }
      }
   }
   return result;
}

template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> & pattern) const {
   bool flag = true;

   if((rows == pattern.rows) && (columns == pattern.columns)) {
      for(int i = 0; i < rows && flag; i++) {
         for(int j = 0; j < columns && flag; j++) {
            flag = compareCollections(pattern.values[i][j], values[i][j]);
         }
      }
   } else {
      flag = false;
   }

   return flag;
}

template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*> & pattern) const {
   return !(*this == pattern);
}
