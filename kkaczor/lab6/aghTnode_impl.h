/**
 * @file aghTnode_impl.h
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief File with an implementation of aghTnode template class, which is node of BST tree
 */

#ifndef AGHTNODE_IMPL_H_
#define AGHTNODE_IMPL_H_

template<class T> aghTnode<T>::aghTnode(void) {
   setNode(T());
}
template<class T> aghTnode<T>::aghTnode(T _content, aghTnode<T>* _lchild, aghTnode<T>* _rchild, aghTnode<T>* _parent) {
   setNode(_content, _lchild, _rchild, _parent);
}

template<class T> aghTnode<T>::~aghTnode(void) {
   setLchild(NULL);
   setRchild(NULL);
   setParent(NULL);
   this->content.~T();
}

template<class T> void aghTnode<T>::setNode(T _content, aghTnode<T>* _lchild, aghTnode<T>* _rchild,
      aghTnode<T>* _parent) {
   setContent(_content);
   setLchild(_lchild);
   setRchild(_rchild);
   setParent(_parent);
}

template<class T> T& aghTnode<T>::getContent() {
   return content;
}

template<class T> void aghTnode<T>::setContent(T content) {
   this->content = content;
}

template<class T> aghTnode<T>* aghTnode<T>::getLchild(void) const {
   return lchild;
}

template<class T> void aghTnode<T>::setLchild(aghTnode<T>* lchild) {
   if(lchild != NULL && (lchild == parent || lchild == rchild)) {
      throw aghException(2, "Wrong indicators given", __FILE__, __LINE__);
   } else {
      this->lchild = lchild;
   }
}

template<class T> aghTnode<T>* aghTnode<T>::getParent(void) const {
   return parent;
}

template<class T> void aghTnode<T>::setParent(aghTnode<T>* parent) {
   if(parent != NULL && (parent == lchild || parent == rchild)) {
      throw aghException(2, "Wrong indicators given", __FILE__, __LINE__);
   } else {
      this->parent = parent;
   }
}

template<class T> aghTnode<T>* aghTnode<T>::getRchild(void) const {
   return rchild;
}

template<class T> void aghTnode<T>::setRchild(aghTnode<T>* rchild) {
   if(rchild != NULL && (rchild == parent || rchild == lchild)) {
      throw aghException(2, "Wrong indicators given", __FILE__, __LINE__);
   } else {
      this->rchild = rchild;
   }
}

#endif /* AGHTNODE_IMPL_H_ */
