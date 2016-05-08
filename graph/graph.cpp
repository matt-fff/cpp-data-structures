/*
  File: graph.cpp
  Author: Matthew White CS153 B
  Contains the graph container class implementations
*/
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include "graph.h"
#include <iostream>

using std::cout;
using std::endl;

graph::graph()
{
}

graph::graph(const graph& p_graph)
{
	*this = p_graph;
}

graph& graph::operator=(const graph& p_graph)
{	
	for(set<node*>::iterator k = p_graph.nodes.begin(); k != p_graph.nodes.end(); k++)
	{
		for(set<edge*>::iterator j = (*k)->edges.begin(); j != (*k)->edges.end(); j++)
		{
			//since we will visit each edge twice, we need to check for redundancy
			if(find((*j)->l->name,(*j)->r->name, (*j)->mph, (*j)->miles) == NULL)
			{
				insertEdge((*j)->l->name,(*j)->r->name, (*j)->mph, (*j)->miles);
			}
		}
	}
}

graph::graph(fstream& fin)
{
	while(fin.good())
	{
		//this loop ignores the irrelevent stuff
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
    
		if(fin.good())
		{
			insertFromFile(fin);
		}
	}
}

graph::~graph()
{
	while(!nodes.empty())
	{
		removeNode(*(nodes.begin()));
	}
}

void graph::insertEdge(string p_left, string p_right, double p_mph, double p_miles)
{
	//redundancy is allowed for edges
	edge* thisEdge = new edge();
	
	thisEdge->mph = p_mph;
	thisEdge->miles = p_miles;
	thisEdge->time = p_miles/p_mph;
	
	if(find(p_left) != NULL)
	{
		thisEdge->l = find(p_left);
	}
	else
	{
		thisEdge->l = new node;
		thisEdge->l->name = p_left;
		insertNode(thisEdge->l);
	}
	
	if(find(p_right) != NULL)
	{
		thisEdge->r = find(p_right);
	}
	else
	{
		thisEdge->r = new node;
		thisEdge->r->name = p_right;
		insertNode(thisEdge->r);
	}
		
	if(thisEdge->l->find(thisEdge) == NULL)
	{
		thisEdge->l->edges.insert(thisEdge);
	}
	if(thisEdge->r->find(thisEdge) == NULL)
	{
		thisEdge->r->edges.insert(thisEdge);
	}
}

void graph::insertNode(string p_node)
{
	//redundancy not allowed
	if(find(p_node) == NULL)
	{
		node* temp = new node;
		temp->name = p_node;
		
		nodes.insert(temp);
	}
}

void graph::insertNode(node* p_node)
{
	if(p_node != NULL && find(p_node->name) == NULL)
	{
		nodes.insert(p_node);
	}
}

void graph::removeEdge(edge* p_edge)
{
	if(p_edge != NULL)
	{		
		if(p_edge->l != NULL)
		{
			p_edge->l->edges.erase(p_edge);
		}
		if(p_edge->r != NULL)
		{
			p_edge->r->edges.erase(p_edge);
		}

		delete p_edge;
	}	
}

void graph::removeNode(node* p_node)
{	
	if(p_node != NULL)
	{		
		//removes all the edges which cease to exist after the node is destroyed
		while(!(p_node->edges.empty()))
		{
			removeEdge(*(p_node->edges.begin()));
		}		
		
		nodes.erase(p_node);
		delete p_node;
	}
}

node* graph::find(string p_name)
{
	set<node*>::iterator current;
	
	for(current = nodes.begin();
		current != nodes.end() &&
		(*current)->name != p_name; 
		current++){}
		
	if(current != nodes.end())
	{
		return *current;
	}
	return NULL;
}

edge* graph::find(string p_left, string p_right, double p_mph, double p_miles)
{	
	if(find(p_left) != NULL && find(p_right) != NULL)
	{	
		set<edge*>::iterator current;
	
		//iterates through until it matches
		for(current = find(p_left)->edges.begin();
			current != find(p_left)->edges.end() &&
			((*current)->mph != p_mph ||
			(*current)->miles != p_miles); 
			current++){}
		
		if(current != find(p_left)->edges.end())
		{
			return *current;
		}
	}
	return NULL;
}

void graph::insertFromFile(fstream& fin)
{
	string source, target;
	string tempEdges, tempMph, tempMiles;
	int sourceEdges;
	double mph, miles;
	
	//get the source
	while(fin.good() 
		&& fin.peek() != ' '
		&& fin.peek() != '\t'
		&& fin.peek() != '\n')
	{
		source.push_back(fin.get());
	}
	
	//skip past nonsense
	while(fin.good() 
		&& (fin.peek() == ' '
		|| fin.peek() == '\t'
		|| fin.peek() == '\n'))
	{
		fin.ignore();
	}
	
	//get the number of edges
	while(fin.good() 
		&& fin.peek() != ' '
		&& fin.peek() != '\t'
		&& fin.peek() != '\n')
	{
		tempEdges.push_back(fin.get());
	}
	sourceEdges = atoi(tempEdges.c_str());
	
	//get all of the destinations and their cost
	for(int k = 0; k < sourceEdges; k++)
	{
		//skip past nonsense
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
		
		//get the target
		while(fin.good() 
			&& fin.peek() != ' '
			&& fin.peek() != '\t'
			&& fin.peek() != '\n')
		{
			target.push_back(fin.get());
		}
		
		//skip past nonsense
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
		
		//get the distance
		while(fin.good() 
			&& fin.peek() != ' '
			&& fin.peek() != '\t'
			&& fin.peek() != '\n')
		{
			tempMiles.push_back(fin.get());
		}
		miles = atof(tempMiles.c_str());
		
		//skip past nonsense
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
		
		//get the mph
		while(fin.good() 
			&& fin.peek() != ' '
			&& fin.peek() != '\t'
			&& fin.peek() != '\n')
		{
			tempMph.push_back(fin.get());
		}
		mph = atof(tempMph.c_str());
		
		insertEdge(source, target, mph, miles);
		tempMph = tempMiles = target = "";
	}
}

void graph::print()
{
	cout << endl;
	for(set<node*>::iterator k = nodes.begin(); k != nodes.end(); k++)
	{
		cout << "From: " << (*k)->name << endl;
		for(set<edge*>::iterator j = (*k)->edges.begin(); j != (*k)->edges.end(); j++)
		{
			string destination = (*j)->l != *k ? (*j)->l->name : (*j)->r->name;
			
			cout << "To: " << destination << " | time: " << (*j)->time << " | mph: " << (*j)->mph << " | miles: " << (*j)->miles << endl;
		}
	}
}


set<node*>::iterator graph::beginNode() const
{
	return nodes.begin();
}

set<node*>::iterator graph::endNode() const
{
	return nodes.end();
}

edgeIterator graph::beginEdge() const
{
	return EdgeIterator(*this);
}

edgeIterator graph::endEdge() const
{
	return EdgeIterator();
}

