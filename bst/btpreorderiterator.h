/*
  File: btpreorderiterator.h
  Author: Matthew White CS153 B
  Contains the preorder iterator for the bt class
*/
/*
  Class: BTPreorderIterator
  
  Function: BTPreorderIterator()
  sets m_current to NULL
  
  Function: BTPreorderIterator(BTN<generic>* x)
  sets m_current to x
  
    Parameters:
	x - node to which to assign iterator
	
  Function: operator*()
  Return m_current->data
  
  Function: operator++()
  Moves iterator to next position
  
  Function: operator++(int)
  Moves iterator to next position
	
  Function: operator==(const BTPreorderIterator&)
  Returns true if parameter equals m_current
  
    Parameters:
	node to compare m_current with
  
  Function: operator!=(const BTPreorderIterator&)
  Returns true if parameter does not equal m_current
  
    Parameters:
	node to compare m_current with
*/
#ifndef BTPREORDERITERATOR_H
#define BTPREORDERITERATOR_H

#include"btn.h"

template <class generic>
class BTPreorderIterator
{
  public:
    BTPreorderIterator();
    BTPreorderIterator(BTN<generic>* x);
    const generic& operator*();
    BTPreorderIterator operator++();
    BTPreorderIterator operator++(int);
    bool operator==(const BTPreorderIterator&) const;
    bool operator!=(const BTPreorderIterator&) const;
  private:
    BTN<generic> * m_current;
};
#include"btpreorderiterator.hpp"
#endif
