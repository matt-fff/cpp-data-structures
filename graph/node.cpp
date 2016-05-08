/*
  File: node.cpp
  Author: Matthew White CS153 B
  Contains the node container class implementations
*/

#include "node.h"

node::node() : name("")
{
}


node::node(const node& c)
{
	*this = c;
}


node::~node()
{
	//removes all the edges which cease to exist after the node is destroyed
	for(set<edge*>::iterator k = edges.begin(); k != edges.end();)
	{
		set<edge*>::iterator j = k;
		k++;
			
		edges.erase(*j);	}		
}

node& node::operator=(const node& rhs)
{
	edges = rhs.edges;
	name = rhs.name;
}

edge* node::find(edge* x)
{
	set<edge*>::iterator current;
	
	for(current = edges.begin();
		current != edges.end() &&
		*(*current) != *x; 
		current++){}
		
	if(current != edges.end())
	{
		return *current;
	}
	else
	{
		return NULL;
	}
}
