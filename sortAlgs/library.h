/*
  File: library.h
  Contains prototypes for the sorting algorithms
*/
/*
  Function:quick_sort(vector<generic>& v)
  Utilizing stacks, sorts vector v using the quicksort algorithm
  
    Parameters:
	v - the vector to be sorted
	
  Function:merge_sort(vector<generic>& v)
  Utilizing stacks, sorts vector v using the mergesort algorithm
  
    Parameters:
	v - the vector to be sorted  
	
  Function:merge(vector<generic>& v, int f, int b)
  Splits vector v into two vectors and merges the resulting vectors together
  
    Parameters:
	v - vector to be merged
	f - front of the area to merge
	b - back of the area to merge
  
  
  Function:partition(vector<generic>& v, int f, int b)
  Sorts vector v by placing everything greater than the pivot after it and everything
  smaller than it before it.
  
    Parameters:
	v - vector to be partitioned
	f - front of the area to partition
	b - back of the area to partition
	
  Function:swap(vector<generic>& v, unsigned left, unsigned right)
  swaps elements left and right in vector v
  
    Parameters:
	v - vector to manipulate
	front - element to switch
	back - element to switch
*/
#ifndef LIBRARY_H
#define LIBRARY_H

#include<vector>
#include<stack>
#include<iostream>
using std::vector;
using std::stack;
using std::cerr;

template<typename generic>
void quick_sort(vector<generic>& v);

template<typename generic>
void merge_sort(vector<generic>& v);

template<typename generic>
void merge(vector<generic>& v, int f, int b);

template<typename generic>
int partition(vector<generic>& v, int f, int b);

template<typename generic>
void swap(vector<generic>& v, unsigned left, unsigned right);

#include"library.hpp"
#endif
