/*
  File: vector.h
  Contains the vector class declaration and prototypes
*/
/*
  Class: Vector
  A container for managing a dynamic array.

  Constructor: Vector()
  Initializes the size to 0, the max_size to 1, and creates a single element
  array at m_data.

  Constructor: Vector(const Vector& v)
  Clears the current contents of the array and then creates a duplicate of v.

    Parameters:
    v - The vector to be copied.

  Destructor: ~Vector()
  Deletes the dynamic array at m_data.

  Function: void push_back(generic x)
  Inserts the data item x to the back of the containers. If the current
  container is not large enough to hold the new item, a the container will
  double in size to make room for the additional item(s).

    Parameters:
    x - The data item to be inserted.

  Function: void pop_back()
  Removes a data item from the back of the container. When the number of
  elements in use becomes less than a quarter of the total number of elements,
  the container will halve in size to make more efficient use of space.

  Function: void clear()
  Empties the container and resets the size back to just one element.

  Function: unsigned int size() const
  Reports the number of elements in use.

    Returns:
    The number of elements currently being occupied within the container.

  Function: unsigned int max_size() const
  Reports the current size of the container.

    Returns:
    The total number of elements currently available.

  Operator: Vector& operator=(const Vector& v)
  Clears the current contents of the array and then creates a duplicate of v.

    Parameters:
    v - The vector to be copied.

    Returns:
    A reference to the newly created duplicate vector.

  Operator: generic& operator[](unsigned int p)
  Retreives a writeable reference to the data item at p within the container. If
  no data item exists at p then a standard out_of_range exception is thrown.

    Parameters:
    p - The position of the container to be accessed.

    Returns:
    A writeable reference to the data item at location p.

  Operator: const generic& operator[](unsigned int p) const
  Retreives a read-only reference to the data item at p within the container. If
  no data item exists at p then a standard out_of_range exception is thrown.

    Parameters:
    p - The position of the container to be accessed.

    Returns:
    A read-only reference to the data item at location p.
*/
#ifndef VECTOR_H
#define VECTOR_H

#include<stdexcept>
using std::out_of_range;

template<typename generic>
class Vector
{
 public:
  Vector();
  Vector(const Vector& v);
  ~Vector();
  void push_back(generic x);
  void pop_back();
  void clear();
  unsigned int size() const;
  unsigned int max_size() const;
  Vector& operator=(const Vector& v);
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;

 private:
  unsigned int m_size;
  unsigned int m_max_size;
  generic* m_data;
};

#include"vector.hpp"
#endif
