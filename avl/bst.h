/*
  Class: BST
  A binary search tree container.
  
  Function: void insert(generic x)
  Inserts a node containing the data item x into the tree.  If x already exists
  within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be inserted.
    
  Function: void remove(generic x)
  Removes the node containing the data item x from the tree.  If x does not
  exist within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be removed.
  
  Function: PreOrder pre_search(generic x)
  Places a pre-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    A pre-order iterator at the node containing x.

  Function: InOrder in_search(generic x)
  Places an in-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    An in-order iterator at the node containing x.

  Function: PostOrder post_search(generic x)
  Places a post-order iterator at the location of the node containing x.  If x
  can not be found within the tree, an empty iterator is returned. 
  
    Parameters:
    x - The data to locate within the tree.
    
    Returns:
    A post-order iterator at the node containing x.
  
  Function: BTN<generic>* p_insert(generic x)
  Inserts a node containing the data item x into the tree.  If x already exists
  within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be inserted.
    
    Returns:
    A BTN pointer to the newly inserted node.
    
  Function: BTN<generic>* p_remove(generic x)
  Removes the node containing the data item x from the tree.  If x does not
  exist within the tree, then the request is ignored.
  
    Parameters:
    x - The data item to be removed.
    
    Returns:
    A BTN pointer to the parent of the node that was deleted.
    
  BTN<generic>* p_search(generic x) const
  Searches the tree for the node that contains the data x, and returns a
  pointer to that node.
  
    Parameters:
    x - The data item to be found.
  
    Returns:
    If x is found in the tree, then a pointer is returned to the node
    containing it.  If x is not found in the tree, then a pointer to the node
    that would be x's parent (if it existed) is returned.
    
  Function: void swap(generic* x, generic* y)
  Swaps the x and y pointers.
  
    Parameters:
    x - The first data pointer position to be swapped.
    y - The second data pointer position to be swapped.
*/
#ifndef BST_H
#define BST_H

#include"bt.h"
#include"btn.h"

template<typename generic>
class BST : public BT<generic>
{
 public:
  void insert(generic x);      
  void remove(generic x);
  typedef BTPreorderIterator<generic> PreOrder;
  typedef BTInorderIterator<generic> InOrder;
  typedef BTPostorderIterator<generic> PostOrder;
  PreOrder pre_search(generic x);
  InOrder in_search(generic x);
  PostOrder post_search(generic x);

 protected:
  BTN<generic>* p_insert(generic x);
  BTN<generic>* p_remove(generic x);
  BTN<generic>* p_search(generic x);
  void swap(generic* x, generic* y);
  
 private:
  using BT<generic>::m_size;
  using BT<generic>::m_root;
};

#endif
