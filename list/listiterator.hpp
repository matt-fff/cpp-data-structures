/*
File: listiterator.hpp
Author: Matthew White CS153 B
Contains the templated implementations for the listiterator class
*/
template<typename generic>
ListIterator<generic>::ListIterator() : m_current(NULL)
{
}

template<typename generic>
ListIterator<generic>::ListIterator(Node<generic>* n) : m_current(n)
{
}

template<typename generic>
generic& ListIterator<generic>::operator*()
{
  if(m_current == NULL)
  {
    throw out_of_range
    (
     "Iterator is not currently on a node."
     );
  }
  return m_current->data;
}

template<typename generic>
const generic& ListIterator<generic>::operator*() const
{
  if(m_current == NULL)
  {
    throw out_of_range
    (
     "Iterator is not currently on a node."
     );
  }
  return m_current->data;
}

template<typename generic>
ListIterator<generic> ListIterator<generic>::operator++()
{
  if(m_current != NULL)
  {
    m_current = m_current->b;
  }
  
  return *this;
}

template<typename generic>
ListIterator<generic> ListIterator<generic>::operator++(int)
{
  return ++(*this);
}

template<typename generic>
ListIterator<generic> ListIterator<generic>::operator--()
{
  if(m_current != NULL)
  {
    m_current = m_current->f;
  }
  
  return *this;
}

template<typename generic>
ListIterator<generic> ListIterator<generic>::operator--(int)
{
  return --(*this);
}

template<typename generic>
bool ListIterator<generic>::operator==(const ListIterator& l) const
{
  return (m_current == l.m_current);
}

template<typename generic>
bool ListIterator<generic>::operator!=(const ListIterator& l) const
{
  return (m_current != l.m_current);
}
