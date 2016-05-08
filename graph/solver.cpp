/*
  File: solver.cpp
  Author: Matthew White CS153 B
  Contains the solver implementations
*/
#include "solver.h"
#include <iostream>

using std::endl;
using std::cout;
using std::cerr;


void route::print()
{
	if(!path.empty())
	{
		string endLocation = path[path.size()-1].m_edge->l == path[path.size()-1].m_source 
	        						? path[path.size()-1].m_edge->r->name : path[path.size()-1].m_edge->l->name;	
	
		cout << "From: " << path[0].m_source->name
	    	  << "\tTo: " << endLocation << endl
		 	  << "Average mph: " << mph
		 	  << "\tTotal Miles: " << miles
			  << "\tTotal Time(h): " << time << endl;
		  
		for(int k = 0; k < path.size(); k++)
		{
			cout << path[k].m_source->name << "->";
		}
	
		//print final destination at the end
		cout << endLocation << endl;
	}
	else
	{
		cout << "Route empty" << endl;
	}
}

void route::fillValues()
{
	double totalMiles, totalMph, totalTime;
	totalMiles = totalMph = totalTime = 0;
	
	for(int k = 0; k < path.size(); k++)
	{
		totalMiles += path[k].m_edge->miles;
		totalMph += path[k].m_edge->mph;
		totalTime += path[k].m_edge->time;
	}
	
	time = totalTime;
	miles = totalMiles;
	mph = (totalMph/path.size());
}


//Think Dijkstra's Algorithm
route shortestPath(string start, string finish, graph map)
{
	vector<solverNode> edgesTaken;
	vector<node*> solvedNodes;
	vector<double> solvedCosts;
	node* begin = map.find(start);
	node* end = map.find(finish);
	
	solvedNodes.push_back(begin);
	solvedCosts.push_back(0);
	
	//while the end is not in our visited nodes and we haven't exhausted our set
	while(find(solvedNodes, end) == -1 && solvedNodes.size() < map.nodes.size())
	{
		solverNode cheap;
		cheap.m_edge = new edge;
		cheap.m_edge->time = std::numeric_limits<double>::max();
		
		//constructs a list of all viable paths
		for(int k = 0; k < solvedNodes.size(); k++)
		{
			for(set<edge*>::iterator j = solvedNodes[k]->edges.begin(); j != solvedNodes[k]->edges.end(); j++)
			{
				solverNode temp;
				temp.m_edge = *j;
				temp.m_source = solvedNodes[k];
				
				if(findEasy(edgesTaken, temp) == (-1))
				{
					if((solvedCosts[k] + temp.m_edge->time) < (cheap.m_edge->time))
					{
						//a little memory management
						if(cheap.m_edge->time == std::numeric_limits<double>::max())
						{
							delete cheap.m_edge;
						}
						
						cheap = temp;
					}
				}
			}
		}
		
		edgesTaken.push_back(cheap);
		

		if(find(solvedNodes, (cheap.m_edge->l == cheap.m_source ? cheap.m_edge->r : cheap.m_edge->l)) == -1)
		{
			//push back the node that isn't the source node
			solvedNodes.push_back(cheap.m_edge->l == cheap.m_source ? cheap.m_edge->r : cheap.m_edge->l);
		
			solvedCosts.push_back(solvedCosts[find(solvedNodes, cheap.m_source)] + cheap.m_edge->time);
		}
	}
	
	if(find(solvedNodes, end) == -1)
	{
		cerr << "The end node was never reached" << endl;
	}
		


	//now we actually have to construct the final path (in reverse) by following
	//the solver nodes to their sources until we hit the beginning
	vector<solverNode> reversedPath;
	reversedPath.push_back(edgesTaken[edgesTaken.size()-1]);
	
	while(reversedPath[reversedPath.size()-1].m_source != begin)
	{		
		bool found = false;
		for(int k = edgesTaken.size()-1; k >= 0 && !found; k--)
		{
			//if the target of the current edge is the source of the last push, we push it
			if((edgesTaken[k].m_edge->l == edgesTaken[k].m_source ? edgesTaken[k].m_edge->r : edgesTaken[k].m_edge->l)
			 == reversedPath[reversedPath.size()-1].m_source)
			{
				reversedPath.push_back(edgesTaken[k]);
				found = true;
			}
		}
	}
	
	route final;
	
	//we reverse the reversedPath into the real path in the final route
	for(int k = reversedPath.size()-1; k >= 0; k--)
	{
		final.path.push_back(reversedPath[k]);
	}
	
	final.fillValues();
	
	return final;
}
int find(const vector<solverNode>& v, const solverNode x)
{
	int index = -1;
	for(int k = 0; k < v.size(); k++)
	{
		if((v[k].m_source) == (x.m_source) &&
		   (v[k].m_edge) == (x.m_edge))
		{
			index = k;
			continue;
		}
	}
	
	return index;
}

int findEasy(const vector<solverNode>& v, const solverNode x)
{
	int index = -1;
	for(int k = 0; k < v.size(); k++)
	{
		if(((v[k].m_source) == (x.m_source) ||
		    (v[k].m_source) == (x.m_edge->l == x.m_source ? x.m_edge->r : x.m_edge->l)) &&
		    (v[k].m_edge) == (x.m_edge))
		{
			index = k;
			continue;
		}
	}
	
	return index;
}

int find(const vector<node*>& v, const node* x)
{
	int index = -1;
	for(int k = 0; k < v.size(); k++)
	{
		if(v[k] == x)
		{
			index = k;
			continue;
		}
	}
	
	return index;
}

int find(const vector<edge*>& v, const edge* x)
{
	int index = -1;
	for(int k = 0; k < v.size(); k++)
	{
		if(v[k] == x)
		{
			index = k;
			continue;
		}
	}
	
	return index;
}
