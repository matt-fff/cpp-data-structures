/*
  File: list.h
  Author: Matthew White CS153 B
  Contains the class and prototypes for the list class
*/
/*
  Class: List
  A doubly-linked list container.

  Constructor: List()
  Initializes the size to 0 and the front and back to null.

  Constructor: List(const List& l)
  Clears the contents of the list and then creates a duplicate of l.

    Parameters:
    l - The list to be copied.

  Destructor: ~List()
  Deletes the entire contents of the list.

  Function: void push_front(generic x)
  Inserts the data item x to the front of the list.

    Parameters:
    x - The data item to be inserted.
  
  Function: void pop_front()
  Removes a data item from the front of the list. If there are no items to
  remove, then the function does nothing.

  Function: void push_back(generic x)
  Inserts the data item x to the back of the list.

    Parameters:
    x - The data item to be inserted.
  
  Function: void pop_back()
  Removes a data item from the back of the list. If there are no items to
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
  
  Function: generic& back()
  Retreives a writeable reference to the data item at the back of the list. If
  the list is empty then a standard out_of_range exception is thrown.

    Returns:
    A writeable reference to the list's back data.

  Function: const generic& front() const
  Retreives a read-only reference to the data item at the front of the list. If
  the list is empty then a standard out_of_range exception is thrown.

    Returns:
    A read-only reference to the list's front data.
  
  Function: const generic& back() const
  Retreives a read-only reference to the data item at the back of the list. If
  the list is empty then a standard out_of_range exception is thrown.

    Returns:
    A read-only reference to the list's back data.

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

  Operator: List& operator=(const List& l)
  Clears the contents of the list and then creates a duplicate of l.

    Parameters:
    l - The list to be replicated.

    Returns:
    A reference to the newly cloned list.
*/
#ifndef LIST_H
#define LIST_H

#include"node.h"
#include"listiterator.h"
#include<stdexcept>
using std::out_of_range;

template<typename generic>
class List
{
 public:
  List();
  List(const List& l);
  List& operator=(const List& l);
  ~List();
  void push_front(generic x);
  void pop_front();
  void push_back(generic x);
  void pop_back();
  void remove(generic x);
  generic& front();
  generic& back();
  const generic& front() const;
  const generic& back() const;
  void clear();
  unsigned int size() const;
  bool empty() const;
  typedef ListIterator<generic> Iterator;
  Iterator begin() const{return Iterator(m_front);}
  Iterator end() const{return Iterator(m_back);}

 private:
  unsigned int m_size;
  Node<generic>* m_front;
  Node<generic>* m_back;
};

#include"list.hpp"
#endif
