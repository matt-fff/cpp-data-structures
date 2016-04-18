/*
  File: slist.hpp
  Contains the templated implementations for the slist class
*/

template<typename generic>
SList<generic>::SList() : m_size(0), m_front(NULL)
{
}

template<typename generic>
SList<generic>::SList(const SList& s) : m_size(0), m_front(NULL)
{
  *this = s;
}

template<typename generic>
SList<generic>::~SList()
{
  clear();
}

template<typename generic>
void SList<generic>::push_front(generic x)
{
  SNode<generic> *temp = new SNode<generic>;
  temp->b = m_front;
  m_front = temp;
  m_front->data = x;
  
  m_size++;
}

template<typename generic>
void SList<generic>::pop_front()
{
  if(m_front != NULL)//ignores in empty list
  {
    SNode<generic> *temp = m_front;
    m_front = temp->b;
  
    delete temp;
	
	m_size--;
  }
}

template<typename generic>
void SList<generic>::remove(generic x)
{
  if(!empty())//ensures list not empty
  {	
    //deals with any x's on the front
	while(m_front != NULL && m_front->data == x)
	{
	  pop_front();
	}
	
	SNode<generic> *temp = m_front;
	SNode<generic> *temp2;
	//deals with any x's not on the front
	while(temp != NULL && temp->b != NULL)
	{
	  temp2 = temp->b;
	  if(temp2->data == x)
	  {
	    temp->b = temp2->b;
		delete temp2;
	  }
	  else
	  {
	    temp = temp->b;
	  }
	}
  }
}

template<typename generic>
generic& SList<generic>::front()
{
  if(m_front == NULL)
  {
    throw out_of_range
	(
	  "The SList is currently empty!"
	);
  }
  return m_front->data;
}

template<typename generic>
const generic& SList<generic>::front() const
{
  if(m_front == NULL)
  {
    throw out_of_range
	(
	  "The SList is currently empty!"
	);
  }
  else
  {
    return m_front->data;
  }
}

template<typename generic>
void SList<generic>::clear()
{
  while(m_front != NULL)
  {
    pop_front();
  }
}

template<typename generic>
unsigned int SList<generic>::size() const
{
  return m_size;
}

template<typename generic>
bool SList<generic>::empty() const
{
  return m_size == 0;
}

/*
Note: see implementations in slist.h
Encountered numerous errors when implementing here

template<typename generic>
Iterator SList<generic>::begin() const
{
  return Iterator(m_front);
}

template<typename generic>
Iterator SList<generic>::end() const
{
 return Iterator();
}*/

template<typename generic>
SList<generic>& SList<generic>::operator=(const SList<generic>& s)
{
  clear();
  
  if(!s.empty())//checks if empty
  {
    m_front = new SNode<generic>;
	SNode<generic> *temp = m_front;
	
	//copies everything!
	for(Iterator k = s.begin(); k != s.end(); m_size++, temp = temp->b)
	{
	  temp->data = *k;
	  k++ != s.end() ? temp->b = new SNode<generic> : temp->b = NULL;
	}
  }
  
  return *this;
}
