/*
  File: queue.h
  Author: Matthew White CS153 B
  Contains class and prototypes for the queue class
*/
/*
  Class: Queue
  A singly-linked list iterator.

  Constructor: Queue()
  Initializes m_current to null.

  Constructor: Queue(const Queue& q)
  Points m_current to q.

    Parameters:
    q - The data item which m_current should point to.
  
  Operator: Queue& operator=(const Queue& q)
  Clears the contents of the queue and then creates a duplicate of q
  
  Parameters:
  q - the queue to be replicated
  
  Returns:
  A reference to the newly cloned queue
  
  Function: bool empty() const
  Returns true if the queue is empty and false otherwise
  
  Function: unsigned int size() const
  Returns the current size of the queue
  
  Function: generic& front()
  Retreives a writeable reference to the data item at the front of the queue.
  If the queue is empty, a standard out_of_range exception is thrown
  
    Returns:
    A read-only reference to the queue's front data.
  
  Function: generic& back()
  Retreives a writeable reference to the data item at the back of the queue.
  If the queue is empty, a standard out_of_range exception is thrown
  
    Returns:
    A read-only reference to the queue's front data.
  
  Function: const generic& front() const
  Retreives a read-only reference to the data item at the front of the queue.
  If the queue is empty, a standard out_of_range exception is thrown
  
    Returns:
    A read-only reference to the queue's front data.
  
  Function: const generic& back() const
  Retreives a read-only reference to the data item at the back of the queue.
  If the queue is empty, a standard out_of_range exception is thrown
  
    Returns:
    A read-only reference to the queue's front data.
  
  Function: void push(generic x)
  creates a new node with data x at the end of the queue
  
    Parameters:
  x - the data item to be inserted
  
  Function: void pop()
  removes a node from the beginning of the queue
  
  Function: void clear()
  Deletes the entire contents of the queue.
*/
#ifndef QUEUE_H
#define QUEUE_H

#include"list.h"

template<typename generic>
class Queue : private List<generic>
{
 public:
  Queue();
  Queue(const Queue& q);
  ~Queue();
  Queue& operator=(const Queue& q);
  bool empty() const;
  unsigned int size() const;
  generic& front();
  generic& back();
  const generic& front() const;
  const generic& back() const;
  void push(generic x);
  void pop();
  void clear();
};

#include"queue.hpp"
#endif
