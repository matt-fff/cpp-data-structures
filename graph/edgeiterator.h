/*
  File: edgeiterator.h
  Author: Matthew White CS153 B
  Contains the edgeiterator class prototypes
*/
/*
	Class: edgeIterator
	The edgeIterator iterator class
	
	Default Constructor:
	Sets m_parent and m_current to the end of a set iterator
	
	Constructor: edgeIterator(const graph& map)
	Sets m_graph to map, m_parent to m_graph's first node, and m_current to m_parent's first edge
	
		Parameters:
		map - the graph to set m_graph to
	
	Constructor: edgeIterator(set<node*>::iterator parent, set<edge*>::iterator current)
	Set m_parent to parent and m_current to current
	
		Parameters:
		parent - the parent node for the iterator
		current - the current edge for the iterator
		
	Function: edge* operator*()
	Returns *m_current
	
   Function: edgeIterator operator++()
	Increments through the edges and parent nodes
	
   Function: edgeIterator operator++(int)
	Increments through the edges and parent nodes
	
   Function: bool operator==(const edgeIterator& x) const
	Returns true if the m_current and m_parent iterators are the same between this and the parameter
	
		Parameters:
		x - the edgeIterator to be compared against
	
   Function: bool operator!=(const edgeIterator& x) const
	Returns false if the m_current and m_parent iterators are the same between this and the parameter
	
		Parameters:
		x - the edgeIterator to be compared against
		
	Function: bool ended()
	Returns true if anything has ended or if anything seems to have gone awry.

	Special Notes:
	Edges have two parent nodes.  The way the graph works, a single edge will be stored in both parents'
	edges set.  Because of this redundancy, we only iterate through edges whose parents are on their left
*/

#ifndef EDGEITERATOR_H
#define EDGEITERATOR_H

#include "node.h"
#include "edge.h"
#include "graph.h"

class node;
class edge;
class graph;

class edgeIterator
{
  public:
    edgeIterator();
	 edgeIterator(const graph& map);
	 //~edgeIterator();
    edge* operator*();
    edgeIterator operator++();
    edgeIterator operator++(int);
    bool operator==(const edgeIterator& x) const;
    bool operator!=(const edgeIterator& x) const;
    bool ended();
	
  private:
    set<node*>::iterator m_parent;
	 set<edge*>::iterator m_current;
	 graph* m_graph;
};

#endif
