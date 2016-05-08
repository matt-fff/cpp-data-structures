/*
  File: listiterator.h
  Author: Matthew White CS153 B
  Contains the class and prototypes for the listiterator class
*/
/*
  Class: ListIterator
  A doubly-linked list iterator.

  Constructor: ListIterator()
  Initializes m_current to null.

  Constructor: ListIterator(Node<generic>* l)
  Points m_current to l.

    Parameters:
    l - The data item which m_current should point to.

  Operator: generic& operator*()
  Retreives a writable reference to the data item at the iterator's position.
  If the iterator is not located at a data item, the function throws a standard
  out_of_range error.

    Returns:
    A writable reference to the iterator's data.

  Operator: const generic& operator*() const
  Retreives a read-only reference to the data item at the iterator's position.
  If the iterator is not located at a data item, the function throws a standard
  out_of_range error.

    Returns:
    A read-only reference to the iterator's data.

  Operator: ListIterator operator++()
  A pre-increment operator that moves the iterator to the next data item. If
  the iterator has already surpassed the last data item, then the function
  does nothing.

    Returns:
    A copy of an iterator located at the next data item.

  Operator: ListIterator operator++(int x)
  A post-increment operator that moves the iterator to the next data item. If
  the iterator has already surpassed the last data item, then the function
  does nothing.

    Parameters:
    x - A dummy variable used to differentiate between the pre and post ops.

    Returns:
    A copy of an iterator located at the next data item.
  
  Operator: ListIterator operator--()
  A pre-decrement operator that moves the iterator to the last data item. If
  the iterator has already surpassed the first data item, then the function
  does nothing.

    Returns:
    A copy of an iterator located at the last data item.

  Operator: ListIterator operator--(int x)
  A post-decrement operator that moves the iterator to the last data item. If
  the iterator has already surpassed the first data item, then the function
  does nothing.

    Parameters:
    x - A dummy variable used to differentiate between the pre and post ops.

    Returns:
    A copy of an iterator located at the last data item.

  Operator: bool operator==(const ListIterator& l) const
  A comparison operator used to determine if two iterators are the same.

    Parameters:
    l - The iterator to be compared against.

    Returns:
    True if the two iterators are positioned over the same data item and false
    if they are positioned over different data items.

  Operator: bool operator!=(const ListIterator& l) const
  A comparison operator used to determine if two iterators are different.

    Parameters:
    l - The iterator to be compared against.

    Returns:
    True if the two iterators are positioned over different data items and
    false if they are positioned over the same data item.
*/
#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include<stdexcept>
using std::out_of_range;
#include"node.h"

template<typename generic>
class ListIterator
{
 public:
  ListIterator();
  ListIterator(Node<generic>* n);
  generic& operator*();
  const generic& operator*() const;
  ListIterator operator++();
  ListIterator operator++(int);
  ListIterator operator--();
  ListIterator operator--(int);
  bool operator==(const ListIterator& l) const;
  bool operator!=(const ListIterator& l) const;

 private:
  Node<generic>* m_current;
};

#include"listiterator.hpp"
#endif 
