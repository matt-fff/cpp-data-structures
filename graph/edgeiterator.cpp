/*
  File: edgeiterator.cpp
  Author: Matthew White CS153 B
  Contains the edgeiterator class implementations
*/
#include "edgeiterator.h"
#include <iostream>

using std::cout;
using std::endl;

edgeIterator::edgeIterator() : m_graph(NULL), m_parent(set<node*>().end()), m_current(set<edge*>().end())
{
}
	
edgeIterator::edgeIterator(const graph& map) : m_graph(new graph()), m_parent(set<node*>().end()), m_current(set<edge*>().end())
{
	*m_graph = map;
	m_parent = m_graph->nodes.begin();
	if(m_parent != m_graph->nodes.end())
	{		m_current = (*m_parent)->edges.begin();
	}
		
	//avoids repeated edges
	if(!ended() && (*m_current)->l != *m_parent)
	{
		operator++();
	}
}

/*
edgeIterator::~edgeIterator()
{
	delete m_graph;
}*/

edge* edgeIterator::operator*()
{
	if(!ended())
	{
		return *m_current;
	}
	
	return NULL;
}

edgeIterator edgeIterator::operator++()
{
	if(!ended())
	{
		//checks if we're at the end and loops to avoid repeated edges 
		do
		{
			//increments current edge
			m_current++;		
		
			//if edge is now at the end, we move to the next node
			if(m_current == (*m_parent)->edges.end())
			{
				m_parent++;
			
				//reassigns m_current to the new node's starting edge
				if(m_parent != (m_graph->nodes.end()))
				{
					m_current = (*m_parent)->edges.begin();
				}
				else
				{
					m_current = set<edge*>().end();
				}
			}
		}while(!ended() && (*m_current)->l != *m_parent);
	}
}

edgeIterator edgeIterator::operator++(int)
{
	return ++(*this);
}

bool edgeIterator::operator==(const edgeIterator& x) const
{
	return (m_current == x.m_current && m_parent == x.m_parent);
}

bool edgeIterator::operator!=(const edgeIterator& x) const
{
	return !(operator==(x));
}

bool edgeIterator::ended()
{
	bool end = (m_current == set<edge*>().end() || m_parent == set<node*>().end() || m_graph == NULL);
	
	if(!end)
	{
		end = (end || m_parent == m_graph->nodes.end() || m_current == (*m_parent)->edges.end());
	}
	
	return end;
}
