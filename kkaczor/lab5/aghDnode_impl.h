/**
 * @file aghDnode_impl.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The implementation of aghDnode template class - node of double list
 */

#ifndef aghDnode_IMPL_H_
#define aghDnode_IMPL_H_

template<class T> aghDnode<T>::aghDnode(void) {
   setNext(NULL);
   setPrev(NULL);
   this->setData(T());
}

template<class T> aghDnode<T>::aghDnode(T const & _data, aghDnode<T>* _next, aghDnode<T>* _prev) {
   setNext(_next);
   setPrev(_prev);
   this->setData(_data);
}

template<class T> aghDnode<T>::~aghDnode(void) {
}

template<class T> void aghDnode<T>::setNext(aghDnode<T>* _next) {
   next = _next;
}

template<class T> aghDnode<T>* aghDnode<T>::getNext(void) const {
   return next;
}

template<class T> void aghDnode<T>::setPrev(aghDnode<T>* _prev) {
   prev = _prev;
}

template<class T> aghDnode<T>* aghDnode<T>::getPrev(void) const {
   return prev;
}

#endif /* AGHDNODE_IMPL_H_ */

