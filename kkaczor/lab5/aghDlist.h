/**
 * @file aghDlist.h
 * @author Wojciech Kasperek
 * @date 18-05-2013
 * @brief The definition of aghDlist template class - a double list
 */

#ifndef AGHDLIST_H_
#define AGHDLIST_H_

/**
 * @file aghDlist
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghDlist template class - a double list
 */
template<class T> class aghDlist: public aghSlist<T> {
   public:

      /**
       * @brief Constructor
       */
      aghDlist(void);

      /**
       * @brief Copying constructor
       * @param _right - other list
       */
      aghDlist(aghDlist<T> const &);

      /**
       * @brief Parametric constructor
       * @param _right - other list
       */
      aghDlist(aghContainer<T> const &);

      /**
       * @brief Destructor
       */
      virtual ~aghDlist(void);

      /**
       * @brief Returns size of container
       * @return Size of container
       */
      int size(void) const;

      /**
       * @brief An overloaded operator = for list
       * @param right - other list
       * @return updated list
       */
      aghDlist<T>& operator=(aghDlist<T> const &);

   private:

      aghDnode<T>* head; /// beginning of the list
      aghDnode<T>* tail; /// end of the list

      /**
       * @brief Push new node to front
       * @param object - value
       * @return No value returns
       */
      void pushFront(T const &);

      /**
       * @brief Insert node to place in the middle
       * @param placeNumber - place to delete node
       * @param object - value to insert
       * @return No value returns
       */
      void pushToMiddle(int, T const&);

      /**
       * @brief Push new node to the end
       * @param object - value
       * @return No value returns
       */
      void pushBack(T const &);

      /**
       * @brief Deletes node from beginning
       * @return No value returns
       */
      void popFront(void);

      /**
       * @brief Deletes node from place in the middle
       * @param placeNumber - place to delete node
       * @return No value returns
       */
      void popFromMiddle(int);

      /**
       * @brief Deletes node from the end
       * @return No value returns
       */
      void popBack(void);

      /**
       * @brief Sets the value of nth node
       * @param object - value
       * @param n - number of node
       * @return No value returns
       */
      void setNode(T const&, int);

      /**
       * @brief Gets nth node
       * @param n - number of node
       * @return Node's indicator
       */
      aghDnode<T>* getNode(int) const;
};

#endif /* AGHDLIST_H_ */

