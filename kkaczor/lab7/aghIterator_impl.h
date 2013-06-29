/**
 * @file aghIterator_impl.h
 * @author Marcin Lachowicz
 * @date 25-05-2013
 * @brief
 */

#ifndef AGHITERATOR_IMPL_H_
#define AGHITERATOR_IMPL_H_

template<class T>
aghIterator<T>::aghIterator(aghContainer<T>* ptr, int _index) {
   container = ptr;
   currentIndex = _index;
}

template<class T>
aghIterator<T>::~aghIterator() {

}

template<class T>
aghIterator<T>::operator int() const {
   int result = 0;
   if(container == NULL) {
      result = 1;
   } else if(container->isEmpty()) {
      result = 1;
   } else if((currentIndex < 0) || (currentIndex >= container->size())) {
      result = 1;
   }
   return !result;
}

template<class T>
aghIterator<T> aghIterator<T>::first() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else {
      return aghIterator(container, 0);
   }
}

template<class T>
aghIterator<T> aghIterator<T>::last() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else {
      return aghIterator(container, container->size() - 1);
   }
}

template<class T>
aghIterator<T>& aghIterator<T>::next() {
   currentIndex++;
   return *this;
}

template<class T>
aghIterator<T>& aghIterator<T>::prev() {
   currentIndex--;
   return *this;
}

template<class T>
T& aghIterator<T>::current() const {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else if((currentIndex < 0) || (currentIndex >= container->size())) {
      throw aghException(3, "Index out of range", __FILE__, __LINE__);
   } else {
      return container->at(currentIndex);
   }
}

template<class T>
aghIterator<T>& aghIterator<T>::atFirst() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else {
      currentIndex = 0;
   }
   return *this;
}

template<class T>
aghIterator<T>& aghIterator<T>::atLast() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else {
      currentIndex = container->size() - 1;
   }
   return *this;
}

template<class T>
int aghIterator<T>::size() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else {
      return container->size() - currentIndex;
   }
}
template<class T>
aghIterator<T> const & aghIterator<T>::operator=(aghContainer<T> * _container) {
   if(_container == NULL) {
      throw aghException(2, "NULL pointer passed to method", __FILE__, __LINE__);
   } else {
      container = _container;
      currentIndex = 0;
   }
   return *this;
}

template<class T>
T& aghIterator<T>::operator *() {
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else if((currentIndex < 0) || (currentIndex >= container->size())) {
      throw aghException(3, "Index out of range", __FILE__, __LINE__);
   } else {
      return container->at(currentIndex);
   }
}

template<class T>
T& aghIterator<T>::operator [](int _d) {
   int newIndex = currentIndex + _d;
   if(container->isEmpty()) {
      throw aghException(0, "Container is empty", __FILE__, __LINE__);
   } else if((newIndex < 0) || (newIndex >= container->size())) {
      throw aghException(3, "Index out of range", __FILE__, __LINE__);
   } else {
      return container->at(newIndex);
   }
}

template<class T>
aghIterator<T> aghIterator<T>::operator +(int _d) {
   return aghIterator<T>(container, currentIndex + _d);
}

template<class T>
void aghIterator<T>::operator +=(int _d) {
   currentIndex += _d;
}

template<class T>
aghIterator<T> aghIterator<T>::operator -(int _d) {
   return *this + (-_d);
}

template<class T>
void aghIterator<T>::operator -=(int _d) {
   *this += (-_d);
}

template<class T>
aghIterator<T> aghIterator<T>::operator ++(int) {
   aghIterator temp = *this;
   ++(*this);
   return temp;
}

template<class T>
aghIterator<T> aghIterator<T>::operator ++() {
   this->next();
   return *this;
}

template<class T>
aghIterator<T> aghIterator<T>::operator --(int) {
   aghIterator temp = *this;
   --(*this);
   return temp;
}

template<class T>
aghIterator<T> aghIterator<T>::operator --() {
   this->prev();
   return *this;
}

template<class T>
bool aghIterator<T>::operator ==(aghIterator<T> const & other) {
   return (this->current() == other.current());
}

template<class T>
bool aghIterator<T>::operator !=(aghIterator<T> const & other) {
   return !(*this == other);
}

#endif  /*AGHITERATOR_IMPL_H_*/

