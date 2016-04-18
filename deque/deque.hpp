/*
  File: deque.hpp
  Contains the deque class's templated implementations
*/
template<typename generic>
Deque<generic>::Deque(): m_data(NULL), m_size(0), m_blocks(1), m_block_size(3)
{
  m_data = new Block<generic>*[m_blocks];
  m_data[0] = new Block<generic>(m_block_size);
}

template<typename generic>
Deque<generic>::Deque(unsigned int n): m_data(NULL), m_size(0), m_blocks(1), m_block_size(n)
{
  if(n == 0)
  {
    throw invalid_argument(
	"AHHH! MY EYES ARE BURNING BECAUSE YOU'RE TRYING TO MAKE A 0 SIZE BLOCK!");
  }
  
  m_data = new Block<generic>*[m_blocks];
  m_data[0] = new Block<generic>(m_block_size);
}

template<typename generic>
Deque<generic>::Deque(Deque<generic>& d): m_data(NULL), m_size(0), m_blocks(1), m_block_size(3)
{
  m_data = new Block<generic>*[m_blocks];
  m_data[0] = new Block<generic>(m_block_size);
  *this = d;
}

template<typename generic>
Deque<generic>::~Deque()
{
  clear();
  
  delete m_data[0];
  delete [] m_data;
}

template<typename generic>
void Deque<generic>::push_front(generic x)
{
  if(m_data[0]->ffull())//if we run out of room, make more
  {
    Block<generic>** temp = m_data;
    m_data = new Block<generic>*[++m_blocks];
    m_data[0] = new Block<generic>(m_block_size);
    for(unsigned k = 1; k < m_blocks; k++)
    {
      m_data[k] = temp[k-1];
    }
    delete [] temp;
  }
  if(!m_data[0]->ffull())
  {
  m_data[0]->push_front(x);
  m_size++;
  }
}

template<typename generic>
void Deque<generic>::pop_front()
{
  if(m_blocks > 1 && m_data[0]->empty())//if the first block is empty when
  {                                     //we try to pop, we get rid of it
    Block<generic>** temp = m_data;
    m_data = new Block<generic>*[--m_blocks];
    for(unsigned k = 0; k < m_blocks; k++)//copies everything
    {
      m_data[k] = temp[k+1];
    }
	delete temp[0];//we delete the lone block
    delete [] temp;//we delete the pointer
  }  
  m_data[0]->pop_front();
  if(!empty())
  {
    m_size--;
  }
}

template<typename generic>
void Deque<generic>::push_back(generic x)
{
  if(m_data[m_blocks-1]->bfull())//if we run out of room, make more
  {
    Block<generic>** temp = m_data;
    m_data = new Block<generic>*[++m_blocks];
    m_data[m_blocks-1] = new Block<generic>(m_block_size);
    for (unsigned int k = 0; k < m_blocks - 1; k++)
    {
      m_data[k] = temp[k];
    }
    delete [] temp;
  }
  m_data[m_blocks-1]->push_back(x);
  m_size++;
}

template<typename generic>
void Deque<generic>::pop_back()
{
  if(m_blocks > 1 && m_data[m_blocks-1]->empty())//if the last block is empty when
  {                                              //we try to pop, we get rid of it
    Block<generic>** temp = m_data;
    m_data = new Block<generic>*[--m_blocks];
    for (unsigned int k = 0; k < m_blocks; k++)//copies everything
    {
      m_data[k] = temp[k];
    }
	delete temp[m_blocks];//we delete the lone block
    delete [] temp;//we delete the pointer
  }
  
  m_data[m_blocks-1]->pop_back();
  if(!empty())
  {
    m_size--;
  }
}

template<typename generic>
void Deque<generic>::clear()
{
  while(!empty())
  {
    pop_back();
  }
}

template<typename generic>
Deque<generic>& Deque<generic>::operator=(const Deque<generic>& d)
{
  if(!d.empty())
  {
    clear();
    delete m_data[0];//removes initial block

    m_block_size = d.m_block_size;
  
    m_data[0] = new Block<generic>(m_block_size);
    for(unsigned k = 0; k < d.m_size; k++)
    {
      push_back(d[k]);//a simple, deep copy
    }
  }
}

template<typename generic>
generic& Deque<generic>::operator[](unsigned int p)
{
  if(empty() || p >= m_size)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
  
  unsigned dq_index = p/m_block_size;//starts out simple enough
  unsigned block_index = p%m_block_size;
  if(!empty() &&
    (m_data[0]->empty() || //compensates for an empty front block
	(m_data[0]->size() <= p &&           //compensates for weird sizes
	 m_data[0]->size() != m_block_size)))//in the first block that can
  {                                      //throw off dq_index
    dq_index++;
  }
  if(!empty() && dq_index > 0 && m_data[0]->size() <= p)//compensates for weird sizes
  {                                                     //in the first block that can
	block_index -= m_data[0]->size()%m_block_size;      //throw off block_index
  }
  
  try
  {
    return m_data[dq_index]->operator[](block_index);
  }
  catch(out_of_range& e)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
}

template<typename generic>
const generic& Deque<generic>::operator[](unsigned int p) const
{
  if(empty() || p >= m_size)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
  
  unsigned dq_index = p/m_block_size;//starts out simple enough
  unsigned block_index = p%m_block_size;
  if(!empty() &&
    (m_data[0]->empty() || //compensates for an empty front block
	(m_data[0]->size() <= p &&           //compensates for weird sizes
	 m_data[0]->size() != m_block_size)))//in the first block that can
  {                                      //throw off dq_index
    dq_index++;
  }
  if(!empty() && dq_index > 0 && m_data[0]->size() <= p)//compensates for weird sizes
  {                                                     //in the first block that can
	block_index -= m_data[0]->size()%m_block_size;      //throw off block_index
  }
  
  try
  {
    return m_data[dq_index]->operator[](block_index);
  }
  catch(out_of_range& e)
  {
    throw out_of_range
	(
	  "You wound me, sir, with your attempts to access an invalid index"
	);
  }
}

template<typename generic>
unsigned int Deque<generic>::size() const
{
  return m_size;
}

template<typename generic>
unsigned int Deque<generic>::block_size() const
{
  return m_block_size;
}

template<typename generic>
bool Deque<generic>::empty() const
{
  return (m_size == 0);
}
