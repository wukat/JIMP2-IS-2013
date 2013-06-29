/**
 * @file aghMatrix_impl.h
 * @author Marcin Lachowicz
 * @date 10-05-2013
 * @brief
 */

#ifndef AGHMATRIX_IMPL_H_
#define AGHMATRIX_IMPL_H_

template<class T>
aghMatrix<T>::aghMatrix() {
   values = NULL;
   rows = 0;
   columns = 0;
}

template<class T>
aghMatrix<T>::aghMatrix(int r, int c) {
   values = NULL;
   allocate(r, c);
}

template<class T>
aghMatrix<T>::aghMatrix(aghMatrix<T> const & pattern) {
   *this = pattern;
}

template<class T>
aghMatrix<T>::~aghMatrix() {
   deAllocate();
}

template<class T>
void aghMatrix<T>::allocate(int r, int c) {
   if((r < 0) || (c < 0)) {
      throw aghException(0, "Index out of range", __FILE__, __LINE__);
   } else if(values != NULL) {
      throw aghException(1, "Memory already located", __FILE__, __LINE__);
   } else {
      rows = r;
      columns = c;

      values = new T*[rows];
      for(int i = 0; i < rows; i++) {
         values[i] = new T[columns];
         for(int j = 0; j < columns; j++) {
            values[i][j] = T();
         }
      }
   }
}

template<class T>
void aghMatrix<T>::deAllocate() {
   for(int i = 0; i < rows; i++) {
      delete[] values[i];
   }
   delete[] values;

   rows = 0;
   columns = 0;
   values = NULL;
}

template<class T>
int aghMatrix<T>::getRows() const {
   return rows;
}

template<class T>
int aghMatrix<T>::getColumns() const {
   return columns;
}

template<class T>
void aghMatrix<T>::setItem(int r, int c, T value) {
   if((r < 0) || (r >= rows) || (c < 0) || (c >= columns)) {
      throw aghException(0, "Index out of range", __FILE__, __LINE__);
   } else {
      values[r][c] = value;
   }
}

template<class T>
void aghMatrix<T>::setItems(T* array) {
   if(array == NULL) {
      throw aghException(1, "NULL pointer passed to method", __FILE__, __LINE__);
   } else {
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            values[i][j] = *(array++);
         }
      }
   }
}

template<class T>
void aghMatrix<T>::setItems(int r, int c, ...) {
   if(values != NULL) {
      deAllocate();
   }

   if((r < 0) || (c < 0)) {
      throw aghException(0, "Index out of range", __FILE__, __LINE__);
   }

   allocate(r, c);

   va_list vl;
   va_start(vl, c);
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         values[i][j] = va_arg(vl, T);
      }
   }
   va_end(vl);

}

template<class T>
aghMatrix<T> const & aghMatrix<T>::operator=(aghMatrix<T> const& pattern) {
   if(&pattern != this) {
      if(values != NULL)
         deAllocate();
      allocate(pattern.rows, pattern.columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            values[i][j] = pattern.values[i][j];
         }
      }
   }
   return *this;
}

template<class T>
const aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> const& term) {
   aghMatrix<T> result;
   if((columns != term.getColumns()) || (rows != term.getRows())) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, columns);
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < columns; j++) {
            result.setItem(i, j, values[i][j] + term.values[i][j]);
         }
      }
   }
   return result;
}

template<class T>
const aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> const& factor) {
   aghMatrix<T> result;
   if(columns != factor.getRows()) {
      throw aghException(2, "Different dimensions of matrices", __FILE__, __LINE__);
   } else {
      result.allocate(rows, factor.getColumns());
      for(int i = 0; i < rows; i++) {
         for(int j = 0; j < factor.getColumns(); j++) {
            result.values[i][j] = T();
            for(int k = 0; k < columns; k++) {
               result.values[i][j] += values[i][k] * factor.values[k][j];
            }
         }
      }
   }
   return result;
}

template<class T>
bool aghMatrix<T>::operator==(aghMatrix<T> & pattern) const {
   bool flag = true;

   if((rows == pattern.rows) && (columns == pattern.columns)) {
      for(int i = 0; i < rows && flag; i++) {
         for(int j = 0; j < columns && flag; j++) {
            flag = (values[i][j] == pattern.values[i][j]);
         }
      }
   } else {
      flag = false;
   }

   return flag;
}

template<class T>
bool aghMatrix<T>::operator !=(aghMatrix<T> & pattern) const {
   bool flag = true;

   flag = !(*this == pattern);

   return flag;
}

template<class T>
T aghMatrix<T>::operator ()(int r, int c) const {
   T result = T();

   if((r < 0) || (c < 0) || (r >= rows) || (c >= columns)) {
      throw aghException(0, "Index out of range", __FILE__, __LINE__);
   } else {
      result = values[r][c];
   }

   return result;
}

#endif /* AGHMATRIX_IMPL_H_ */
