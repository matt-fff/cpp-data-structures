/*
  File: btpostorderiterator.hpp
  Author: Matthew White CS153 B
  Contains the implementations for the postorder iterator for the bt class
*/
template <class generic>
BTPostorderIterator<generic>::BTPostorderIterator(): m_current(NULL)
{
}

template <class generic>
BTPostorderIterator<generic>::BTPostorderIterator(BTN<generic> * x): m_current(x)
{
}

template <class generic>
bool BTPostorderIterator<generic>::operator== (const BTPostorderIterator& rhs) const
{
  return m_current == rhs.m_current;
}
template <class generic>
bool BTPostorderIterator<generic>::operator!= (const BTPostorderIterator& rhs) const
{
  return m_current != rhs.m_current;
}

template <class generic>
const generic& BTPostorderIterator<generic>::operator* ()
{
  return *(m_current->data);
}

template <class generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ (int)
{
  return ++(*this);
}

template <class generic>
BTPostorderIterator<generic> BTPostorderIterator<generic>::operator++ ()
{
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
  return *this;
}
