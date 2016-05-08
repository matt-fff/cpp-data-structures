/*
  File: set.hpp
  Author: Matthew White CS153 B
  Contains the set container class implementations
*/
template<typename generic>
Set<generic>::Set()
{
}

template<typename generic>
Set<generic>::Set(const Set<generic>& px)
{
	*this = px;
}


template<typename generic>
Set<generic>& Set<generic>::operator=(const Set<generic>& px)
{
	for(BTInorderIterator<generic> k = px.begin(); k != px.end(); k++)
	{
		insert(*k);
	}
}

template<typename generic>
Set<generic> Set<generic>::operator+(const Set<generic>& rhs) const
{
	Set<generic> temp;
	for(BTInorderIterator<generic> k = begin(); k != end(); k++)
	{
		temp.insert(*k);
	}
	for(BTInorderIterator<generic> j = rhs.begin(); j != rhs.end(); j++)
	{
		temp.insert(*j);
	}
	
	return temp;
}

template<typename generic>
Set<generic> Set<generic>::operator*(const Set<generic>& rhs) const
{
	Set<generic> temp;
	for(BTInorderIterator<generic> k = begin(); k != end(); k++)
	{
		for(BTInorderIterator<generic> j = rhs.begin(); j != rhs.end(); j++)
		{
			if(*k == *j)
			{
				temp.insert(*k);
			}
		}
	}
	
	return temp;
}

template<typename generic>
Set<generic> Set<generic>::operator-(const Set<generic>& rhs) const
{
	bool contained;
	Set<generic> temp;
	for(BTInorderIterator<generic> k = begin(); k != end(); k++)
	{
		contained = false;
		for(BTInorderIterator<generic> j = rhs.begin(); j != rhs.end(); j++)
		{
			if(*k == *j)
			{
				contained = true;
			}
		}
		if(!contained)
		{
			temp.insert(*k);
		}
	}
	
	return temp;
}

template<typename generic>
void Set<generic>::insert(generic px)
{
	AVL<generic>::insert(px);
}

template<typename generic>
void Set<generic>::erase(generic px)
{
	AVL<generic>::remove(px);
}

template<typename generic>
bool Set<generic>::empty() const
{
	return AVL<generic>::m_size == 0;
}

template<typename generic>
unsigned int Set<generic>::size() const
{
	return BST<generic>::m_size;
}

template<typename generic>
void Set<generic>::clear()
{
	BT<generic>::clear();
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::find(generic px)
{
	return AVL<generic>::in_search(px);
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::begin() const
{
	return AVL<generic>::in_begin();
}

template<typename generic>
BTInorderIterator<generic> Set<generic>::end() const
{
	return AVL<generic>::in_end();
}
