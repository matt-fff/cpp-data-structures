/*
  File: node.h
  Author: Matthew White CS153 B
  Contains the node container class prototypes
*/
/*
	Class: node
	the node container class
	
	Default Constructor:
	Sets name to ""
	
	Copy Constructor:
	Sets name and edges equal to the parameter node
	
		Parameters:
		c - the node to be copied
	
	Function: node& operator=(const node& rhs)
	Sets name and edges equal to the parameter node
	
		Parameters:
		rhs - the node to be copied
  
	Function: edge* find(edge* x)
	Returns a pointer to an edge in edges with the same information as x.
	Returns null if no such edge exists
	
		Parameters:
		x - the edge to be found

*/
#ifndef NODE_H
#define NODE_H
#include <set>
#include <string>
#include "edge.h"

using namespace std;
class edge;

class node
{
  public:
  node();
  ~node();
  node(const node& c);
  node& operator=(const node& rhs);
  edge* find(edge* x);
  
  set<edge*> edges;
  string name;
};

#endif
