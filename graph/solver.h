/*
  File: solver.h
  Author: Matthew White CS153 B
  Contains the solver prototypes
*/
/*
	This is really just a collection of structs and functions
	to nicely determine and display the optimum route

	Function: route shortestPath(string start, string finish, graph map)
	Uses Dijkstra's Algorithm to determine the best route between the start and finish
	
		Parameters:
		start - the starting node's name
		finish - the finishing node's name
		map - the graph on which one wants to find a path
	
	Function: int find(const vector<solverNode>& v, const solverNode x)
	Returns the index within v at which x is located.  Returns -1 if x not found
	
		Parameters:
		v - the vector to be searched
		c - the value to be searched for
	
	Function: int findEasy(const vector<solverNode>& v, const solverNode x)
	Returns the index within v at which x is located.  Returns -1 if x not found.
	Differs from the above function by disregarding x's source and trying to match
	either side of x's edge to the values in v.
	
		Parameters:
		v - the vector to be searched
		c - the value to be searched for
	
	Function: int find(const vector<node*>& v, const node* x)
	Returns the index within v at which x is located.  Returns -1 if x not found
	
		Parameters:
		v - the vector to be searched
		c - the value to be searched for
	
	Function: int find(const vector<edge*>& v, const edge* x)
	Returns the index within v at which x is located.  Returns -1 if x not found
	
		Parameters:
		v - the vector to be searched
		c - the value to be searched for
	
	Class: Route
	Simple container class		
	
	Function: void print()
	Prints out the path contained in route in a coherent fashion
	
	Function: void fillValues();
	If path contains properly initialialized solvedNodes, this function will 
	calculate time, miles, and mph.
*/
#ifndef SOLVER_H
#define SOLVER_H
#include "graph.h"
#include <string>
#include <set>
#include <vector>

class edge;
class graph;

struct solverNode
{
	node* m_source;
	edge* m_edge;
};

class route
{
	public:
	double time; //total
	double miles; //total
	double mph; //average of, naturally
	vector<solverNode> path;
	
	void print();
	void fillValues();
};


route shortestPath(string start, string finish, graph map);
int find(const vector<solverNode>& v, const solverNode x);
int findEasy(const vector<solverNode>& v, const solverNode x);
int find(const vector<node*>& v, const node* x);
int find(const vector<edge*>& v, const edge* x);

#endif
