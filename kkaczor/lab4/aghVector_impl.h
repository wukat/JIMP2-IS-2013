/**
 * @file aghVector_impl.h
 * @author Marcin Lachowicz
 * @date 15-05-2013
 * @brief Implementation header file for aghVector class
 */

#ifndef AGHVECTOR_IMPL_H_
#define AGHVECTOR_IMPL_H_

template<class T>
aghVector<T>::aghVector() {
   memory = NULL;
   memorySize = 0;
   elementsCount = 0;
   setMemoryStep(10);
   realloc(getMemoryStep());
}

template<class T>
aghVector<T>::aghVector(aghVector<T> const & other) {
   memory = NULL;
   memorySize = 0;
   elementsCount = 0;
   setMemoryStep(10);

   this->aghContainer<T>::operator =(other);
}

template<class T>
aghVector<T>::aghVector(aghContainer<T> const & other) {
   memory = NULL;
   memorySize = 0;
   elementsCount = 0;
   setMemoryStep(10);

   this->aghContainer<T>::operator =(other);
}

template<class T>
aghVector<T>::~aghVector() {
   freeMemory();
}

template<class T>
void aghVector<T>::setMemoryStep(int _memoryStep) {
   if(_memoryStep < 1) {
      throw aghException(11, "Incorrect value", __FILE__, __LINE__);
   } else {
      memoryStep = _memoryStep;
   }
}

template<class T>
int aghVector<T>::getMemoryStep() const {
   return memoryStep;
}

template<class T>
int aghVector<T>::getMemorySize() const {
   return memorySize;
}

template<class T>
int aghVector<T>::getFreeMemorySize() const {
   return memorySize - size();
}

template<class T>
int aghVector<T>::size() const {
   return elementsCount;
}

template<class T>
bool aghVector<T>::insert(int _index, T const & _object) {
   int flag = false;

   if((_index >= 0) && (_index <= size())) {
      if(getFreeMemorySize() == 0) { // check if vector is not full
         enlargeMemory();
      }

      // move elements after _index
      for(int i = elementsCount; i > _index; i--) {
         memory[i] = memory[i - 1];
      }

      memory[_index] = _object;
      elementsCount++;

      flag = true;
   }

   return flag;
}

template<class T>
T& aghVector<T>::at(int _index) const {
   if((_index < 0) || (_index >= size())) {
      throw aghException(12, "Index out of range", __FILE__, __LINE__);
   } else {
      return memory[_index];
   }
}

template<class T>
bool aghVector<T>::remove(int _index) {
   int flag = false;

   if((_index >= 0) && (_index <= size())) {
      if(size() > 0) {
         // move elements after _index
         for(int i = _index; i < size() - 1; i++) {
            memory[i] = memory[i + 1];
         }
         memory[size() - 1].~T();
         elementsCount--;

         if(getFreeMemorySize() > getMemoryStep()) { // free unused memory
            reduceMemory();
         }

         flag = true;
      }
   }
   return flag;
}

template<class T>
aghVector<T> const & aghVector<T>::operator=(aghVector<T> const & other) {
   this->aghContainer<T>::operator =(other);
   return *this;
}

template<class T>
void aghVector<T>::realloc(int _size) {
   if(_size < 0) {
      throw aghException(10, "Bad memory allocation", __FILE__, __LINE__);
   } else {
      T* temp = new T[_size];

      for(int i = 0; i < _size && i < size(); i++) { // copy elements
         temp[i] = memory[i];
      }

      freeMemory(); // if memory is already allocated - delete it

      elementsCount = size() < _size ? size() : _size;
      memorySize = _size;
      memory = temp;
   }
}

template<class T>
void aghVector<T>::enlargeMemory() {
   realloc(getMemorySize() + getMemoryStep());
}

template<class T>
void aghVector<T>::reduceMemory() {
   realloc(getMemorySize() - getMemoryStep());
}

template<class T>
void aghVector<T>::freeMemory() {
   if(memory != NULL) {
      delete[] memory;
      memory = NULL;
   }
}

#endif /* AGHVECTOR_IMPL_H_ */
