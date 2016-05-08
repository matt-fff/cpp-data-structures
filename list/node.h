/*
  File: node.h
  Author: Matthew White CS153 B
  Contains the node struct
*/
#ifndef NODE_H
#define NODE_H

template<typename generic>
struct Node
{
  Node<generic>* f;
  Node<generic>* b;
  generic data;
};

#endif 
