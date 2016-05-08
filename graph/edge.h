/*
  File: edge.h
  Author: Matthew White CS153 B
  Contains the edge container class prototypes
*/
/*
	Class: edge
	the edge container class
	
	Default Constructor:
	Sets l and r to NULL.  Sets time, mph, and miles to the maximum double value.
	
	Copy Constructor:
	Copies time, mph, and miles from c.  Sets l and r to new nodes of the same values as c's.
	
		Parameters:
		c - the edge to be copied
	
	Destructor:
	Remove edge from its left and right node edges list
	
	Function: edge& operator=(const edge& rhs)
	Copies time, mph, and miles from c.  Sets l and r to new nodes of the same values as rhs'.
	
		Parameters:
		rhs - the edge to be copied
	
	Function: bool operator==(const edge& rhs) const
	Returns true if time, mph, and miles match and both edges share the same sides
		
		Parameters:
		rhs - the edge to compared against
	
	Function: bool operator!=(const edge& rhs) const
	Returns true if time, mph, or miles do not match or  if the edges do not share the same sides
		
		Parameters:
		rhs - the edge to compared against
*/
#ifndef EDGE_H
#define EDGE_H
#include "node.h"

class node;

class edge
{
  public:
  edge();
  ~edge();
  edge(const edge& c);
  edge& operator=(const edge& rhs);
  bool operator==(const edge& rhs) const;
  bool operator!=(const edge& rhs) const;
  
  node* l;
  node* r;
  double time;
  double mph;
  double miles;
};

#endif
