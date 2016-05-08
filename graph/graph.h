/*
  File: graph.h
  Author: Matthew White CS153 B
  Contains the graph container class prototypes
*/
/*
	Class: graph
	the graph container class
	
	Default Constructor:
	Does nothing
	
	Copy Constructor:
	Copies nodes from p_graph
	
		Parameters:
		p_graph - the graph to be copied
	
	Constructor: graph(fstream& fin)
	Goes until the end of fin, creating vertices and edges from the input file.
	fin must have to proper formatting.
	
		Parameters:
		fin - the stream to be input
	
	Function: graph& operator=(const graph& p_graph)
	Copies nodes from p_graph
	
		Parameters:
		p_graph - the graph to be copied
		
	Function: void insertEdge(string p_left, string p_right, double p_mph, double p_miles)
	Inserts an edge with the given attributes into the appropriate nodes in nodes (creates the appropriate nodes if they DNE)
		
		Parameters:
		p_left - the name of the left node
		p_right - the name of the right node
		p_mph - the average miles per hour for an edge
		p_miles - the length of an edge
	
	Function: void insertNode(node* p_node)
	Inserts p_node into nodes.  Ignores request if a node with the same nasme is found
	
		Parameters:
		p_node - the node to be inserted
		
	
	Function: void removeEdge(edge* p_edge)
	Finds and removes an edge with the same attributes as p_edge.  Also removes the edge from the edge sets its parents have.
	All attributes of p_edge must be set to function.
	
		Parameters:
		p_edge - the edge to be removed
	
	Function: void removeNode(node* p_node);
	Finds and removes a node with the same name as p_node.  Will use removeEdge to eliminate all the edges the found node's edges set
	
		Parameters:
		p_node - the node to be removed;
	
	Function: node* find(string p_name);
	Finds and returns a node in the nodes set that has the name of p_name. Returns NULL if node not found.
	
		Parameters:
		p_name - the node name to be found
		
	Function: void print()
	Prints out each vertices and its associated edges in a coherent manner.
  
	Function: NodeIterator beginNode() const
	Returns the begin iterator of nodes
	
	Function: NodeIterator endNode() const
	Returns the end iterator of nodes
  
	
	Function: edgeIterator beginEdge() const
	Returns the begin iterator of edges in the beginning node in nodes
	
	Function: edgeIterator endEdge() const
	Returns the default end iterator of a set of edge* 's
  
	Function: void insertFromFile(fstream& fin)
	Reads in one node and its associated edges from a file and inserts the result in the graph
	
*/

#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include "edge.h"
#include "node.h"
#include "edgeiterator.h"
#include <string>

class edge;
class node;
class edgeIterator;

class graph
{
  public:
  graph();
  graph(const graph& p_graph);
  graph(fstream& fin);
  ~graph();
  graph& operator=(const graph& p_graph);
  void insertEdge(string p_left, string p_right, double p_mph, double p_miles);
  void insertNode(string p_node);
  void insertNode(node* p_node);
  void removeEdge(edge* p_edge);
  void removeNode(node* p_node);
  node* find(string p_name);
  edge* find(string p_left, string p_right, double p_mph, double p_miles);
  
  set<node*> nodes;
  
  void print();
  
  typedef set<node*>::iterator NodeIterator;
  NodeIterator beginNode() const;
  NodeIterator endNode() const;
  
  typedef edgeIterator EdgeIterator;
  EdgeIterator beginEdge() const;
  EdgeIterator endEdge() const;
  
  private:
  void insertFromFile(fstream& fin);
};

#endif
