/**
 * @file aghTree.h
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief File with definition of aghTree template class, which is BST tree
 */

#ifndef AGHTREE_H_
#define AGHTREE_H_

/**
 * @class aghTree
 * @author Wojciech Kasperek
 * @date 21-05-2013
 * @brief aghTree template class, which is BST tree
 */
template<class T> class aghTree: public aghContainer<T> {
   public:
      /**
       * @brief The default constructor
       */
      aghTree(void);

      /**
       * @brief Copying constructor
       * @param other - other container
       */
      aghTree(aghContainer<T> const &);

      /**
       * @brief Destructor
       */
      virtual ~aghTree();

      /**
       * @brief Inserts object to place
       * @param placeNumber - ignore it
       * @param object - object
       * @return True if operation succeed
       */
      bool insert(int, T const&);

      /**
       * @brief Gets object from given place
       * @param placeNumber - place with object// in order
       * @return Reference to object from given place
       */
      T& at(int) const;

      /**
       * @brief Returns size of container
       * @return Size of container
       */
      int size(void) const;

      /**
       * @brief Removes object from given place
       * @param placeNumber - place to remove
       * @return True if operation succeed
       */
      bool remove(int);

      /**
       * @brief An overloaded operator = for container
       * @param right - other container
       * @return updated container
       */
      aghTree<T> const& operator=(aghTree<T> const&);

   private:
      aghTnode<T>* root; ///tree's root
      int treeSize; ///tree's size

      /**
       * @brief Root's getter
       * @return Rott's indicator
       */
      aghTnode<T>* getRoot(void);

      /**
       * @brief Root's setter
       * @param _other - root
       * @return No value returns
       */
      void setRoot(aghTnode<T>*);

      /**
       * @brief Gets smallest object from actual node
       * @param actual - actual node
       * @return Indicator to smallest
       */
      aghTnode<T>* getSmallest(aghTnode<T>*) const;

      /**
       * @brief Gets largest object from actual node
       * @param actual - actual node
       * @return Indicator to largest
       */
      aghTnode<T>* getLargest(aghTnode<T>*) const;

      /**
       * @brief nth node's getter
       * @param  placeNumber - node's number
       * @return indicator to node
       */
      aghTnode<T>* getNode(int) const;

      /**
       * @brief Inserts node
       * @param node - node to insert
       * @return true if operation succeed
       */
      bool insertNode(aghTnode<T>*);

      /**
       * @brief removes node
       * @param removing - node to remove
       * @return true if operation succeed
       */
      bool removeNode(aghTnode<T>*);

      /**
       * @brief Predecessor getter
       * @param node - actual node
       * @return predecessor
       */
      aghTnode<T>* getPred(aghTnode<T>*);

      /**
       * @brief Consequent getter
       * @param node - actual node
       * @return consequent
       */
      aghTnode<T>* getCons(aghTnode<T>*);

};

#endif /* AGHTREE_H_ */
