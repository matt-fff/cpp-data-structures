/*
  File: bst.hpp
  Author: Matthew White CS153 B
  Contains the function implementations for the bst container class
*/

template<typename generic>
BST<generic>::BST():m_root(NULL), m_size(0)
{
}

template<typename generic>
BST<generic>::~BST()
{
  clear();
}

template<typename generic>
void BST<generic>::insert(generic x)
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

template<typename generic>
void BST<generic>::remove(generic x)
{
  BTN<generic>* temp = m_root;
  bool deleted = false;//avoids working with temp's value
                       //when it no longer exists
  
  while(!deleted && temp != NULL)
  {
    //checks if the data matches
    if(temp->data != NULL && *(temp->data) == x)
	{
	  BTN<generic>* swapper = leftRightmost(temp);
	  swap(temp, swapper);
	  delete_node(swapper);
	  deleted = true;
	}
	
	//moves to next appropriate node
    if(!deleted && temp->data != NULL && *(temp->data) > x)
	{
	  temp = temp->l;
	}
	else if(!deleted)
	{
	  temp = temp->r;
	}
  }
}

template<typename generic>
bool BST<generic>::search(generic x) const
{
  BTN<generic>* temp = m_root;
  
  while(temp != NULL)
  {
    //true if found
    if(temp->data != NULL && *(temp->data) == x)
	{
	  return true;
	}
	
	//moves to next appropriate node
    if(temp->data != NULL && *(temp->data) > x)
	{
	  temp = temp->l;
	}
	else
	{
	  temp = temp->r;
	}
  }
  
  return false;
}

template<typename generic>
void BST<generic>::clear()
{
  //Woo! Elegant solution!
  while(m_root != NULL && !empty())
  {
    delete_node(leftRightmost(m_root));
  }
}

template<typename generic>
bool BST<generic>::empty() const
{
  return m_size == 0;
}

template<typename generic>
unsigned int BST<generic>::size() const
{
  return m_size;
}

template<typename generic>
void BST<generic>::swap(BTN<generic>* a, BTN<generic>* b)
{
  if(a != NULL && b != NULL
  && a->data != NULL && b->data != NULL
  && *(a->data) != *(b->data))
  {
    //swaps out the data, nothing else
    BTN<generic>* temp = new BTN<generic>;
	temp->data = new generic;
    *(temp->data) = *(a->data);
    *(a->data) = *(b->data);
    *(b->data) = *(temp->data);
    delete temp->data;
    delete temp;
  }
}

template<typename generic>
void BST<generic>::delete_node(BTN<generic>* a)
{
  //ignores call if node is null or if it has two children
  if(a != NULL && (a->l == NULL || a->r == NULL))
  {
    //deals with parented nodes
    if(a->p != NULL)
	{
      //deals with a node with a left child
      if(a->l != NULL)
	  {
	    a->l->p = a->p;
	    if(a->p->r != NULL && *(a->p->r->data) == *(a->data))
	    {
	      a->p->r = a->l;
        }
	    else
	    {
	      a->p->l = a->l;
	    }
	  }
	  //deals with a node with a right child
	  else if(a->r != NULL)
	  {
	    a->r->p = a->p;
	    if(a->p->r != NULL && *(a->p->r->data) == *(a->data))
	    {
	      a->p->r = a->r;
        }
	    else
	    {
	      a->p->l = a->r;
	    }
	  }
	  //deals with a node with no children
	  else
	  {
	    if(a->p->r != NULL && *(a->p->r->data) == *(a->data))
	    {
	      a->p->r = NULL;
	    }
	    else
	    {
	      a->p->l = NULL;
	    }
	  }
	}
	//deals with parentless nodes
	else
	{
	  //deals with right child
	  if(a->r != NULL)
	  {
	    m_root = a->r;
		if(a->r != NULL)
		{
		  a->r->p = NULL;
		}
	  }
	  //deals with left child and childless
	  else
	  {
	    m_root = a->l;
		if(a->l != NULL)
		{
		  a->l->p = NULL;
		}
	  }
	}
	
	delete a->data;
	delete a;
	m_size--;
  }
}

template<typename generic>
BTN<generic>* BST<generic>::leftRightmost(BTN<generic>* a)
{
  BTN<generic>* node = a;
  //one move left
  if(node != NULL && node->l != NULL)
  {
    node = node->l;
    //as many possible moves right
    while(node->r != NULL)
    {
      node = node->r;
    }
  }
  return node;
}

template<typename generic>
BTPreorderIterator<generic> BST<generic>::pre_search(generic x)
{  
  BTPreorderIterator<generic> k;
 
  for(k = BST<generic>::pre_begin(); k != BST<generic>::pre_end() && *k != x; k++){}
  
  return k;
}

template<typename generic>
BTInorderIterator<generic> BST<generic>::in_search(generic x)
{
  BTInorderIterator<generic> k;
 
  for(k = BST<generic>::in_begin(); k != BST<generic>::in_end() && *k != x; k++){}

  return k;
}

template<typename generic>
BTPostorderIterator<generic> BST<generic>::post_search(generic x)
{
  BTPostorderIterator<generic> k;
 
  for(k = BST<generic>::post_begin(); k != BST<generic>::post_end() && *k != x; k++){}
  
  return k;
}

template<typename generic>
BTPreorderIterator<generic> BST<generic>::pre_begin() const
{
  return BTPreorderIterator<generic>(m_root);
}

template<typename generic>
BTPreorderIterator<generic> BST<generic>::pre_end() const
{
  return NULL;
}

template<typename generic>
BTInorderIterator<generic> BST<generic>::in_begin() const
{
  BTN<generic>* begin = m_root;
  
  while(begin != NULL && begin->l != NULL)
  {
    begin = begin->l;
  }

  return BTInorderIterator<generic>(begin);
}

template<typename generic>
BTInorderIterator<generic> BST<generic>::in_end() const
{
  return NULL;
}

template<typename generic>
BTPostorderIterator<generic> BST<generic>::post_begin() const
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
BTPostorderIterator<generic> BST<generic>::post_end() const
{
  return NULL;
}
