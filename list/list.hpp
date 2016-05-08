/*
  File: list.hpp
  Author: Matthew White CS153 B
  Contains templated implementations for the list class
*/
template<typename generic>
  List<generic>::List() : m_size(0), m_front(NULL), m_back(NULL)
  {
  }

template<typename generic>
  List<generic>::List(const List& l) : m_size(0), m_front(NULL), m_back(NULL)
  {
    *this = l;
  }

template<typename generic>
  List<generic>& List<generic>::operator=(const List& l)
  {
  clear(); //clears list
  
  if(!l.empty())
  {
    m_front = new Node<generic>;
    Node<generic> *temp = m_front;
    m_front->f = NULL;
    m_front->b = NULL;

    for(Iterator k = l.begin(); k != l.end(); m_size++, temp = temp->b, k++)
    {
      Node<generic> *temp2 = new Node<generic>;
      temp->data = *k;
      temp->b = temp2;
      temp2->f = temp;
      temp2->b = NULL;
    }
  }
  return *this;
}

template<typename generic>
List<generic>::~List()
{
  clear();
}

template<typename generic>
void List<generic>::push_front(generic x)
{
  Node<generic> *temp = new Node<generic>;
  temp->data = x;
  temp->f = NULL;
  temp->b = m_front;//grabs old front node
                    //note: m_front will be null, if empty
  
  if(m_front == NULL)//if the list was empty
  {
    m_front = temp;
    m_back = temp;
  }
  else//if the list isn't empty
  {
    m_front->f = temp;//grabs new node
  m_front = temp;//new front assigned
}

m_size++;
}

template<typename generic>
void List<generic>::pop_front()
{
  if(m_front != NULL)//ignores in empty list
  {
    Node<generic> *temp = m_front;
    m_front = temp->b;
    if(m_front != NULL)
    {
      m_front->f = NULL;
    }

    delete temp;

    m_size--;
    if(empty())
    {
      m_back = NULL;
    }
  }
}

template<typename generic>
void List<generic>::push_back(generic x)
{
  if(m_back == NULL)
  {
    push_front(x);
  }
  else
  {
    Node<generic> *temp = new Node<generic>;
    temp->data = x;
    temp->b = NULL;

    m_back->b = temp;//grabs new node
    temp->f = m_back;//grabs old node
    m_back = temp;//new back assigned
    
    m_size++;
  }
}

template<typename generic>
void List<generic>::pop_back()
{
  if(m_back != NULL)//ignores in empty list
  {
    Node<generic> *temp = m_back;
    m_back = temp->f;

    if(m_back != NULL)
    {
      m_back->b = NULL;
    }

    delete temp;

    m_size--;
    if(empty())
    {
      m_front = NULL;
    }
  }
}

template<typename generic>
void List<generic>::remove(generic x)
{
  if(!empty())
  {
    while(!empty() && front() == x)
    {
      pop_front();
    }
    while(!empty() && back() == x)
    {
      pop_back();
    }

    bool done = false;//necessary when there are multiple
                    //cases of x are adjacent in the center of a list
    while(!done)//will loop until we run through without finding x
    {
      done = true;
      Node<generic> *temp = m_front;
      for(Iterator k = begin(); k != end(); k++, temp = temp->b)
      {
        while(temp != NULL && temp->b != NULL && temp->b->data == x)
        {
        Node<generic> *temp2 = temp->b;//grabs old node
        temp2->f->b = temp2->b;//node in front grabs the node behind
        temp2->b->f = temp2->f;//node behind grabs the node in front

        delete temp2;//old node falls to its death
        done = false;
        m_size--;
      }
    }
    temp = NULL;
    delete temp;
  }
}
}

template<typename generic>
generic& List<generic>::front()
{
  if(m_front == NULL)
  {
    throw out_of_range
    (
      "The List is currently empty!"
    );
  }
  return m_front->data;
}

template<typename generic>
generic& List<generic>::back()
{
  if(m_back == NULL)
  {
    throw out_of_range
    (
      "The List is currently empty!"
    );
  }
  return m_back->data;
}

template<typename generic>
const generic& List<generic>::front() const
{
  if(m_front == NULL)
  {
    throw out_of_range
    (
      "The List is currently empty!"
    );
  }
  return m_front->data;
}

template<typename generic>
const generic& List<generic>::back() const
{
  if(m_back == NULL)
  {
    throw out_of_range
    (
      "The List is currently empty!"
    );
  }
  return m_back->data;
}

template<typename generic>
void List<generic>::clear()
{
  while(!empty())
  {
    pop_front();
  }
}

template<typename generic>
unsigned int List<generic>::size() const
{
  return m_size;
}

template<typename generic>
bool List<generic>::empty() const
{
  return (m_size == 0);
}
