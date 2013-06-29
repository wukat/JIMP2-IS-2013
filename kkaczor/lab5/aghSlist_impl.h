/**
 * @file aghSlist_impl.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The implementation of aghSlist template class - a simple list
 */

#ifndef AGHSLIST_IMPL_H_
#define AGHSLIST_IMPL_H_

template<class T> void aghSlist<T>::pushFront(T const& object) {
   aghSnode<T>* temp = new aghSnode<T>(object, head);
   head = temp;
   return;
}

template<class T> void aghSlist<T>::pushToMiddle(int placeNumber, T const & object) {
   if(placeNumber < size() - 1 && placeNumber >= 1) {
      aghSnode<T> * temp;
      temp = getNode(placeNumber - 1);
      temp->setNext(new aghSnode<T>(object, temp->getNext()));
   }
}

template<class T> void aghSlist<T>::pushBack(T const& object) {
   if(head == NULL) {
      head = new aghSnode<T>(object, NULL);
   } else {
      getNode(size() - 1)->setNext(new aghSnode<T>(object, NULL));
   }
}

template<class T> void aghSlist<T>::popFront(void) {
   if(head != NULL) {
      aghSnode<T>* temp = head->getNext();
      delete head;
      head = temp;
   }
}

template<class T> void aghSlist<T>::popFromMiddle(int placeNumber) {
   if(placeNumber < size() - 1 && placeNumber >= 1) {
      aghSnode<T> *temp = getNode(placeNumber);
      getNode(placeNumber - 1)->setNext(temp->getNext());
      delete temp;
   }
}

template<class T> void aghSlist<T>::popBack(void) {
   int listLength = size();
   if(listLength >= 1) {
      if(listLength == 1) {
         popFront();
      } else if(listLength > 1) {
         aghSnode<T>* temp = getNode(listLength - 2);
         delete temp->getNext();
         temp->setNext(NULL);
      }
   }
}

template<class T> void aghSlist<T>::setNode(T const & object, int n) {
   if(n >= size() || n < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      getNode(n)->setData(object);
   }
}

template<class T> aghSnode<T>* aghSlist<T>::getNode(int n) const {
   aghSnode<T>* result = NULL;
   if(n >= size() || n < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      aghSnode<T>* temp = head;
      int i = 0;
      while(i++ < n)
         temp = temp->getNext();
      result = temp;
   }
   return result;
}

template<class T> aghSlist<T>::aghSlist(void) {
   head = NULL;
}

template<class T> aghSlist<T>::aghSlist(aghSlist<T> const & right) {
   head = NULL;
   this->aghContainer<T>::operator =(right);
}

template<class T> aghSlist<T>::aghSlist(aghContainer<T> const & right) {
   head = NULL;
   this->aghContainer<T>::operator =(right);
}

template<class T> aghSlist<T>::~aghSlist(void) {
   if(!this->isEmpty())
      this->clear();
}

template<class T> bool aghSlist<T>::insert(int placeNumber, T const& object) {
   bool result = false;
   if(placeNumber == 0) {
      pushFront(object);
      result = true;
   } else if(placeNumber == size()) {
      pushBack(object);
      result = true;
   } else if(placeNumber < size() && placeNumber > 0) {
      pushToMiddle(placeNumber, object);
      result = true;
   }
   return result;
}

template<class T> T& aghSlist<T>::at(int placeNumber) const {
   return getNode(placeNumber)->getData();
}

template<class T> int aghSlist<T>::size(void) const {
   int counter = 0;
   aghSnode<T>* temp = head;
   while(temp != NULL) {
      counter++;
      temp = temp->getNext();
   }
   return counter;
}

template<class T> bool aghSlist<T>::remove(int placeNumber) {
   bool result = false;
   if(placeNumber == 0) {
      popFront();
      result = true;
   } else if(placeNumber == size() - 1) {
      popBack();
      result = true;
   } else if(placeNumber < size() - 1 && placeNumber > 0) {
      popFromMiddle(placeNumber);
      result = true;
   }
   return result;
}

template<class T> aghSlist<T>& aghSlist<T>::operator=(aghSlist<T> const & right) {
   this->aghContainer<T>::operator=(right);
   return *this;
}

#endif /* AGHSLIST_IMPL_H_ */
