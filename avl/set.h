/*
  File: set.h
  Author: Matthew White CS153 B
  Contains the set container class prototypes
*/
/*
  Class: Set
  A set tree container.
  
  Function: Set(const Set&)
  Creates a new set and copies the parameter to it
	
	Parameters:
		the set to copy from
  
  Function: Set& operator=(const Set&)
  Creates a new set and copies the parameter to it
	
	Parameters:
		the set to copy from
		
  Function: Set operator+(const Set&) const
  Returns a new set containing the elements found in either the 
  lhs or the rhs
  
	Parameters:
		the set to compare against
		
  Function: Set operator*(const Set&) const
  Returns a new set containing only the elements found in both the lhs
  and the rhs
  
	Parameters:
		the set to compare against
  
  Function: Set operator-(const Set&) const
  Returns a new set containing only the elements found in the lhs that
  were not found in the rhs
  
	Parameters:
		the set to compare against
		
  Function: void insert(generic)
  Inserts a new element into the set
  
	Parameters:
		the element to insert
		
  Function: void erase(generic)
  Removes the element from the set
  
	Parameters:
		the element to be removed
		
  Function: void clear()
  Clears the entire set
  
  Function: bool empty() const
  Returns true if size = 0
  
  Function: unsigned int size() const
  Returns m_size
  
  Function: Iterator find(generic)
  Returns an iterator located at the node at with generic is found
  
	Parameters:
		the element to be found
		
  Function: Iterator begin() const
  Returns an iterator located at the node at the inorder iterator 
  starting node
  
  Function: Iterator end() const
  Returns NULL
*/
#ifndef SET_H
#define SET_H
#include"avl.h"
#include"btinorderiterator.h"

template<typename generic>
class Set : private AVL<generic>
{
 public:
  Set();
  Set(const Set&);
  Set& operator=(const Set&);
  Set operator+(const Set&) const;
  Set operator*(const Set&) const;
  Set operator-(const Set&) const;
  void insert(generic);
  void erase(generic);
  void clear();
  bool empty() const;
  unsigned int size() const;
  typedef BTInorderIterator<generic> Iterator;
  Iterator find(generic);
  Iterator begin() const;
  Iterator end() const;
  
  private:
   using AVL<generic>::remove;//(generic);
  //int m_size;
  //BTN<generic>* m_root;
};

#include"set.hpp"
#endif
