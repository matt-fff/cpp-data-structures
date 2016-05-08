/*
  File: priority_queue.h
  Author: Matthew White CS153 B
  Contains the priority queue container class prototypes
*/
/*
  Class: Priority Queue
  A priority queue container.
  
  Constructor:
  Calls the BT container constructor
  
  Copy Constructor:
  Calls the BT copy constructor
  
  Function: Priority_queue& operator=(const Priority_queue &)
  Calls the BT assignment operator
  
  Function: void push(generic)
  Creates a new node containing the parameter value and adds it to the 
  bottom right slot in the queue, reorganizing afterwards
  
	Parameter:
	The value to be added to the queue
  
  Function: void pop()
  Removes the top (and highest value) node in the queue and reorganizes the queue
  Ignores request if empty.
  
  Function: const generic& top() const
  Returns the value m_root holds, the highest value node in the queue.
  Throws out of range exception if the queue is empty

  Function: void setDepth(BTN<generic>* x)
  Sets the depth of the node
  
	Parameters:
	x - the node which needs its depth set
  
  Function: void promoteNodesPop(BTN<generic>* x)
  Moves from the given node downward, moving values after a pop
  
	Parameters:
	x - the base node for the comparisons downward
  
  Function: void promoteNodesPush(BTN<generic>* x)
  Moves from given node upwards, switching greater values upward
  
	Parameters:
	x - the base node for the corrections upward
  
  Function: void swap(BTN<generic>* a, BTN<generic>* b)
  Swaps the data pointers stored in a and b
  
	Parameters:
	a, b - the nodes whose data is to be switched
	
  Function: void recursiveCopy(BTN<generic>* x)
  Works recursively down from node x, pushing the values of the bottom
  nodes before pushing those of the upper
  
	Parameters:
	x - the tree will be copied from this point downward  
*/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include"bt.h"
#include"btn.h"

template<typename generic>
class Priority_queue : public BT<generic>
{
 public:
  Priority_queue();
  Priority_queue(const Priority_queue &);
  Priority_queue& operator=(const Priority_queue &);
  void push(generic);      
  void pop();
  const generic& top() const;
  int size();

 private:
  void setDepth(BTN<generic>* x);
  void promoteNodesPop(BTN<generic>* x);
  void promoteNodesPush(BTN<generic>* x);
  void swap(BTN<generic>* a, BTN<generic>* b);
  void recursiveCopy(BTN<generic>* x);
  BTN<generic>* m_push;
  BTN<generic>* m_pop;
};

#include"priority_queue.hpp"
#endif
