/**
 * @file aghSlist.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghSlist template class - a simple list
 */

#ifndef AGHSLIST_H_
#define AGHSLIST_H_

template<class T> class aghSnode;
/**
 * @file aghSlist
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghSlist template class - a simple list
 */
template<class T> class aghSlist: public aghContainer<T> {
   public:

      /**
       * @brief Constructor
       */
      aghSlist(void);

      /**
       * @brief Parametric constructor
       * @param _right - other list
       */
      aghSlist(aghContainer<T> const &);

      /**
       * @brief Copying constructor
       * @param _right - other list
       */
      aghSlist(aghSlist<T> const &);

      /**
       * @brief Destructor
       */
      virtual ~aghSlist(void);

      /**
       * @brief Inserts object to place
       * @param placeNumber - place to insert
       * @param object - object
       * @return True if operation succeed
       */
      bool insert(int, T const&);

      /**
       * @brief Gets object from given place
       * @param placeNumber - place with object
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
       * @brief An overloaded operator = for list
       * @param right - other list
       * @return updated list
       */
      aghSlist<T>& operator=(aghSlist<T> const &);

   private:

      aghSnode<T>* head; /// beginning of the list

      /**
       * @brief Push new node to front
       * @param object - value
       * @return No value returns
       */
      virtual void pushFront(T const &);

      /**
       * @brief Insert node to place in the middle
       * @param placeNumber - place to delete node
       * @param object - value to insert
       * @return No value returns
       */
      virtual void pushToMiddle(int, T const&);

      /**
       * @brief Push new node to the end
       * @param object - value
       * @return No value returns
       */
      virtual void pushBack(T const &);

      /**
       * @brief Deletes node from beginning
       * @return No value returns
       */
      virtual void popFront(void);

      /**
       * @brief Deletes node from place in the middle
       * @param placeNumber - place to delete node
       * @return No value returns
       */
      virtual void popFromMiddle(int);

      /**
       * @brief Deletes node from the end
       * @return No value returns
       */
      virtual void popBack(void);

      /**
       * @brief Sets the value of nth node
       * @param object - value
       * @param n - number of node
       * @return No value returns
       */
      virtual void setNode(T const&, int);

      /**
       * @brief Gets nth node
       * @param n - number of node
       * @return Node's indicator
       */
      virtual aghSnode<T>* getNode(int) const;
};

#endif /* AGHSLIST_H_ */
