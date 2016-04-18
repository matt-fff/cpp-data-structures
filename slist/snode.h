/*
  File: snode.h
  Contains SNode class
*/
/*
  Class: SNode
  A singly-linked node.

    Variable: b
    Provides the single-link by pointing to the node back behind this node.

    Variable: data
    The contents of the node.
*/
#ifndef SNODE_H
#define SNODE_H

template<typename generic>
struct SNode
{
  SNode<generic>* b;
  generic data;
};

#endif
