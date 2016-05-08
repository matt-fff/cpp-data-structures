/*
  Class: BTPreorderIterator
  A pre-order binary tree traversal iterator.
  
  Constructor: BTPreorderIterator()
  Initializes m_current to NULL;
  
  Constructor: BTPreorderIterator(BTN<generic>* x)
  Initializes m_current to x.
  
    Parameters:
    x - Indicates where m_current should point.
    
  Operator: const generic& operator*() const
  Provides read-only access to the data at m_current.  If m_current is NULL,
  a out_of_range exception is thrown.
  
    Returns:
    A write-protected reference to m_current's data.
    
  Operator: BTPreorderIterator operator++()
  A pre-increment overload for the pre-order iterator.  This moves m_current
  to the next node in the tree according to pre-order binary tree traversal
  rules.
  
    Returns:
    The iterator position after it moved to the next node in the tree.
  
  Operator: BTPreorderIterator operator++(int)
  A post-increment overload for the pre-order iterator.  This moves m_current
  to the next node in the tree according to pre-order binary tree traversal
  rules.
  
    Returns:
    The iterator position after it moved to the next node in the tree.
  
  Operator: bool operator==(const BTPreorderIterator& rhs) const
  Used to compare the equivalence of two iterator positions.  If the iterators
  are located at the same node, a value of true is returned.
  
    Parameters:
    rhs - The iterator to compare against this one.
    
    Returns:
    True if the two iterators are pointing to the same node.  False otherwise.
  
  Operator: bool operator!=(const BTPreorderIterator& rhs) const
  Used to compare the equivalence of two iterator positions.  If the iterators
  are located at the same node, a value of false is returned.
  
    Parameters:
    rhs - The iterator to compare against this one.
    
    Returns:
    True if the iterators are pointing to differnt nodes. False otherwise.
*/
#ifndef BTPREORDERITERATOR_H
#define BTPREORDERITERATOR_H

#include"btn.h"
#include<stdexcept>
using std::out_of_range;

template<typename generic>
class BTPreorderIterator
{
 public:
  BTPreorderIterator();
  BTPreorderIterator(BTN<generic>* x);
  const generic& operator*() const;
  BTPreorderIterator& operator++();
  BTPreorderIterator& operator++(int);
  bool operator==(const BTPreorderIterator& rhs) const;
  bool operator!=(const BTPreorderIterator& rhs) const;

 private:
  BTN<generic>* m_current;
};

#endif

