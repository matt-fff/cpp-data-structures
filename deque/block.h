/*
  File: block.h
  Contains the class and prototypes for the block container
*/
/*
  Class: Block
  A block container.

  Constructor: Block()
  Creates a block of size 0 with m_front equal to -1,
  max size equal to 3, and m_data to the array

  Constructor: Block(unsigned int n)
  creates a block of size 0 with m_front equal to -1,
  max size equal to n, and m_data to the array
  
    Parameters:
	n - The block size to be used
  
  Constuctor: Block(Block& b)
  Creates a duplicate of b
  
    Parameters:
    b - The block to be copied.

  Destructor: ~Block()
  Deletes the entire contents of the block.

  Function: void push_front(generic x)
  Inserts the data item x to the front of the block.

    Parameters:
    x - The data item to be inserted.
	
  Function: void pop_front()
  Removes a data item from the front of the block. If there are no items to
  remove, then the function does nothing.

  Function: void push_back(generic x)
  Inserts the data item x to the back of the block.

    Parameters:
    x - The data item to be inserted.
	
  Function: void pop_back()
  Removes a data item from the back of the block. If there are no items to
  remove, then the function does nothing.

  Function: void clear()
  Deletes the entire contents of the block and sets size to 0 and blocks back to 1.

  Function: Block& operator=(const Block& b)
  Clears the content of the block and creates a duplicate of b
  
    Parameters:
	b - the block to be copied
  
  Function: generic& operator[](unsigned int p)
  Returns a writable reference to the data item at position p in the block
  
    Parameters:
	p - the position of the element to be returned
	
  Function: const generic& operator[](unsigned int p) const
  Returns a read-only reference to the data item at position p in the block
    
	Parameters:
	p - the position of the element to be returned
  
  Function: unsigned int size() const
  Reports the number of data items in the block.

    Returns:
    The number of items stored in the block.

  Function: bool ffull() const
  Reports if the block front is full
  
    Returns:
	True if the front of the block is full, false otherwise
  
  Function: bool bfull() const
  Reports if the block back is full
  
    Returns:
	True if the back of the block is full, false otherwise
  
	
  Function: bool empty() const
  Reports if the block is holding data or is not holding any data.

    Returns:
    True if the block has no data and false if it has data.
*/
/*
  File: main.cpp
  Author: Matthew White CS153 B
  Contains fun run program running and testing code
*/
#ifndef BLOCK_H
#define BLOCK_H

#include<stdexcept>
using std::out_of_range;
using std::invalid_argument;

template<typename generic>
class Block
{
 public:
  Block();
  Block(unsigned int n);
  Block(Block& b);
  Block& operator=(const Block& b);
  ~Block();
  void push_front(generic x);
  void pop_front();
  void push_back(generic x);
  void pop_back();
  void clear();
  generic& operator[](unsigned int p);
  const generic& operator[](unsigned int p) const;
  unsigned int size() const;
  unsigned int max_size() const;
  bool ffull() const;
  bool bfull() const;
  bool empty() const;

 private:
  generic* m_data;
  unsigned int m_size;
  unsigned int m_max_size;
  unsigned int m_front;
};

#include"block.hpp"
#endif
