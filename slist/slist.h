/*
  File: slist.h
  Contains the slist class and prototypes
*/
/*
  Class: SList
  A singly-linked list container.

  Constructor: SList()
  Initializes the size to 0 and the front to null.

  Constructor: SList(const SList& s)
  Clears the contents of the list and then creates a duplicate of s.

    Parameters:
    s - The list to be copied.

  Destructor: ~SList()
  Deletes the entire contents of the list.

  Function: void push_front(generic x)
  Inserts the data item x to the front of the list.

    Parameters:
    x - The data item to be inserted.

  Function: void pop_front()
  Removes a data item from the front of the list. If there are no items to
  remove, then the function does nothing.

  Function: void remove(generic x)
  Removes all instances of x from the list. If there are no data items
  containing x to remove, then the function does nothing.

    Parameters:
    x - The data item to be removed.

  Function: generic& front()
  Retreives a writeable reference to the data item at the front of the list. If
  the list is empty then a standard out_of_range exception is thrown.

    Returns:
    A writeable reference to the list's front data.

  Function: const generic& front() const
  Retreives a read-only reference to the data item at the front of the list. If
  the list is empty then a standard out_of_range exception is thrown.

    Returns:
    A read-only reference to the list's front data.

  Function: void clear()
  Deletes the entire contents of the list and sets size back to 0.

  Function: unsigned int size() const
  Reports the number of data items in the list.

    Returns:
    The number of items stored in the list.

  Function: bool empty() const
  Reports if the list is holding data or is not holding any data.

    Returns:
    True if the list has no data and false if it has data.

  Function: Iterator begin() const
  Places an iterator at the front of the list.

    Returns:
    An iterator positioned at the front of the list.

  Function: Iterator end() const
  Places an iterator at the back of the list.

    Returns:
    An iterator positioned at the back of the list.

  Operator: SList& operator=(const SList& s)
  Clears the contents of the list and then creates a duplicate of s.

    Parameters:
    s - The list to be replicated.

    Returns:
    A reference to the newly cloned list.
*/
#ifndef SLIST_H
#define SLIST_H

#include"snode.h"
#include"slistiterator.h"
#include<stdexcept>
using std::out_of_range;

template<typename generic>
class SList
{
 public:
  SList();
  SList(const SList& s);
  ~SList();
  void push_front(generic x);
  void pop_front();
  void remove(generic x);
  generic& front();
  const generic& front() const;
  void clear();
  unsigned int size() const;
  bool empty() const;
  typedef SListIterator<generic> Iterator;
  Iterator begin() const{return Iterator(m_front);}
  Iterator end() const{return Iterator();}
  SList& operator=(const SList& s);

 private:
  unsigned int m_size;
  SNode<generic>* m_front;
};

#include"slist.hpp"
#endif 
