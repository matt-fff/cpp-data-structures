/*
  File: block.hpp
  Contains templated implementations for the block class
*/
template<typename generic>
Block<generic>::Block() : m_data(NULL), m_size(0), m_max_size(3), m_front(-1)
{
  m_data = new generic[m_max_size];
}

template<typename generic>
Block<generic>::Block(unsigned int n) : m_data(NULL), m_size(0), m_max_size(n), m_front(-1)
{
  m_data = new generic[m_max_size];
}

template<typename generic>
Block<generic>::Block(Block& b): m_data(NULL), m_size(0), m_max_size(3), m_front(-1)
{
 *this = b;
}

template<typename generic>
Block<generic>& Block<generic>::operator=(const Block<generic>& b)
{
  generic* temp;
  temp = m_data;
  clear();
  m_data = NULL;
  delete [] temp;
  
  m_front = b.m_front;
  m_size = b.m_size;
  m_max_size = b.m_max_size;
  
  m_data = new generic[m_max_size];
  
  for(int k = 0; k < m_size; k++)
  {
    operator[](k) = b[k];
  }
}

template<typename generic>
Block<generic>::~Block()
{
  clear();
  delete [] m_data;
}

template<typename generic>
void Block<generic>::push_front(generic x)
{
  if(!ffull())//ignores a front full list
  {
    if(empty())//if empty, we start on the farmost right
    {
      m_data[m_max_size-1] = x;
	  m_front = m_max_size-1;
    }
	else//if not empty, we just place to the left of m_front
	{
	  m_data[--m_front] = x;
	}
	m_size++;
  }
}

template<typename generic>
void Block<generic>::pop_front()
{
  if(!empty())
  {
    m_size--;
	if(!empty())
	{
	  m_front++;
	}
	else
	{
	  m_front = -1;
	}
  }
}

template<typename generic>
void Block<generic>::push_back(generic x)
{
  if(!bfull())//ignores a back full list
  {
    if(empty())//if empty, we start on the farmost left
    {
	  m_front = 0;
      m_data[m_front] = x;
    }
	else//if not empty, we just place to the right of m_front
	{
	  m_data[m_front + m_size] = x;
	}
	m_size++;
  }
}

template<typename generic>
void Block<generic>::pop_back()
{
  if(!empty())
  {
    m_size--;
	if(empty())
	{
	  m_front = -1;
	}
  }
}

template<typename generic>
void Block<generic>::clear()
{
  while(!empty())
  {
    pop_back();
  }
}

template<typename generic>
generic& Block<generic>::operator[](unsigned int p)
{
  if(empty() || p >= m_size)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
  else
  {
    return m_data[m_front + p];
  }
}

template<typename generic>
const generic& Block<generic>::operator[](unsigned int p) const
{
  if(empty() || p >= m_size)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
  else
  {
    return m_data[m_front + p];
  }
}

template<typename generic>
unsigned int Block<generic>::size() const
{
  return m_size;
}

template<typename generic>
unsigned int Block<generic>::max_size() const
{
  return m_max_size;
}

template<typename generic>
bool Block<generic>::ffull() const
{
  return (m_front == 0);
}

template<typename generic>
bool Block<generic>::bfull() const
{
  return (!empty() && (m_front + m_size) >= m_max_size);
}

template<typename generic>
bool Block<generic>::empty() const
{
  return (m_size == 0);
}
