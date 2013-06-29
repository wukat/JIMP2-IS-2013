/**
 * @file aghDnode.h
 * @author Wojciech Kasperek
 * @date 18-05-2013
 * @brief The definition of aghDnode template class - node of double list
 */

#ifndef AGHDNODE_H_
#define AGHDNODE_H_

/**
 * @file aghDnode
 * @author Wojciech Kasperek
 * @date 18-05-2013
 * @brief The definition of aghDnode template class - node of double list
 */
template<class T> class aghDnode : public aghSnode<T> {
   public:

      /**
       * @brief The default constructor
       */
      aghDnode(void);

      /**
       * @brief Constructor
       * @param _data - node data
       * @param _next - next node
       * @param _prev - previous node
       */
      aghDnode(T const &, aghDnode<T>* = NULL, aghDnode<T>* = NULL);

      /**
       * @brief Destructor
       */
      virtual ~aghDnode(void);

      /**
       * @brief Next node setter
       * @param _next - next node
       */
      void setNext(aghDnode<T>*);

      /**
       * @brief Nodes getter
       * @return Indicator to next node
       */
      aghDnode<T>* getNext(void) const;

      /**
       * @brief Previous node setter
       * @param _prev - previous node
       */
      void setPrev(aghDnode<T>*);

      /**
       * @brief Nodes getter
       * @return Indicator to previous node
       */
      aghDnode<T>* getPrev(void) const;

   private:
      aghDnode<T>* next; /// indicator to next node
      aghDnode<T>* prev; /// indicator to previous node
};

#endif /* AGHDNODE_H_ */
