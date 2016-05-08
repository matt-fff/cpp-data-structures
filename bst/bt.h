/*
  File: bt.h
  Author: Matthew White CS153 B
  Contains the class and prototypes for the bt container class
*/
/*
  Class: BT
  
  Function: BT()
  Sets m_root to NULL and m_size to 0
  
  Function: BT(const BT& c)
  Creates a new tree copied from c
  
    Parameters:
	c - tree to be copied
  
  Function: ~BT()
  Clears the tree
  
  Function: BT& operator=(const BT& rhs)
  Creates a new tree copied from rhs
  
    Parameters:
	rhs - tree to be copied
  
  Function: void clear()
  Clears the tree
  
  Function: bool empty() const
  Returns true if size is 0
  
  Function: unsigned int size() const
  Returns m_size
  
  Function: PreOrder pre_begin() const
  Returns the starting node for the preorder iterator
  
  Function: PreOrder pre_end() const
  Returns the ending node for the preorder iterator
  
  Function: InOrder in_begin() const
  Returns the starting node for the inorder iterator
  
  Function: InOrder in_end() const
  Returns the ending node for the inorder iterator
  
  Function: PostOrder post_begin() const
  Returns the starting node for the postorder iterator
  
  Function: PostOrder post_end() const
  Returns the ending node for the posteorder iterator
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
	void insert(generic x);

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
};

#include"bt.hpp"
#endif
