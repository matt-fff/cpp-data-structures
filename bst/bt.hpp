/*
  File: bt.hpp
  Author: Matthew White CS153 B
  Contains the implementations for the bt container class
*/
template<typename generic>
BT<generic>::BT():m_root(NULL), m_size(0)
{
}

template<typename generic>
BT<generic>::BT(const BT& c):m_root(NULL), m_size(0)
{
  *this = c;
}

template<typename generic>
BT<generic>::~BT()
{
  clear();
}

template<typename generic>
BT<generic>& BT<generic>::operator=(const BT& rhs)
{
  BTInorderIterator<generic> k;
 
  for(k = rhs.in_begin(); k != rhs.in_end(); k++)
  {
    insert(*k);
  }
}

template<typename generic>
void BT<generic>::clear()
{
  BTN<generic>* m_current = m_root;
  
  //finds first node
  do
  {
	while(m_current != NULL && m_current->l != NULL)
	{
	  m_current = m_current->l;
  	}
	if(m_current != NULL && m_current->r != NULL)
	{
	  m_current = m_current->r;
	}
  }while(m_current != NULL && (m_current->r != NULL || m_current->l != NULL));
  
  //iterates through nodes, destroying along the way
  while(m_current != NULL)
  {
    BTN<generic>* deleteMe = m_current;
    if(m_current != NULL 
    && m_current->p  != NULL 
    && m_current->p->r != NULL 
    && m_current->p->r != m_current)
    {
      m_current = m_current->p->r;
	
	  do
	  {
	    while(m_current != NULL && m_current->l != NULL)
	    {
	      m_current = m_current->l;
  	    }
	    if(m_current != NULL && m_current->r != NULL)
	    {
	      m_current = m_current->r;
	    }
	  }while(m_current != NULL && (m_current->r != NULL || m_current->l != NULL));
    }
    else if(m_current != NULL)
    {
      m_current = m_current->p;
    }
	
	if(deleteMe != NULL)
	{
	  delete deleteMe->data;
	}
	delete deleteMe;
  }
  if(m_current != NULL)
  {
    delete m_current->data;
  }
  delete m_current;
}

template<typename generic>
bool BT<generic>::empty() const
{
  return (m_size == 0);
}

template<typename generic>
unsigned int BT<generic>::size() const
{
  return m_size;
}

template<typename generic>
BTPreorderIterator<generic> BT<generic>::pre_begin() const
{
  return BTPreorderIterator<generic>(m_root);
}

template<typename generic>
BTPreorderIterator<generic> BT<generic>::pre_end() const
{
  return NULL;
}

template<typename generic>
BTInorderIterator<generic> BT<generic>::in_begin() const
{
  BTN<generic>* begin = m_root;
  
  while(begin != NULL && begin->l != NULL)
  {
    begin = begin->l;
  }

  return BTInorderIterator<generic>(begin);
}

template<typename generic>
BTInorderIterator<generic> BT<generic>::in_end() const
{
  return NULL;
}

template<typename generic>
BTPostorderIterator<generic> BT<generic>::post_begin() const
{
  BTN<generic>* begin = m_root;
  do
  {
	while(begin != NULL && begin->l != NULL)
	{
	  begin = begin->l;
  	}
	if(begin != NULL && begin->r != NULL)
	{
	  begin = begin->r;
	}
  }while(begin != NULL && (begin->r != NULL || begin->l != NULL));
  
  
  return BTPostorderIterator<generic>(begin);
}

template<typename generic>
BTPostorderIterator<generic> BT<generic>::post_end() const
{
  return NULL;
}

template<typename generic>
void BT<generic>::insert(generic x)
{
  BTN<generic>* temp = new BTN<generic>;
  temp->data = new generic;
  *(temp->data) = x;
  temp->p = NULL;
  temp->l = NULL;
  temp->r = NULL;
  
  //deals with empty BST
  if(m_root == NULL)
  {
    m_root = temp;
  }
  else
  {
    bool unfinished = true;
    BTN<generic>* temp1 = m_root;
    while(unfinished)
	{
      //deals with less than case
	  if(*(temp1->data) > x)
	  {
	    if(temp1->l != NULL)
		{
		  temp1 = temp1->l;
		}
		else
		{
		  temp1->l = temp;
		  temp->p = temp1;
		  unfinished = false;
		}
	  }
      //deals with greater than case
	  else if(*(temp1->data) < x)
	  {
	    if(temp1->r != NULL)
		{
		  temp1 = temp1->r;
		}
		else
		{
		  temp1->r = temp;
		  temp->p = temp1;
		  unfinished = false;
		}
	  }
      //deals with identical case
      else if(*(temp1->data) == x)
      {
        unfinished = false;
        m_size--;//to offset the inevitable increment at the end
		
		delete temp->data;//these two lines were all that were 
		delete temp;      //missing in the original submission
      }
	}
  }
  m_size++;
}
