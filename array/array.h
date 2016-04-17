/*
  File: array.h
  Contains function prototypes and the class declaration for the array class
*/

/*
  Class: Array
  A container for managing a static array.

  Constructor: Array()
  Initializes the size to 0 and the max_size to 20.

  Function: void push_back(generic x)
  Adds a new data item into the back of the container. If the container is full
  the push request will be ignored and the container's state will be unchanged.

    Parameters:
    x - The data to be inserted into the container.

  Function: void pop_back()
  Removes a data item from the back of the container. If the container is empty
  the pop request will be ignored and the container's state will be unchanged.

  Function: void clear()
  Empties the container. If the container is already empty, nothing happens.

  Function: unsigned int size() const
  Reports the number of data items currently being held in the container.

    Returns:
    The number of data items currently being held in the container.

  Function: unsigned int max_size() const
  Reports the maximum number of data items that can be held in the container.

    Returns:
    The maximum number of data items that can be held in the container.

  Operator: generic& operator[](unsigned int p)
  Retreives a writeable reference to the data item at p within the container.

    Parameters:
    p - The position of the container to be accessed.

    Returns:
    A writeable reference to the data item at location p.

  Operator: const generic& operator[](unsigned int p) const
  Retreives a read-only reference to the data item at p within the container.

    Parameters:
    p - The position of the container to be accessed.

    Returns:
    A read-only reference to the data item at location p.
*/
#ifndef ARRAY_H
#define ARRAY_H

#include<stdexcept>
using std::out_of_range;

template<typename generic>
class Array
{
 public:
  Array();
  void push_back(generic x);
  void pop_back();
  void clear();
  unsigned int size() const;
  unsigned int max_size() const;
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;

 private:
  unsigned int m_size;
  unsigned int m_max_size;
  generic m_data[20];
};

#include"array.hpp"
#endif
