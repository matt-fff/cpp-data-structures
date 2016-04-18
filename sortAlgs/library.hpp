/*
  File: library.hpp
  Contains templated implementations for the sorting algorithms
*/

#include "library.h"

template<typename generic>
  void quick_sort(vector<generic>& v)
  {
    if(v.size() > 1)
    {
      stack<int> f;
      stack<int> b;
      f.push(0);
      b.push(v.size()-1);
      int m = 0;
      int front = f.top();
      int back = b.top();
      
    //cout << endl;
      while(f.size() > 0 && b.size() > 0)
      {
    //cout << f.top() << "|" << b.top() << endl;
        if(f.top() < b.top())
        {
          m = partition(v, f.top(), b.top());
          front = f.top();
          back = b.top();
        }
        f.pop();
        b.pop();
        if(front < back)
        {
          f.push(front);
          b.push(m-1);
          f.push(m+1);
          b.push(back);
        }
        front = back = 0;
      }
    }
  }

template<typename generic>
  void merge_sort(vector<generic>& v)
  {
    if(v.size() > 1)
    {
      bool repeats = false;
      int m;
      stack<int> sf;
      stack<int> sb;
      stack<int> mf;
      stack<int> mb;
      sf.push(0);
      sb.push(v.size()-1);
      
  //builds merge stacks until split stack is exhausted
      do
      {     
    if(sf.size() > 0 && sf.top() < sb.top())//push to merge stack
    {
      mf.push(sf.top());
      mb.push(sb.top());
    }
    do
    {
      sf.pop();//pop split stack
      sb.pop();
    }while(sf.size() > 0 && sf.top() >= sb.top());
    
    
    //decides if we need to push anything else to the split stack
    if(mb.top()-mf.top() > 1
      && (sf.size() == 0 || (sf.top() != mf.top()
        && sb.top() != ((mb.top()+mf.top())/2))))
    {     
      m = (mb.top()+mf.top())/2;
      sf.push(mf.top());
      sb.push(m);
      sf.push(m+1);
      sb.push(mb.top());
    }
  }while(sf.size() > 0 && sb.size() > 0);
  
  
  //merges everything together!!! Muahahahahaaaa!
  while(mf.size() > 0 && mb.size() > 0)
  {
    merge(v, mf.top(), mb.top());
    mf.pop();
    mb.pop();
  }
}
}

template<typename generic>
void merge(vector<generic>& v, int f, int b)
{
  if(f >= v.size() || b >= v.size() || f > b)
  {
    cerr << "Invalid Input!" << endl;
  }
  else
  {
    vector<generic> temp = v;
    v.clear();
    for(int k = 0; k < f; k++)//deals with front section
    {
      v.push_back(temp[k]);
    }
    
    int m = ((f+b)/2);
    int left = f;
  int right = m+1;//adding 1 fixed the entire function
  //cout << "M = " << m << endl;
  
  vector<generic> Right;
  vector<generic> Left;
  
  //cout << endl << "Left: ";
  for(int k = left; k < right; k++)//construct a "Left" vector
  {
    Left.push_back(temp[k]);
    //cout << temp[k] << ", ";
  }
  //cout << endl << "Right: ";
  for(int k = right; k <= b; k++)//constructs a "Right" vector
  {
    Right.push_back(temp[k]);
    //cout << temp[k] << ", ";
  }
  
  left = 0;
  right = 0;
    while(left < Left.size() && right < Right.size())//deals with the section to be sorted
    {
      if(Left[left] < Right[right])//which is bigger?
      {
        v.push_back(Left[left++]);
      }
      else
      {
        v.push_back(Right[right++]);
      }
    }
    
  while(left < Left.size())//deals with remaining numbers on Left
  {
    v.push_back(Left[left++]);
  }
  while(right < Right.size())//deals with remaining numbers on Right
  {
    v.push_back(Right[right++]);
  }
  
    for(int k = b + 1; k < temp.size(); k++)//deals with back section
    {
      v.push_back(temp[k]);
    }
  }
}

template<typename generic>
int partition(vector<generic>& v, int f, int b)
{
  int above = 0, below = 0, firstIndex = f+1, index;
  generic pivot = v[f];
  index = firstIndex;
  
  //cout << endl;
  while(above + index < v.size() && below + index < v.size())
  {
    /*cout << "index: " << index << endl
       << "above: " << above << endl
     << "below: " << below << endl;*/
       while(above + index < v.size() && v[above + index] <= pivot)
       {
        index++;
      }
      above += index;
      while(index + below < v.size() && v[index + below] > pivot)
      {
        index++;
      }
      below += index;
      
      if(above < v.size() && below < v.size())
      {
        swap(v, above, below);
      }
      index = 0;
    }
    swap(v, above-1, f);
  //cout << "returns: " << above-1 << endl;
    return (above-1);
  }

template<typename generic>
  void swap(vector<generic>& v, unsigned left, unsigned right)
  {
    if(left < v.size() && right < v.size())
    {
      generic temp = v[left];
      v[left] = v[right];
      v[right] = temp;
    }
  }
