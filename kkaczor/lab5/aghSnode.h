/**
 * @file aghSnode.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghSnode template class - node of simple list
 */

#ifndef AGHSNODE_H_
#define AGHSNODE_H_

/**
 * @file aghSnode
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghSnode template class - node of simple list
 */
template<class T> class aghSnode {
   public:

      /**
       * @brief The default constructor
       */
      aghSnode(void);

      /**
       * @brief Constructor
       * @param _data - node data
       * @param _next - next node
       */
      aghSnode(T const &, aghSnode<T>* = NULL);

      /**
       * @brief Destructor
       */
      virtual ~aghSnode(void);

      /**
       * @brief Data setter
       * @param _data - node data
       * @return No value returns
       */
      void setData(T const &);

      /**
       * @brief Data getter
       * @return Reference to node's data
       */
      T& getData(void);

      /**
       * @brief Next node setter
       * @param _next - next node
       */
      virtual void setNext(aghSnode<T>*);

      /**
       * @brief Nodes getter
       * @return Indicator to next node
       */
      virtual aghSnode<T>* getNext(void) const;

   protected:
      T data; /// node's data

   private:
      aghSnode* next; /// indicator to next node

};

#endif /* AGHSNODE_H_ */
