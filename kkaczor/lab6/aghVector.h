/**
 * @file aghVector.h
 * @author Marcin Lachowicz
 * @date 15-05-2013
 * @brief Header file for aghVector class
 */

#ifndef AGHVECTOR_H_
#define AGHVECTOR_H_

#include "aghContainer.h"

/**
 * @brief Declaration of aghVector class. Class represents vector.
 * @date 15-05-2013
 * @author Marcin Lachowicz
 * @class aghVector
 */
template<class T>
class aghVector: public aghContainer<T> {
   public:
      /**
       * @brief Default constructor
       */
      aghVector();

      /**
       * @brief Copy constructor
       * @param other - object to copy
       */
      aghVector(aghVector<T> const & other);

      /**
       * @brief Parametric constructor
       * @param other - pattern object
       */
      aghVector(aghContainer<T> const & other);

      /**
       * @brief Default destructor
       */
      virtual ~aghVector();

      /**
       * @brief Memory step setter
       * @param _memoryStep - memory step. > 0
       */
      void setMemoryStep(int _memoryStep);

      /**
       * @brief Memory step getter
       * @return size of memory step
       */
      int getMemoryStep() const;

      /**
       * @ Memory size getter
       * @return size of memory
       */
      int getMemorySize() const;

      /**
       * @brief Free memory size getter
       * @return Free memory size
       */
      int getFreeMemorySize() const;

      /**
       * @brief Returns size of container
       * @return Size of container
       */
      int size() const;

      /**
       * @brief Method inserts object to vector
       * @param _index - index. < size()+1
       * @param _object  - object
       * @return - true on success
       */
      bool insert(int _index, T const & _object);

      /**
       * @brief Gets object at_index
       * @param _index - index
       * @return Reference to object at _index
       */
      T& at(int _index) const;

      /**
       * @brief Removes object at _index
       * @param _index - index
       * @return True on success
       */
      bool remove(int _index);

      /**
       * @brief Assignment operator
       * @param other - pattern
       * @return Constant reference to itself
       */
      aghVector<T> const & operator=(aghVector const & other);

   private:
      int memoryStep; ///< Step of memory size. Default 10
      int elementsCount; ///< Number of elements in vector
      int memorySize; ///< Size of allocated memory
      T* memory; ///< Pointer to memory

      /**
       * @brief Method reallocates memory for vector and copies old elements to new vector. Possible loss of data.
       * @param _size - size of new vector. >= 0
       */
      void realloc(int _size);

      /**
       * @brief Method enlarges memory
       */
      void enlargeMemory();

      /**
       * @brief Method reduces memory. Possible loss of data.
       */
      void reduceMemory();

      /**
       * @brief Method frees memory and set memory pointer to NULL.
       */
      void freeMemory();


};

#endif /* AGHVECTOR_H_ */
