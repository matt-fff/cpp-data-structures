/*
  Class: AVL
  An Adelson-Velskii and Landis balanced binary search tree container.
  
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
  
  Function: void rotate(BTN<generic>* x)
  When an imbalance is detected (a node with +2 or -2 imbalance), the rotate
  function is used to identify which type of rotation should be performed.
  
    Parameters:
    x - The node that has a +2 or -2 imbalance.
  
  Function: void rotatePosPos(BTN<generic>* x)
  When the rotate function detects a +2 and +1 imbalance, the rotatePosPos
  function performs a correction to shift subtree's nodes into a balanced state. 
  
    Parameters:
    x - The node that has a +2 imbalance.
  
  Function: void rotatePosNeg(BTN<generic>* x)
  When the rotate function detects a +2 and -1 imbalance, the rotatePosNeg
  function performs a correction to shift subtree's nodes into a balanced state. 
  
    Parameters:
    x - The node that has a +2 imbalance.
  
  Function: void rotateNegPos(BTN<generic>* x)
  When the rotate function detects a -2 and +1 imbalance, the rotateNegPos
  function performs a correction to shift subtree's nodes into a balanced state. 
  
    Parameters:
    x - The node that has a -2 imbalance.
  
  Function: void rotateNegNeg(BTN<generic>* x)
  When the rotate function detects a -2 and -1 imbalance, the rotateNegNeg
  function performs a correction to shift subtree's nodes into a balanced state. 
  
    Parameters:
    x - The node that has a -2 imbalance.
  
  Function: bool unbalanced(BTN<generic>* px)
  Determines if the subtree at and below px is balanced.
  
    Parameters:
    px - The node at the top of the subtree to be evaluated.
    
    Returns:
    True if the balance at px is above +1 or below -1.  False if otherwise.
  
  Function: int getDepth(BTN<generic>* px)
  Determines the distance of px from the furthest leaf node.
  
    Parameters:
    px - The node whose depth is to be evaluated.
    
    Returns:
    An integer count of how many nodes lie beneath px in the tree.
  
  Function: void setDepth(BTN<generic>* px)
  Sets the depth of px.
  
    Parameters:
    px - The node whose depth is to be established.
*/

#ifndef AVL_H
#define AVL_H
#include"bst.h"

template<typename generic>
class AVL : public BST<generic>
{
 public:
  void insert(generic x);
  void remove(generic x);

 private:
  void rotate(BTN<generic>* x);
  void rotatePosPos(BTN<generic>* x);
  void rotatePosNeg(BTN<generic>* x);
  void rotateNegPos(BTN<generic>* x);
  void rotateNegNeg(BTN<generic>* x);
  bool unbalanced(BTN<generic>* px);
  int getDepth(BTN<generic>* px);
  void setDepth(BTN<generic>* px);
};

#endif
