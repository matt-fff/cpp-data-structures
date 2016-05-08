/*
  File: btinorderiterator.h
  Author: Matthew White CS153 B
  Contains the inorder iterator for the bt class
*/
/*
  Class: BTInorderIterator
  
  Function: BTInorderIterator()
  sets m_current to NULL
  
  Function: BTInorderIterator(BTN<generic>* x)
  sets m_current to x
  
    Parameters:
	x - node to which to assign iterator
	
  Function: operator*()
  Return m_current->data
  
  Function: operator++()
  Moves iterator to next position
  
  Function: operator++(int)
  Moves iterator to next position
	
  Function: operator==(const BTInorderIterator&)
  Returns true if parameter equals m_current
  
    Parameters:
	node to compare m_current with
  
  Function: operator!=(const BTInorderIterator&)
  Returns true if parameter does not equal m_current
  
    Parameters:
	node to compare m_current with
*/
#ifndef BTINORDERITERATOR_H
#define BTINORDERITERATOR_H

#include"btn.h"

template<typename generic>
class BTInorderIterator
{
  public:
    BTInorderIterator();
    BTInorderIterator(BTN<generic>* x);	
    const generic& operator*();
    BTInorderIterator operator++();
    BTInorderIterator operator++(int);
    bool operator==(const BTInorderIterator&) const;
    bool operator!=(const BTInorderIterator&) const;
  private:
    void set_end();
    BTN<generic> * m_current;
	BTN<generic> * m_end;
};

#include"btinorderiterator.hpp"
#endif
