/**
 * @file aghSnode_impl.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The implementation of aghSnode template class - node of simple list
 */

#ifndef aghSnode_IMPL_H_
#define aghSnode_IMPL_H_

template<class T> aghSnode<T>::aghSnode(void) {
   setData(T());
   setNext(NULL);
}

template<class T> aghSnode<T>::aghSnode(T const & _data, aghSnode<T>* _next) {
   setData(_data);
   setNext(_next);
}

template<class T> aghSnode<T>::~aghSnode(void) {
}

template<class T> void aghSnode<T>::setData(T const& _data) {
   data = _data;
}

template<class T> T& aghSnode<T>::getData(void) {
   return data;
}

template<class T> void aghSnode<T>::setNext(aghSnode<T>* _next) {
   next = _next;
}

template<class T> aghSnode<T>* aghSnode<T>::getNext(void) const {
   return next;
}

#endif /* AGHSNODE_IMPL_H_ */
