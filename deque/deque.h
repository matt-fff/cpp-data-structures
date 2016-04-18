/*
  File: deque.h
  Contains the class and prototypes for the deque container
*/
/*
  Class: Deque
  A deque container.

  Constructor: Deque()
  Sets size to 0, blocks to 1, block size to 3, and creates a block  

  Constructor: Deque(unsigned int n)
  Sets size to 0, blocks to 1, block size to n, and creates a block  
  
    Parameters:
	n - The block size to be used
  
  Constuctor: Deque(Deque& d)
  Creates a new deque and copies d to it
  
    Parameters:
    d - The deque to be copied.

  Destructor: ~Deque()
  Deletes the entire contents of the deque.

  Function: void push_front(generic x)
  Inserts the data item x to the front of the deque.

    Parameters:
    x - The data item to be inserted.
	
  Function: void pop_front()
  Removes a data item from the front of the deque. If there are no items to
  remove, then the function does nothing.

  Function: void push_back(generic x)
  Inserts the data item x to the back of the deque.

    Parameters:
    x - The data item to be inserted.
	
  Function: void pop_back()
  Removes a data item from the back of the deque. If there are no items to
  remove, then the function does nothing.

  Function: void clear()
  Deletes the entire contents of the deque and sets size to 0 and blocks back to 1.

  Function: Deque& operator=(const Deque& d)
  Clears the content of the deque and creates a duplicate of d
  
    Parameters:
	d - the deque to be copied
  
  Function: generic& operator[](unsigned int p)
  Returns a writable reference to the data item at position p in the deque
  
    Parameters:
	p - the position of the element to be returned
	
  Function: const generic& operator[](unsigned int p) const
  Returns a read-only reference to the data item at position p in the deque
    
	Parameters:
	p - the position of the element to be returned
  
  Function: unsigned int size() const
  Reports the number of data items in the deque.

    Returns:
    The number of items stored in the list.

  Function: bool empty() const
  Reports if the deque is holding data or is not holding any data.

    Returns:
    True if the deque has no data and false if it has data.
*/
#ifndef DEQUE_H
#define DEQUE_H

#include<stdexcept>
using std::out_of_range;
#include "block.h"

template<typename generic>
class Deque
{
 public:
  Deque();
  Deque(unsigned int n);
  Deque(Deque& d);
  ~Deque();
  void push_front(generic x);
  void pop_front();
  void push_back(generic x);
  void pop_back();
  void clear();
  Deque& operator=(const Deque& d);
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;
  unsigned int size() const;
  unsigned int block_size() const;
  bool empty() const;

 private:
  Block<generic>** m_data;
  unsigned int m_size;
  unsigned int m_blocks;
  unsigned int m_block_size;
};

#include"deque.hpp"
#endif
