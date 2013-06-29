/**
 * @file aghContainer_impl.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The implementation of template aghContainer class' methods.
 */

#ifndef AGHCONTAINER_IMPL_H_
#define AGHCONTAINER_IMPL_H_

template<class T> aghContainer<T>::aghContainer(void) {
}

template<class T> aghContainer<T>::~aghContainer() {
}

template<class T> void aghContainer<T>::append(T const & object) {
   if(!insert(size(), object)) {
      throw aghException(0, "Operation failed", __FILE__, __LINE__);
   }
}

template<class T> bool aghContainer<T>::replace(int placeNumber, T const & object) {
   bool result = false;
   if(placeNumber >= 0 && placeNumber < size()) {
      result = remove(placeNumber);
      if(result)
         result = insert(placeNumber, object);
   }
   return result;
}

template<class T> void aghContainer<T>::clear(void) {
   int length = size();
   for(int i = length - 1; i >= 0; i--)
      remove(i);
}

template<class T> bool aghContainer<T>::isEmpty(void) const {
   return (size() <= 0);
}

template<class T> int aghContainer<T>::indexOf(T const & _value, int _from) const {
   int result = -1;
   if(_from >= size() || _from < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      for(int i = _from; i < size() && result == -1; i++)
         if(_value == at(i))
            result = i;
   }
   return result;
}

template<class T> bool aghContainer<T>::contains(T const & _value, int _from) const {
   bool result = false;
   if(_from >= size() || _from < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      for(int i = _from; i < size() && !result; i++)
         if(_value == at(i))
            result = true;
   }
   return result;
}

template<class T> aghContainer<T> const & aghContainer<T>::operator=(aghContainer<T> const & other) {
   if(this != &other) {
      if(!this->isEmpty())
         this->clear();
      *this += other;
   }
   return *this;
}

template<class T> bool aghContainer<T>::operator==(aghContainer<T> const& right) const {
   bool result = false;
   if((result = (size() == right.size())))
      for(int i = 0; i < size() && result; i++)
         result = (right.at(i) == at(i));
   return result;
}

template<class T> bool aghContainer<T>::operator!=(aghContainer<T> const& right) const {
   return !(*this == right);
}

template<class T> T& aghContainer<T>::operator[](int n) const {
   if(n >= size() || n < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      return at(n);
   }
}

template<class T> aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right) {
   int length = right.size();
   for(int i = 0; i < length; i++) {
      append(right.at(i));
   }
   return *this;
}

template<class T> aghContainer<T>& aghContainer<T>::operator+=(T const& element) {
   append(element);
   return *this;
}

template<class T> aghContainer<T>& aghContainer<T>::operator<<(T const& element) {
   return *this += element;
}

template<class T> aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right) {
   return *this += right;
}

template<class U> ostream& operator<<(ostream& stream, aghContainer<U> const& right) {
   for(int i = 0; i < right.size(); i++) {
      stream << right[i];
      stream << endl;
   }
   return stream;
}

#endif /* AGHCONTAINER_IMPL_H_ */
