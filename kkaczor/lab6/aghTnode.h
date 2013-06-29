/**
 * @file aghTnode.h
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief File with definition of aghTnode template class, which is node of BST tree
 */

#ifndef AGHTNODE_H_
#define AGHTNODE_H_

/**
 * @class aghTnode
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief aghTnode template class, which is node of BST tree
 */
template<class T> class aghTnode {
   public:
      /**
       * @brief The default constructor
       */
      aghTnode(void);

      /**
       * @brief Parameter constructor
       * @param _content - value
       * @param _lchild - left child
       * @param _rchild - right child
       * @param _parent - parent
       */
      aghTnode(T, aghTnode<T>* = NULL, aghTnode<T>* = NULL, aghTnode<T>* = NULL);

      /**
       * @brief Destructor
       */
      virtual ~aghTnode(void);

      /**
       * @brief Node's setter
       * @param _content - value
       * @param _lchild - left child
       * @param _rchild - right child
       * @param _parent - parent
       * @return No value returns
       */
      void setNode(T, aghTnode<T>* = NULL, aghTnode<T>* = NULL, aghTnode<T>* = NULL);

      /**
       * @brief Content getter
       * @return Reference to content
       */
      T& getContent(void);

      /**
       * @brief Content setter
       * @param content - value
       * @return No value returns
       */
      void setContent(T);

      /**
       * @brief Left child getter
       * @return Reference to indicator to left child
       */
      aghTnode<T>* getLchild(void) const;

      /**
       * @brief Left child setter
       * @param lchild - value
       * @return No values returns
       */
      void setLchild(aghTnode<T>*);

      /**
       * @brief Parent getter
       * @return Reference to indicator to parent
       */
      aghTnode<T>* getParent(void) const;

      /**
       * @brief Parent setter
       * @param parent - value
       * @return No values returns
       */
      void setParent(aghTnode<T>*);

      /**
       * @brief Right child getter
       * @return Reference to indicator to right child
       */
      aghTnode<T>* getRchild(void) const;

      /**
       * @brief Right child setter
       * @param rchild - value
       * @return No values returns sx
       */
      void setRchild(aghTnode<T>*);

   private:
      aghTnode<T>* parent; ///indicator to parent
      aghTnode<T>* lchild; ///indicator to left child
      aghTnode<T>* rchild; ///indicator to right child
      T content; ///contained value
};

#endif /* AGHTNODE_H_ */
