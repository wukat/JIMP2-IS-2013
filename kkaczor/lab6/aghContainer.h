/**
 * @file aghContainer.h
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghContainer template abstract class that allows making any type containers.
 */

#ifndef AGHCONTAINER_H_
#define AGHCONTAINER_H_

/**
 * @file aghContainer
 * @author Wojciech Kasperek
 * @date 15-05-2013
 * @brief The definition of aghContainer template abstract class that allows making any type containers.
 */
template<class T> class aghContainer {
   public:
      /**
       * @brief Constructor
       */
      aghContainer(void);

      /**
       * @brief Destructor
       */
      virtual ~aghContainer(void);

      /**
       * @brief Adds object to container
       * @param object - object
       * @return No value returns
       */
      void append(T const&);

      /**
       * @brief Inserts object to place
       * @param placeNumber - place to insert
       * @param object - object
       * @return True if operation succeed
       */
      virtual bool insert(int, T const&) = 0;

      /**
       * @brief Replace nth object with given
       * @param placeNumber - place to replace
       * @param object - object
       * @return True if operation succeed
       */
      bool replace(int, T const&);

      /**
       * @brief Gets object from given place
       * @param placeNumber - place with object
       * @return Reference to object from given place
       */
      virtual T& at(int) const = 0;

      /**
       * @brief Returns size of container
       * @return Size of container
       */
      virtual int size(void) const = 0;

      /**
       * @brief Removes object from given place
       * @param placeNumber - place to remove
       * @return True if operation succeed
       */
      virtual bool remove(int) = 0;

      /**
       * @brief Clears container
       * @return No value returns
       */
      void clear(void);

      /**
       * @brief Check if the container if empty
       * @return True if container if empty
       */
      bool isEmpty(void) const;

      /**
       * @brief Try to find given object from given place
       * @param _value - object to find
       * @param _from - place to start searching
       * @return Number of place on which is searched object
       */
      int indexOf(T const&, int = 0) const;

      /**
       * @brief Checks if container contains given value
       * @param _value - object to check
       * @param _from - place to start searching
       * @return  True if object is in container further than _from
       */
      bool contains(T const&, int = 0) const;

      /**
       * @brief An overloaded operator = for container
       * @param right - other container
       * @return updated container
       */
      aghContainer<T> const & operator=(aghContainer<T> const &);

      /**
       * @brief An overloaded operator == which checks if contents are same
       * @param right - other container
       * @return True if contents are same
       */
      bool operator==(aghContainer<T> const&) const;

      /**
       * @brief An overloaded operator != which checks if contents are not same
       * @param right - other container
       * @return True if contents are not same
       */
      bool operator!=(aghContainer<T> const&) const;

      /**
       * @brief An overloaded operator []
       * @param n - number of place
       * @return Reference to nth object
       */
      T& operator[](int) const;

      /**
       * @brief Appends with values from right
       * @param right - other container
       * @return This*
       */
      aghContainer<T>& operator+=(aghContainer<T> const&);

      /**
       * @brief Appends with given values
       * @param element - append value
       * @return This*
       */
      aghContainer<T>& operator+=(T const&);

      /**
       * @brief Appends with given values
       * @param element - append value
       * @return This*
       */
      aghContainer<T>& operator<<(T const&);

      /**
       * @brief Appends with values from right
       * @param right - container
       * @return This*
       */
      aghContainer<T>& operator<<(aghContainer<T> const&);

      /**
       * @brief Prints content to stream
       * @param stream - output
       * @param right - container
       * @return Output stream
       */
      template<class U> friend ostream& operator<<(ostream&, aghContainer const&);
};

#endif /* AGHCONTAINER_H_ */
