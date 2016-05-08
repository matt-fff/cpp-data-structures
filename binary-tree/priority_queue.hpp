/*
  File: priority_queue.hpp
  Author: Matthew White CS153 B
  Contains the priority queue container class implementations
*/
template<typename generic>
Priority_queue<generic>::Priority_queue() : BT<generic>()
{
	m_push = m_pop = NULL;
}

template<typename generic>
Priority_queue<generic>::Priority_queue(const Priority_queue<generic>& c) : BT<generic>()
{
	m_push = m_pop = NULL;
	*this = c;
}

template<typename generic>
Priority_queue<generic>& Priority_queue<generic>::operator=(const Priority_queue<generic>& rhs)
{
  recursiveCopy(rhs.m_root);
  return *this;
}

template<typename generic>
void Priority_queue<generic>::recursiveCopy(BTN<generic>* x)
{
	if(x != NULL)
	{
		if(x->l != NULL)
		{
			recursiveCopy(x->l);
		}
		if(x->r != NULL)
		{
			recursiveCopy(x->r);
		}
		push(*(x->d));
	}
}

template<typename generic>
void Priority_queue<generic>::push(generic x)
{
	BTN<generic>* temp = new BTN<generic>;
	temp->d = new generic;
	*(temp->d) = x;
	temp->l = NULL;
	temp->r = NULL;
	
	//if this is the first push
	if(BT<generic>::m_root == NULL)
	{
		temp->p = NULL;
		BT<generic>::m_root = m_push = m_pop = temp;
	}
	else
	{
		m_pop = m_push;//m_pop lags behind m_push as it goes
	
		//if the new node goes to the left
		if(m_push->l == NULL)
		{
			m_push->l = temp;
			temp->p = m_push;
		}
		//if the new node goes to the right (we must move m_push)
		else
		{
		
			m_push->r = temp;
			temp->p = m_push;
			
			//if we're at the tip top
			if(m_push->p == NULL)
			{
				m_push = m_push->l;
			}
			//if we're on the left (simple move)
			else if(m_push->p->l == m_push)
			{
				m_push = m_push->p->r;
			}
			//if we're on the right (complicated)
			else
			{
				//goes as high as we need to
				while(m_push->p != NULL && m_push->p->r == m_push)
				{
					m_push = m_push->p;
				}
				
				//indicates we need to move right
				if(m_push->p != NULL)
				{
					m_push = m_push->p->r;
				}
				
				//proceeds to move to the next node
				while(m_push != NULL && m_push->l != NULL)
				{
					m_push = m_push->l;
				}
			}
		}
	}
	
	setDepth(temp);
	promoteNodesPush(temp);
	BT<generic>::m_size++;
}

template<typename generic>
void Priority_queue<generic>::pop()
{
	if(BT<generic>::m_root != NULL)
	{
		m_push = m_pop;//m_push inversely lags behind m_pop
		
		//if we only have one node
		if(BT<generic>::m_root == m_pop 
		&& m_pop != NULL 
		&& m_pop->l == NULL 
		&& m_pop->r == NULL)
		{
			delete m_pop->d;
			delete m_pop;
			BT<generic>::m_root = m_push = m_pop = NULL;
		}
		//more than one node
		else
		{
			//node deletion on the right
			if(m_pop != NULL && m_pop->r != NULL)
			{
				swap(BT<generic>::m_root, m_pop->r);
				delete m_pop->r->d;
				delete m_pop->r;
				m_pop->r = NULL;
			}
			//node deletion on the left (requires move)
			else
			{
				swap(BT<generic>::m_root, m_pop->l);
				delete m_pop->l->d;
				delete m_pop->l;
				m_pop->l = NULL;
			
				//if we're on the right (simple move)
				if(m_pop != NULL && m_pop->p != NULL && m_pop->p->r == m_pop)
				{
					m_pop = m_pop->p->l;
				}
				//if we're on the left (complicated)
				else if(m_pop != NULL && m_pop->p != NULL)
				{
					//goes as high as we need to
					while(m_pop != NULL && m_pop->p != NULL && m_pop->p->l == m_pop)
					{
						m_pop = m_pop->p;
					}
				
					//indicates we need to move left
					if(m_pop != NULL && m_pop->p != NULL)
					{
						m_pop = m_pop->p->l;
					}
				
					//proceeds to move to the next node
					while(m_pop != NULL && m_pop->r != NULL && m_pop->r->r != NULL)
					{
						m_pop = m_pop->r;
					}
				}
			}
		}
		
		promoteNodesPop(BT<generic>::m_root);
		BT<generic>::m_size--;
	}
}

template<typename generic>
const generic& Priority_queue<generic>::top() const
{
	if(BT<generic>::m_root == NULL || BT<generic>::m_root->d == NULL)
	{
		throw out_of_range
		(
		"Queue is currently empty."
		);
	}
	
	return *(BT<generic>::m_root->d);
}

template<typename generic>
void Priority_queue<generic>::setDepth(BTN<generic>* x)
{
	//Note: root depth will be 0

	BTN<generic>* temp = x;
	int depth = 0;
	while(temp != NULL && temp->p != NULL)
	{
		temp = temp->p;
		depth++;
	}
	
	x->depth = depth;
}

template<typename generic>
void Priority_queue<generic>::promoteNodesPop(BTN<generic>* x)
{
	if(x != NULL)
	{
		//if x's left is greater than x
		if(x->l != NULL && *(x->d) < *(x->l->d))
		{
			//if x's right is greater than x's left
			if(x->r != NULL && *(x->r->d) > *(x->l->d))
			{
				swap(x, x->r);
				promoteNodesPop(x->r);
			}
			//if x's left is greater than x's right
			else
			{
				swap(x, x->l);
				promoteNodesPop(x->l);
			}
		}
		//if x's right is greater than x
		else if(x->r != NULL && *(x->d) < *(x->r->d))
		{
			//note: no comparison between sides needed as we already
			//know that the left is not greater than x
			swap(x,x->r);
			promoteNodesPop(x->r);
		}
	}
}

template<typename generic>
void Priority_queue<generic>::promoteNodesPush(BTN<generic>* x)
{
	while(x != NULL && x->p != NULL && *(x->d) > *(x->p->d))
	{
		swap(x, x->p);
		x = x->p;
	}
}

template<typename generic>
void Priority_queue<generic>::swap(BTN<generic>* a, BTN<generic>* b)
{
	if(a != NULL && b != NULL
	&& a->d != NULL && b->d != NULL)
	{
		//swaps out the data, nothing else
		generic* temp = a->d;
		a->d = b->d;
		b->d = temp;
	}
}

template<typename generic>
int Priority_queue<generic>::size()
{
	return BT<generic>::m_size;
}
