/*
File: queue.hpp
Author: Matthew White CS153 B
Contains templated implementations for the queue class
*/
template<typename generic>
Queue<generic>::Queue()
{
}

template<typename generic>
Queue<generic>::Queue(const Queue& q) : List<generic> (q)
{
}

template<typename generic> 
Queue<generic>::~Queue()
{
  clear();
}

template<typename generic>
Queue<generic>& Queue<generic>::operator=(const Queue& q)
{
  List<generic>::operator=(q);
  return *this;
}

template<typename generic>
bool Queue<generic>::empty() const
{
  return List<generic>::empty();
}

template<typename generic>
unsigned int Queue<generic>::size() const
{
  return List<generic>::size();
}

template<typename generic>
generic& Queue<generic>::front()
{
  if(!empty())
  {
    return List<generic>::front();
  }
  else
  {
    throw out_of_range
    (
     "The Queue is currently empty!"
     );
  }
}

template<typename generic>
generic& Queue<generic>::back()
{
  if(!empty())
  {
    return List<generic>::back();
  }
  else
  {
    throw out_of_range
    (
     "The Queue is currently empty!"
     );
  }
}

template<typename generic>
const generic& Queue<generic>::front() const
{
  if(!empty())
  {
    return List<generic>::front();
  }
  else
  {
    throw out_of_range
    (
     "The Queue is currently empty!"
     );
  }
}

template<typename generic>
const generic& Queue<generic>::back() const
{
  if(!empty())
  {
    return List<generic>::back();
  }
  else
  {
    throw out_of_range
    (
     "The Queue is currently empty!"
     );
  }
}

template<typename generic>
void Queue<generic>::push(generic x)
{
  List<generic>::push_back(x);
}

template<typename generic>
void Queue<generic>::pop()
{
  if(!empty())
  {
    List<generic>::pop_front();
  }
}

template<typename generic>
void Queue<generic>::clear()
{
  if(!empty())
  {
    List<generic>::clear();
  }
}
