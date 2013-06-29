/**
 * @file aghTree_impl.h
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief File with implementation of aghTree template class, which is BST tree
 */

#ifndef AGHTREE_IMPL_H_
#define AGHTREE_IMPL_H_

template<class T> aghTree<T>::aghTree(void) {
   setRoot (NULL);
   treeSize = 0;
}

template<class T> aghTree<T>::aghTree(aghContainer<T> const& other) {
   root = NULL;
   treeSize = 0;
   this->aghContainer < T > ::operator=(other);
}

template<class T> aghTree<T>::~aghTree(void) {
   if(getRoot())
      this->clear();
}

template<class T> bool aghTree<T>::insert(int placeNumber, T const& object) {
   return insertNode(new aghTnode<T>(object));
}

template<class T> T& aghTree<T>::at(int placeNumber) const {
   return getNode(placeNumber)->getContent();
}

template<class T> int aghTree<T>::size(void) const {
   return treeSize;
}

template<class T> bool aghTree<T>::remove(int placeNumber) {
   if(placeNumber >= size() || placeNumber < 0)
      return false;
   else
      return removeNode(getNode(placeNumber));
}

template<class T> aghTnode<T>* aghTree<T>::getRoot(void) {
   return root;
}

template<class T> void aghTree<T>::setRoot(aghTnode<T>* other) {
   root = other;
}

template<class T> aghTnode<T>* aghTree<T>::getSmallest(aghTnode<T>* actual) const {
   aghTnode < T > *temp = NULL;
   if(actual) {
      temp = actual;
      while(temp->getLchild())
         temp = temp->getLchild();
   }
   return temp;
}

template<class T> aghTnode<T>* aghTree<T>::getLargest(aghTnode<T>* actual) const {
   aghTnode < T > *temp = NULL;
   if(actual) {
      temp = actual;
      while(temp->getRchild())
         temp = temp->getRchild();
   }
   return temp;
}

template<class T> aghTnode<T>* aghTree<T>::getNode(int placeNumber) const {
   aghTnode < T > *result = NULL;
   if(placeNumber >= size() || placeNumber < 0) {
      throw aghException(1, "Index out of range", __FILE__, __LINE__);
   } else {
      aghTnode < T > *temp;
      temp = root;
      int i = -1;
      while(!result) {
         temp = getSmallest(temp);
         if(++i == placeNumber)
            result = temp;
         while(!temp->getRchild() && !result) {
            if(temp != temp->getParent()->getRchild()) {
               temp = temp->getParent();
               if(++i == placeNumber)
                  result = temp;
            } else {
               while(temp->getParent()->getRchild() == temp) {
                  temp = temp->getParent();
               }
               temp = temp->getParent();
               if(++i == placeNumber)
                  result = temp;
            }
         }
         if(!result)
            temp = temp->getRchild();
      }
   }
   return result;
}

template<class T> aghTree<T> const& aghTree<T>::operator=(aghTree<T> const& right) {
   this->aghContainer < T > ::operator=(right);
   return *this;
}

template<class T> bool aghTree<T>::insertNode(aghTnode<T>* node) {
   bool result = true;
   if(!node) {
      result = false;
   } else {
      aghTnode < T > *temp = NULL;
      aghTnode < T > *temp1 = root;

      node->setLchild(NULL);
      node->setRchild(NULL);

      while(temp1) {
         temp = temp1;
         temp1 = node->getContent() < temp1->getContent() ? temp1->getLchild() : temp1->getRchild();
      }

      node->setParent(temp);
      if(!temp)
         root = node;
      else if(node->getContent() < temp->getContent()) {
         temp->setLchild(node);
      } else {
         temp->setRchild(node);
      }
      treeSize++;
   }

   return result;
}

template<class T> bool aghTree<T>::removeNode(aghTnode<T>* removing) {
   aghTnode<T>* temp, *temp1;
   bool result;
   if(!removing) {
      result = false;
   } else {
      if(!removing->getLchild() || !removing->getRchild())
         temp = removing;
      else
         temp = getCons(removing);
      if(temp->getLchild())
         temp1 = temp->getLchild();
      else
         temp1 = temp->getRchild();
      if(temp1)
         temp1->setParent(temp->getParent());
      if(!temp->getParent())
         setRoot(temp1);
      else if(temp == temp->getParent()->getLchild())
         temp->getParent()->setLchild(temp1);
      else
         temp->getParent()->setRchild(temp1);
      if(temp != removing)
         removing->setContent(temp->getContent());
      delete temp;
      treeSize--;
   }
   return result;
}

template<class T> aghTnode<T>* aghTree<T>::getPred(aghTnode<T>* node) {
   aghTnode < T > *result = NULL;
   if(node) {
      if(node->getLchild())
         result = getLargest(node->getLchild());
      else {
         aghTnode < T > *temp;
         result = node;
         do {
            temp = result;
            result = result->getParent();
         } while(result && (result->getRchild() != temp));
      }
   }
   return result;
}

template<class T> aghTnode<T>* aghTree<T>::getCons(aghTnode<T>* node) {
   aghTnode < T > *result = NULL;
   if(node) {
      if(node->getRchild())
         result = getSmallest(node->getRchild());
      else {
         aghTnode < T > *temp;
         result = node;
         do {
            temp = result;
            result = result->getParent();
         } while(result && (result->getLchild() != temp));
      }
   }
   return result;
}

#endif /* AGHTREE_IMPL_H_ */
