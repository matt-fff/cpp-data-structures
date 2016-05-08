/*
  Class: BT
  An abstract base class for all binary trees.
  
  Constructor: BT()
  Sets m_root to NULL and m_size to 0.
  
  Constructor: BT(const BT& c)
  Sets m_root to NULL and m_size to 0.  Then calls the assignment operator
  to create a duplicate of c.
  
    Parameters:
    c - The binary tree to copy.
  
  Destructor: ~BT()
  Clears out all of the nodes in the tree.
  
  Operator: BT& operator=(const BT& rhs)
  Creates a binary tree that exactly matches the contents and structure to
  that of the rhs tree.
  
    Parameters:
    rhs - The binary tree to duplicate.
    
    Returns:
    A reference to the new duplicate tree.
  
  Function: void clear()
  Deletes all nodes from the tree.  If the tree is already empty, then the
  function does nothing.
  
  Function: bool empty() const
  Indicates if the tree contains any nodes.
  
    Returns:
    True if there are one or more nodes within the tree.  False if otherwise.
  
  Function: unsigned int size() const
  Reports how many nodes exist within the tree.
  
    Returns:
    The total number of nodes within the binary search tree.
    
  Function: PreOrder pre_begin() const
  Places a pre-order iterator at the beginning of the pre-order traversal.
  
    Returns:
    A pre-order iterator at the first node in its traversal cycle.
    
  Function: PreOrder pre_end() const
  Indicates where the pre-order cycle ends.
  
    Returns:
    A pre-order iterator at the end of the traversal cycle.
    
  Function: InOrder in_begin() const
  Places an in-order iterator at the beginning of the in-order traversal.
  
    Returns:
    An in-order iterator at the first node in its traversal cycle.
  
  Function: InOrder in_end() const
  Indicates where the in-order cycle ends.
  
    Returns:
    An in-order iterator at the end of the traversal cycle.
  
  Function: PostOrder post_begin() const
  Places a post-order iterator at the beginning of the post-order traversal.
  
    Returns:
    A post-order iterator at the first node in its traversal cycle.
    
  Function: PostOrder post_end() const
  Indicates where the post-order cycle ends.
  
    Returns:
    A post-order iterator at the end of the traversal cycle.
*/
#ifndef BT_H
#define BT_H

#include"btn.h"
#include"btpreorderiterator.h"
#include"btinorderiterator.h"
#include"btpostorderiterator.h"

template<typename generic>
class BT
{
 public:
  BT();
  BT(const BT& c);
  ~BT();
  BT& operator=(const BT& rhs);
  void clear();
  bool empty() const;
  unsigned int size() const;
  typedef BTPreorderIterator<generic> PreOrder;
  typedef BTInorderIterator<generic> InOrder;
  typedef BTPostorderIterator<generic> PostOrder;
  PreOrder pre_begin() const;
  PreOrder pre_end() const;
  InOrder in_begin() const;
  InOrder in_end() const;
  PostOrder post_begin() const;
  PostOrder post_end() const;
  
 protected:
  BTN<generic>* m_root;
  unsigned int m_size;
  
 private:
  void recursive_copy(BTN<generic>* thisNode, BTN<generic>* copyNode);
  void recursive_clear(BTN<generic>* deleteNode);
};

#endif
