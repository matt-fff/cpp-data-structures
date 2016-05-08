/*
  File: edge.cpp
  Author: Matthew White CS153 B
  Contains the edge container class implementations
*/

#include "edge.h"

edge::edge() : l(NULL), r(NULL),
 time(std::numeric_limits<double>::max()),
 mph(std::numeric_limits<double>::max()),
 miles(std::numeric_limits<double>::max())
{}


edge::~edge()
{	
	edge* temp = this;
	if(l != NULL)
	{
		l->edges.erase(temp);
	}
	if(r != NULL)
	{
		r->edges.erase(temp);
	}
}

edge::edge(const edge& c)
{
	*this = c;
}

edge& edge::operator=(const edge& rhs)
{
	*l = *(rhs.l);
	*r = *(rhs.r);
	time = rhs.time;
	mph = rhs.mph;
	miles = rhs.miles;
}

bool edge::operator==(const edge& rhs) const
{
	return (time == rhs.time 
		&& mph == rhs.mph 
		&& miles == rhs.miles 
		&& (l->name == rhs.l->name || l->name == rhs.r->name) 
		&& (r->name == rhs.l->name || r->name == rhs.r->name));
}

bool edge::operator!=(const edge& rhs) const
{
	return !(operator==(rhs));
}
