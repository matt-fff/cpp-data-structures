/*
  File: btinorderiterator.hpp
  Author: Matthew White CS153 B
  Contains the implementations inorder iterator for the bt class
*/
template <class generic>
BTInorderIterator<generic>::BTInorderIterator(): m_current(NULL), m_end(NULL)
{
}

template <class generic>
BTInorderIterator<generic>::BTInorderIterator(BTN<generic> * x): m_current(x), m_end(NULL)
{
  set_end();
}

template <class generic>
bool BTInorderIterator<generic>::operator== (const BTInorderIterator& rhs) const
{
  return m_current == rhs.m_current;
}
template <class generic>
bool BTInorderIterator<generic>::operator!= (const BTInorderIterator& rhs) const
{
  return m_current != rhs.m_current;
}

template <class generic>
const generic& BTInorderIterator<generic>::operator* ()
{
  return *(m_current->data);
}

template <class generic>
BTInorderIterator<generic> BTInorderIterator<generic>::operator++ (int)
{
  return ++(*this);
}

template <class generic>
void BTInorderIterator<generic>::set_end()
{
  m_end = m_current;
  while(m_end != NULL && m_end->p != NULL)
  {
    m_end = m_end->p;
  }
  while(m_end != NULL && m_end->r != NULL)
  {
    m_end = m_end->r;
  }
}

template <class generic>
BTInorderIterator<generic> BTInorderIterator<generic>::operator++()
{  
  if(m_end == NULL)
  {
    set_end();
  }
  //deals with end case
  if(m_current != NULL && m_current == m_end)
  {
    m_current = NULL;
  }  
  //actually moves around
  else if(m_current != NULL && m_current->r != NULL)
  {
    m_current = m_current->r;
	
	while(m_current != NULL && m_current->l != NULL)
    {
	  m_current = m_current->l;
    }
  }
  else if(m_current != NULL 
  && m_current->p != NULL 
  && m_current->p->r != NULL
  && m_current->p->r == m_current)
  {
    m_current = m_current->p->p;
  }
  else if(m_current != NULL)
  {
    m_current = m_current->p;
  }
  
  return *this;
}
