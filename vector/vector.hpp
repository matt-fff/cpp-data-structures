/*
  File: vector.hpp
  Contains the templated vector implementations
*/

template<typename generic>
Vector<generic>::Vector():m_size(0), m_max_size(1), m_data(NULL)
{
  m_data = new generic[m_max_size]; //creates single element array
}

template<typename generic>
Vector<generic>::Vector(const Vector& v):m_size(0), m_max_size(1), m_data(NULL)
{
  m_data = new generic[m_max_size]; //creates single element array
  *this = v;
}

template<typename generic>
Vector<generic>::~Vector()
{
  delete [] m_data; //clears m_data from memory
}

template<typename generic>
void Vector<generic>::push_back(generic x)
{
  if(m_max_size <= m_size)//if the max size needs increased
  {
    generic* temp = m_data;//for the transfer
    m_max_size *= 2;
	m_data = new generic[m_max_size];//new array of double size
	
	for(int k = 0; k < m_size; k++)
	{
	  m_data[k] = temp[k];//duplicates
	}
	delete [] temp;//clears from memory
  }
  
  m_data[m_size++] = x;//adds x to the array and increments size
}

template<typename generic>
void Vector<generic>::pop_back()
{
  if(m_size > 0)//ignores if already empty
  {
    m_size--;
	
    if(m_size == 0)//special case
    {	
	  generic* temp = m_data;
	  m_max_size = 1;
	  m_data = new generic[m_max_size]; //empty array
	
	  delete [] temp;
    }
    else if(m_size <= (m_max_size/4))//checks for scaling
    {
      generic* temp = m_data;
      m_max_size /= 2;
      m_data = new generic[m_max_size];
	
	  for(int k = 0; k < m_size; k++)
  	  {
	    m_data[k] = temp[k];//duplicates
	  }
	  delete [] temp;
    }
  }
}

template<typename generic>
void Vector<generic>::clear()
{
  generic* temp = m_data;
  m_max_size = 1;
  m_size = 0;
  m_data = new generic[m_max_size];
  
  delete [] temp;
}

template<typename generic>
unsigned int Vector<generic>::size() const
{
  return m_size;
}

template<typename generic>
unsigned int Vector<generic>::max_size() const
{
  return m_max_size;
}

template<typename generic>
Vector<generic>& Vector<generic>::operator=(const Vector& v)
{  
  clear();

  generic* temp = m_data;//for deletion
  m_max_size = v.max_size();
  m_size = v.size();
  m_data = new generic[m_max_size];
  
  for(int k = 0; k < m_size; k++)
  {
    m_data[k] = v[k];//duplicates
  }
  
  delete [] temp;
}

template<typename generic>
generic& Vector<generic>::operator[](unsigned int p)
{
  if(p >= m_size)//ensures the position is in the array
  {
    throw out_of_range
	(
      "This index position does not exist within the scope of the vector."
	);
  }
  return m_data[p];
}

template<typename generic>
const generic& Vector<generic>::operator[](unsigned int p) const
{
  if(p >= m_size)//ensures the position is in the array
  {
    throw out_of_range
	(
      "This index position does not exist within the scope of the vector."
	);
  }
  return m_data[p];
}
