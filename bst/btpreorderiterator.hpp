/*
  File: btpreorderiterator.hpp
  Author: Matthew White CS153 B
  Contains the implementations for the preorder iterator for the bt class
*/
template <class generic>
BTPreorderIterator<generic>::BTPreorderIterator(): m_current(NULL)
{
}

template <class generic>
BTPreorderIterator<generic>::BTPreorderIterator(BTN<generic> * x): m_current(x)
{
}

template <class generic>
bool BTPreorderIterator<generic>::operator== (const BTPreorderIterator& rhs) const
{
  return m_current == rhs.m_current;
}
template <class generic>
bool BTPreorderIterator<generic>::operator!= (const BTPreorderIterator& rhs) const
{
  return m_current != rhs.m_current;
}

template <class generic>
const generic& BTPreorderIterator<generic>::operator*()
{
  return *(m_current->data);
}

template <class generic>
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ (int)
{
  return ++(*this);
}

template <class generic>
BTPreorderIterator<generic> BTPreorderIterator<generic>::operator++ ()
{
  if (m_current->l != NULL)
  {
    m_current= m_current->l;
  }
  else if (m_current->l == NULL && m_current->r != NULL) 
  {
    m_current= m_current->r;
  }
  else
  {
    while (m_current->p != NULL && ((m_current->p->r != NULL &&
		   m_current->p->r == m_current) || m_current->p->r == NULL))
    {
      m_current= m_current->p;
    }
	
    if (m_current->p != NULL)
    {
      m_current= m_current->p->r;
    }
    else
	{
      m_current= NULL;
    }
  }
  return *this;
}
