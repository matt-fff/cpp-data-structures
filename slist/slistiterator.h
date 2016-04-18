/*
  File: slistiterator.hpp
  Contains the prototypes and the slist iterator class
*/
/*
  Class: SListIterator
  A singly-linked list iterator.

  Constructor: SListIterator()
  Initializes m_current to null.

  Constructor: SListIterator(SNode<generic>* s)
  Points m_current to s.

    Parameters:
    s - The data item which m_current should point to.

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

  Operator: SListIterator operator++()
  A pre-increment operator that moves the iterator to the next data item. If
  the iterator has already surpassed the last data item, then the function
  does nothing.

    Returns:
    A copy of an iterator located at the next data item.

  Operator: SListIterator operator++(int x)
  A post-increment operator that moves the iterator to the next data item. If
  the iterator has already surpassed the last data item, then the function
  does nothing.

    Parameters:
    x - A dummy variable used to differentiate between the pre and post ops.

    Returns:
    A copy of an iterator located at the next data item.

  Operator: bool operator==(const SListIterator& s) const
  A comparison operator used to determine if two iterators are the same.

    Parameters:
    s - The iterator to be compared against.

    Returns:
    True if the two iterators are positioned over the same data item and false
    if they are positioned over different data items.

  Operator: bool operator!=(const SListIterator& s) const
  A comparison operator used to determine if two iterators are different.

    Parameters:
    x - The iterator to be compared against.

    Returns:
    True if the two iterators are positioned over different data items and
    false if they are positioned over the same data item.
*/
#ifndef SLISTITERATOR_H
#define SLISTITERATOR_H

#include<stdexcept>
using std::out_of_range;
#include"snode.h"

template<typename generic>
class SListIterator
{
 public:
  SListIterator();
  SListIterator(SNode<generic>* s);
  generic& operator*();
  const generic& operator*() const;
  SListIterator operator++();
  SListIterator operator++(int x);
  bool operator==(const SListIterator& s) const;
  bool operator!=(const SListIterator& s) const;

 private:
  SNode<generic>* m_current;
};

#include"slistiterator.hpp"
#endif 
