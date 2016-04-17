/*
  File: array.hpp
  Templated function implementations for the array class
*/


template<typename generic>
Array<generic>::Array(): m_size(0), m_max_size(20)
{
}

template<typename generic>
void Array<generic>::push_back(generic x)
{
  if(m_size < m_max_size)
  {
    m_data[m_size++] = x;
  }
}

template<typename generic>
void Array<generic>::pop_back()
{
  if(m_size > 0)
  {
    m_size--;
  }
}

template<typename generic>
void Array<generic>::clear()
{
  m_size = 0;
}

template<typename generic>
generic& Array<generic>::operator[](unsigned int p)
{
  if(p >= m_size)
  {
    throw out_of_range
    (
      "This index position does not exist within the scope of the array."
    );
  }
  return m_data[p];
}

template<typename generic>
const generic& Array<generic>::operator[](unsigned int p) const
{
  if(p >= m_size)
  {
    throw out_of_range
    (
      "This index position does not exist within the scope of the array."
    );
  }
  return m_data[p];
  
}

template<typename generic>
unsigned int Array<generic>::size() const
{
  return m_size;
}

template<typename generic>
unsigned int Array<generic>::max_size() const
{
  return m_max_size;
}
