/*
  File: bst.h
  Author: Matthew White CS153 B
  Contains the prototypes for the bst container class
*/
/*
  Class: BST
  A Binary Search Tree container
  
  Function: BST()
  Sets m_size to 0 and m_root to NULL
  
  Function: ~BST()
  Calls clear
  
  Function: insert(generic x)
  Inserts a BTN with data containing x into the tree
    
	Parameters:
	x - value to be inserted into the new node into the tree
  
  Function: remove(generic x)
  If found, removes the first node found which contains x
  
    Parameters:
	x - value to be located and destroyed
  
  Function: search(generic x) const
  Returns true if a node containing x is found in the tree;
  Returns false otherwise.
  
    Parameters:
	x - value to be found
  
  Function: clear()
  Clears out all the nodes in the tree
  
  Function: empty() const
  Returns true if m_size == 0, false otherwise
  
  Function: size() const
  Returns m_size
  
  Function: swap(BTN<generic>* a, BTN<generic>* b)
  Swaps the data of a and b
  
    Parameters:
	a, b - nodes whose data is to be swapped with each other
  
  Function: delete_node(BTN<generic>* a)
  Deletes node a from the tree while keeping the tree integrity intact.
  Note: does nothing if a has two child nodes.
  
    Parameters:
	a - node to be deleted
  
  Function: leftRightmost(BTN<generic>* a)
  Returns the left-rightmost node of node a; for use in node deletion
    
	Parameters:
	a - node base for finding the left-rightmost
	
  Function:PreOrder pre_search(generic x)
  Searches tree using preorder iterator.  Returns an iterator with
  data x if a node is found countaining it, NULL otherwise.
  
    Parameters:
	x - the data to be found in the tree
	
  Function:PostOrder post_search(generic x)
  Searches tree using postorder iterator.  Returns an iterator with
  data x if a node is found countaining it, NULL otherwise.
  
    Parameters:
	x - the data to be found in the tree
	
  Function:InOrder in_search(generic x)
  Searches tree using inorder iterator.  Returns an iterator with
  data x if a node is found countaining it, NULL otherwise.
  
    Parameters:
	x - the data to be found in the tree
*/
#ifndef BST_H
#define BST_H

#include "bt.h"

template<typename generic>
class BST : public BT<generic>
{
  public:
    BST();
    ~BST();
    void insert(generic x);
    void remove(generic x);
    bool search(generic x) const;
    void clear();
    bool empty() const;
    unsigned int size() const;
	
	typedef BTPreorderIterator<generic> PreOrder;
    typedef BTInorderIterator<generic> InOrder;
    typedef BTPostorderIterator<generic> PostOrder;
    PreOrder pre_search(generic x);
    InOrder in_search(generic x);
    PostOrder post_search(generic x);
	
	PreOrder pre_begin() const;
    PreOrder pre_end() const;
    InOrder in_begin() const;
    InOrder in_end() const;
    PostOrder post_begin() const;
    PostOrder post_end() const;
	
  private:
    void swap(BTN<generic>* a, BTN<generic>* b);
	void delete_node(BTN<generic>* a);
	BTN<generic>* leftRightmost(BTN<generic>* a);
    BTN<generic>* m_root;
	unsigned m_size;
};

#include "bst.hpp"
#endif
