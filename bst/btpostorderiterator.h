/*
  File: btpostorderiterator.h
  Author: Matthew White CS153 B
  Contains the postorder iterator for the bt class
*/
/*
  Class: BTPostorderIterator
  
  Function: BTPostorderIterator()
  sets m_current to NULL
  
  Function: BTPostorderIterator(BTN<generic>* x)
  sets m_current to x
  
    Parameters:
	x - node to which to assign iterator
	
  Function: operator*()
  Return m_current->data
  
  Function: operator++()
  Moves iterator to next position
  
  Function: operator++(int)
  Moves iterator to next position
	
  Function: operator==(const BTPostorderIterator&)
  Returns true if parameter equals m_current
  
    Parameters:
	node to compare m_current with
  
  Function: operator!=(const BTPostorderIterator&)
  Returns true if parameter does not equal m_current
  
    Parameters:
	node to compare m_current with
*/
#ifndef BTPOSTORDERITERATOR_H
#define BTPOSTORDERITERATOR_H

#include"btn.h"

template<typename generic>
class BTPostorderIterator
{
  public:
    BTPostorderIterator();
    BTPostorderIterator(BTN<generic>* x);
    const generic& operator*();
    BTPostorderIterator operator++();
    BTPostorderIterator operator++(int);
    bool operator==(const BTPostorderIterator&) const;
    bool operator!=(const BTPostorderIterator&) const;
  private:
    BTN<generic> * m_current;
};

#include"btpostorderiterator.hpp"
#endif
