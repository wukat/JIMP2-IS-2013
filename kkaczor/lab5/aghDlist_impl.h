/**
 * @file aghDlist_impl.h
 * @author Wojciech Kasperek
 * @date 18-05-2013
 * @brief The implementation of aghDlist template class - a double list
 */

#ifndef AGHDLIST_IMPL_H_
#define AGHDLIST_IMPL_H_

template<class T> void aghDlist<T>::pushFront(T const& object) {
   aghDnode<T>* temp = new aghDnode<T>(object, head);
   if(head == NULL)
      tail = temp;
   else
      head->setPrev(temp);
   head = temp;
}

template<class T> void aghDlist<T>::pushToMiddle(int placeNumber, T const & object) {
   if(placeNumber >= 0 && placeNumber < size()) {
      aghDnode<T> * temp;
      temp = getNode(placeNumber - 1);
      temp->setNext(new aghDnode<T>(object, temp->getNext(), temp));
      temp->getNext()->getNext()->setPrev(temp->getNext());
   }
}

template<class T> void aghDlist<T>::pushBack(T const& object) {
   if(head == NULL) {
      head = new aghDnode<T>(object);
      tail = head;
   } else {
      tail->setNext(new aghDnode<T>(object, NULL, tail));
      tail = tail->getNext();
   }
}

template<class T> void aghDlist<T>::popFront(void) {
   if(head != NULL) {
      if(tail == head) {
         tail = NULL;
         delete head;
         head = NULL;
      } else {
         aghDnode<T> *temp = head->getNext();
         temp->setPrev(NULL);
         head = temp;
      }
   }
}

template<class T> void aghDlist<T>::popFromMiddle(int placeNumber) {
   if(placeNumber < size() - 1 && placeNumber >= 1) {
      aghDnode<T> * temp = getNode(placeNumber);
      temp->getPrev()->setNext(temp->getNext());
      temp->getNext()->setPrev(temp->getPrev());
      delete temp;
   }
}

template<class T> void aghDlist<T>::popBack(void) {
   if(tail != NULL) {
      if(tail == head) {
         head = NULL;
         delete tail;
         tail = NULL;
      } else {
         aghDnode<T>* temp = tail->getPrev();
         temp->setNext(NULL);
         delete tail;
         tail = temp;
      }
   }
}

template<class T> void aghDlist<T>::setNode(T const & object, int n) {
   if(n >= size() || n < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      getNode(n)->setData(object);
   }
   return;
}

template<class T> aghDnode<T>* aghDlist<T>::getNode(int n) const {
   aghDnode<T>* result = NULL;
   if(n >= size() || n < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      aghDnode<T>* temp = head;
      int i = 0;
      while(i++ < n)
         temp = temp->getNext();
      result = temp;
   }
   return result;
}

template<class T> aghDlist<T>::aghDlist(void) {
   head = NULL;
   tail = NULL;
}

template<class T> aghDlist<T>::aghDlist(aghDlist<T> const & right) {
   head = NULL;
   tail = NULL;
   this->aghContainer<T>::operator =(right);
}

template<class T> aghDlist<T>::aghDlist(aghContainer<T> const & right) {
   head = NULL;
   tail = NULL;
   this->aghContainer<T>::operator =(right);
}

template<class T> aghDlist<T>::~aghDlist(void) {
   if(!this->isEmpty())
      this->clear();
}

template<class T> int aghDlist<T>::size(void) const {
   int counter = 0;
   aghDnode<T>* temp = head;
   while(temp != NULL) {
      counter++;
      temp = temp->getNext();
   }
   return counter;
}

template<class T> aghDlist<T>& aghDlist<T>::operator=(aghDlist<T> const & right) {
   this->aghContainer<T>::operator=(right);
   return *this;
}

#endif /* AGHDLIST_IMPL_H_ */
