/**
 * @file aghIterator.h
 * @author Marcin Lachowicz
 * @date 25-05-2013
 * @brief Header file of aghIterator
 */

#ifndef AGHITERATOR_H_
#define AGHITERATOR_H_

//#include "aghContainer.h"
/**
 * @brief Declaration of aghIterator class.
 * @author Marcin Lachowicz
 * @date 25-05-2013
 * @class aghIterator
 */

template<class T>
class aghIterator {
   public:

      /**
       * @brief Parametric constructor.
       * @param ptr - pointer to container.
       * @param _index - current index.
       */

      aghIterator(aghContainer<T>* ptr, int _index = 0);

      /**
       * @brief Default destructor
       */

      virtual ~aghIterator();

      /**
       * @brief
       * @return Iterator pointing to first element.
       */
      aghIterator<T> first();

      operator int() const;

      /**
       *
       * @return Iterator pointing to last element.
       */
      aghIterator<T> last();

      /**
       * @brief Moves iterator to next element.
       * @return Reference to itself.
       */
      aghIterator<T>& next();

      /**
       * @brief Moves iterator to previous element.
       * @brief Reference to itself.
       */
      aghIterator<T>& prev();

      /**
       * @brief Gets current object from container.
       * @return Reference to current object.
       */
      T& current() const;

      /**
       * @brief Moves iterator to first element.
       */
      aghIterator<T>& atFirst();

      /**
       * @brief Moves iterator to last element.
       */
      aghIterator<T>& atLast();

      /**
       *
       * @return Number of element between current position and last element.
       */
      int size();

      /**
       * @brief Method sets current iterator.
       * @param _container - pointer to container.
       * @return Constant reference to itself.
       */
      aghIterator<T> const & operator=(aghContainer<T> * _container);

      /**
       * @brief Operator gets current element.
       * @return Reference to current element.
       */
      T& operator*();

      /**
       * @brief Operator gets element _d beyond current.
       * @param _d - difference
       * @return Reference to element
       */
      T& operator[](int _d);

      /**
       * @brief Method gets iterator pointing to _d element beyond current.
       * @param _d - difference
       * @return - aghIterator
       */
      aghIterator<T> operator+(int _d);

      /**
       * @brief Moves iterator on _d element beyond current.
       * @param _d - difference
       */
      void operator+=(int _d);

      /**
       * @brief Method gets iterator pointing to _d element before current.
       * @param _d - difference
       * @return - aghIterator
       */
      aghIterator<T> operator-(int _d);

      /**
       * @brief Moves iterator on _d element before current.
       * @param _d - difference
       */
      void operator-=(int _d);

      /**
       * @brief Post incrementation operator.
       * @param
       * @return Reference to itself
       */
      aghIterator<T> operator++(int);

      /**
       * @brief Pre incrementation operator.
       * @return Reference to itself.
       */
      aghIterator<T> operator++();

      /**
       * @brief Pre incrementation operator.
       * @param
       * @return Reference to itself
       */
      aghIterator<T> operator--(int);

      /**
       * @brief Pre incrementation operator.
       * @param
       * @return Reference to itself
       */
      aghIterator<T> operator--();

      /**
       * @brief Overloaded comparison operator.
       * @param other - pattern.
       * @return True if iterators are pointing to the same arguments.
       */
      bool operator==(aghIterator<T> const & other);

      /**
       * @brief Overloaded comparison operator.
       * @param other - pattern.
       * @return False if iterators are pointing to the same arguments.
       */
      bool operator!=(aghIterator<T> const & other);

   private:
      aghContainer<T>* container;
      int currentIndex;
};

#endif  /* AGHITERATOR_H_*/

