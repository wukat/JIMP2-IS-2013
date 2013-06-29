/**
 * @file aghMatrix.h
 * @author Marcin Lachowicz
 * @date 06-05-2013
 * @brief aghMatrix class header file
 */

#ifndef AGHMATRIX_H_
#define AGHMATRIX_H_

/**
 * @class aghMatrix
 * @author Marcin Lachowicz
 * @date 06-05-2013
 * @brief Class represents matrix of any size and store any items
 */
template<class T>
class aghMatrix {
   public:
      /**
       * @brief The default constructor
       */
      aghMatrix();

      /**
       * @brief The constructor that creates rectangular matrix
       * @param r - number of rows
       * @param c - number of columns
       */
      aghMatrix(int r, int c);

      /**
       * @brief The copy constructor
       * @param pattern - pattern
       */
      aghMatrix(aghMatrix<T> const & pattern);

      /**
       * \brief The destructor
       */
      virtual ~aghMatrix();

      /**
       * @brief Rows getter
       * @return Number of rows
       */
      int getRows() const;

      /**
       * @brief Columns getter
       * @return Number of columns
       */
      int getColumns() const;

      /**
       * @brief Method set item at intersection row and column
       * @param r - row
       * @param c - column
       * @param value - value
       */
      void setItem(int r, int c, T value);

      /**
       * @brief Method fill the matrix with values stored in array
       * @param array - pointer to first element of array
       */
      void setItems(T* array);

      /**
       * @brief Method fill r rows and c columns of matrix with (r*c) values
       * @param r - number of rows
       * @param c - number of columns
       * @param values
       */
      void setItems(int r, int c, ...);

      /**
       * @brief Overloaded assignment operator
       * @param pattern - pattern
       * @return reference to current object
       */
      aghMatrix const & operator=(aghMatrix<T> const & pattern);

      /**
       * @brief Overloaded addition operator
       * @param term - term
       * @return added components
       */
      const aghMatrix operator+(aghMatrix<T> const & term);

      /**
       * @brief Overloaded multiplication operator
       * @param factor - factor
       * @return multiplied factors
       */
      const aghMatrix operator*(aghMatrix<T> const & factor);

      /**
       * @brief Overloaded comparison operator
       * @param pattern - pattern
       * @return True if matrices are similar
       */
      bool operator==(aghMatrix<T> & pattern) const;

      /**
       * @brief Overloaded differential operator
       * @param pattern - pattern
       * @return True if Matrices are different
       */
      bool operator!=(aghMatrix<T> & pattern) const;

      /**
       * @brief Method gets element at intersection r row and c column
       * @param r - row
       * @param c - column
       * @return element at intersection r row and c column
       */
      T operator ()(int r, int c) const;

   private:
      /**
       * @brief Method allocates memory for matrix
       * @param r - rows
       * @param c - columns
       */
      void allocate(int r, int c);

      /**
       * @brief Method deallocates memory from matrix
       */
      void deAllocate();
      int rows;
      int columns;
      T** values;
};
/**
 * @brief Specialized constructor for char*
 */
template<>
aghMatrix<char*>::~aghMatrix();

/**
 * @brief Specialized method for char*. Method sets item at r row and c column with value
 * @param r - row
 * @param c - column
 * @param value - value to set
 */
template<>
void aghMatrix<char*>::setItem(int r, int c, char* value);

/**
 * @brief Specialized method for char*. Method fill matrix with values from array.
 * @param array - values
 */
template<>
void aghMatrix<char*>::setItems(char** array);

/**
 * @brief Specialized method for char. Method set matrix to r rows and c columns and fill with arguments
 * @param r - rows
 * @param c - columns
 */
template<>
void aghMatrix<char>::setItems(int r, int c, ...);

/**
 * @brief Specialized method for char*. Method set matrix to r rows and c columns and fill with arguments
 * @param r - rows
 * @param c - columns
 */
template<>
void aghMatrix<char*>::setItems(int r, int c, ...);

/**
 * @brief Overloaded specialized operator= for char*. Operator assumes matrix.
 * @param pattern - pattern
 * @return constant reference to itself
 */
template<>
aghMatrix<char*> const & aghMatrix<char*>::operator=(aghMatrix<char*> const& pattern);

/**
 * @brief Overloaded specialized operator+ for char. Operator adds two matrices in a-z scope.
 * @param term - term
 * @return sum of two matrices in a-z scope
 */
template<>
const aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> const & term);

/**
 * @brief Overloaded specialized operator+ for char*. Operator adds two matrices filled witch collections.
 * @param term - term
 * @return sum of two matrices
 */
template<>
const aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const & term);

/**
 * @brief Overloaded specialized operator* for char. Operator multiplies two matrices in a-z scope
 * @param factor - factor
 * @return result of matrices multiplication in a-z scope.
 */
template<>
const aghMatrix<char> aghMatrix<char>::operator*(aghMatrix<char> const& factor);

/**
 * @brief Overloaded specialized operator* for char*. Operator multiplies two matrices, where items are collections.
 * @param factor - factor
 * @return result of matrices multiplication, where items are collections
 */
template<>
const aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const & factor);

/**
 * @brief Overloaded specialize operator== for char*. Operator compare two matrices, where items are collections/
 * @param pattern
 * @return true if matrices are identical, otherwise false
 */
template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> & pattern) const;

/**
 * @brief Overloaded specialize operator!= for char*. Operator compare two matrices, where items are collections/
 * @param pattern
 * @return false if matrices are identical, otherwise true
 */
template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*> & pattern) const;

#endif /* AGHMATRIX_H_ */
