/*
  File: test_slist.cpp
  Contains test implementations for the slist class
*/

#include"test_slist.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_slist);


Test_slist::Test_slist() : TEST_MAX(5000)
{
}

void Test_slist::test_default_constructor()
{
  cout << endl << "Testing default constructor: " << endl;
  SList<int> j;
  
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(j.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking that front is NULL: ";
  try
    {
      CPPUNIT_ASSERT(j.front());
    }
  catch(out_of_range& e)
    {
      cout << "PASSED" << endl;
    }
}

void Test_slist::test_copy_constructor()
{
  cout << endl << "Testing copy constructor: " << endl;
  SList<int> j;
  SList<int>::Iterator i;
  
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k*2);
  }
  
  SList<int> f(j);
  SList<int>::Iterator k;
  
  f.pop_front(); //for some variance
  f.push_front(-4);
  
  cout << "checking that a deep copy was created: ";
  for(i = j.begin(), k = f.begin(); i != j.end(); i++, k++)
  {
    if(i == j.begin() && k == f.begin())
	{
	  CPPUNIT_ASSERT(*i != *k);
	}
	else
	{
      CPPUNIT_ASSERT(*i == *k);
	}
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_push_front()
{
  cout << endl << "Testing push front: " << endl;
  SList<int> j;
  
  j.push_front(5);
  cout << "checking value from one push: ";
  CPPUNIT_ASSERT(j.front() == 5);
  cout << "PASSED" << endl;
  
  cout << "checking values from pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k*2);
	CPPUNIT_ASSERT(j.front() == k*2);
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_pop_front()
{
  cout << endl << "Testing pop front: " << endl;
  SList<int> j;
  
  j.pop_front();
  for(unsigned k = 0; k < TEST_MAX; k++)
  {
    j.push_front(k);
  }
  
  cout << "checking front value after TEST_MAX pushes and pops: ";
  for(unsigned k = TEST_MAX-1; k > 1; k--)
  {
    j.pop_front();
	CPPUNIT_ASSERT(j.front() == k-1);
  }
  cout << "PASSED" << endl;
  
  cout << "checking pop front when empty: ";
  
  for(unsigned k = 0; k < 10; k++)
  {
    j.pop_front();
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_remove()
{
  cout << endl << "Testing remove: " << endl;
  SList<int> j;
  
  cout << "checking remove on empty list: ";
  j.remove(2);
  CPPUNIT_ASSERT(j.size() == 0);
  cout << "PASSED" << endl;
  
  j.push_front(2);
  j.push_front(2);
  j.push_front(2);
  j.push_front(2);
  j.push_front(2);
  
  cout << "checking list of all 2's with remove(2): ";
  j.remove(2);
  CPPUNIT_ASSERT(j.empty());
  cout << "PASSED" << endl;
  
  j.push_front(2);
  j.push_front(1);
  j.push_front(4);
  j.push_front(2);
  j.push_front(7);
  j.push_front(8);
  j.push_front(2);
  j.push_front(9);
  j.push_front(2);
  
  cout << "checking remove on long list: ";
  j.remove(2);
  for(SList<int>::Iterator k = j.begin(); k != j.end(); k++)
  {
    //cout << *k << ", ";
    CPPUNIT_ASSERT(*k != 2);
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_front()
{
  cout << endl << "Testing front: " << endl;
  SList<int> j;
  
  cout << "checking initial front: ";
  try
  {
    CPPUNIT_ASSERT(j.front());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  j.push_front(5);
  cout << "checking front after one push: ";
  CPPUNIT_ASSERT(j.front() == 5);
  cout << "PASSED" << endl;
  
  cout << "checking front after pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k/2+5);
	CPPUNIT_ASSERT(j.front() == k/2+5);
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  SList<int> j;
  
  
  cout << "checking front is NULL after pushes and clear: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k/2+5);
  }
  
  j.clear();
  try
  {
    CPPUNIT_ASSERT(j.front());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  cout << "checking size is 0 after pushed and clear: ";
  CPPUNIT_ASSERT(j.size() == 0);
  cout << "PASSED" << endl;
}

void Test_slist::test_size()
{
  cout << endl << "Testing size: " << endl;
  SList<int> j;
  
  cout << "checking initial size: ";
  CPPUNIT_ASSERT(j.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking size after pushes: ";
  j.push_front(5);
  j.push_front(6);
  CPPUNIT_ASSERT(j.size() == 2);
  cout << "PASSED" << endl;
  
  cout << "checking size after pop: ";
  j.pop_front();
  CPPUNIT_ASSERT(j.size() == 1);
  cout << "PASSED" << endl;
}

void Test_slist::test_empty()
{
  cout << endl << "Testing empty: " << endl;
  SList<int> j;
  
  cout << "checking empty initially: ";
  CPPUNIT_ASSERT(j.empty());
  cout << "PASSED" << endl;
 
  j.push_front(5);
  cout << "checking empty after push: ";
  CPPUNIT_ASSERT(!j.empty());
  cout << "PASSED" << endl;
  
  j.pop_front();
  cout << "checking empty after pop: ";
  CPPUNIT_ASSERT(j.empty());
  cout << "PASSED" << endl;
}


void Test_slist::test_assignment_operator()
{
  cout << endl << "Testing assignment operator: " << endl;
  SList<int> j;
  SList<int>::Iterator i;
  
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k*2);
  }
  
  SList<int> f;
  f = j;
  SList<int>::Iterator k;
  
  f.pop_front(); //for some variance
  f.push_front(-4);
  
  cout << "checking that a deep copy was created: ";
  for(i = j.begin(), k = f.begin(); i != j.end(); i++, k++)
  {
    if(i == j.begin() && k == f.begin())
	{
	  CPPUNIT_ASSERT(*i != *k);
	}
	else
	{
      CPPUNIT_ASSERT(*i == *k);
	}
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_iterator_default_constructor()
{
  cout << endl << "Testing iterator default constructor: " << endl;
  SList<int>::Iterator k;
  
  cout << "checking that m_current is NULL: ";
  try
  {
    CPPUNIT_ASSERT(*k);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
}

void Test_slist::test_iterator_parameter_constructor()
{
  cout << endl << "Testing iterator parameter constructor: " << endl;
  
  SNode<int>* j = new SNode<int>();
  j->data = 2;
  
  SList<int>::Iterator k(j);
  
  cout << "checking that the iter. and its param. point to same data: ";
  CPPUNIT_ASSERT(k == j);
  cout << "PASSED" << endl;
  
  delete j;
}

void Test_slist::test_iterator_reference_operator()
{
  cout << endl << "Testing iterator * operator: " << endl;
  SNode<int>* j = new SNode<int>();
  j->data = 2;
  
  SList<int>::Iterator k(j);
  
  cout << "checking that the proper data is returned: ";
  CPPUNIT_ASSERT(*k == j->data);
  cout << "PASSED" << endl;
  
  delete  j;
}

void Test_slist::test_iterator_increment_operator()
{
  cout << endl << "Testing iterator incrementer: " << endl;
  
  SList<int> j;
  
  j.push_front(2);
  j.push_front(1);
  j.push_front(4);
  j.push_front(2);
  j.push_front(7);
  j.push_front(8);
  
  cout << "checking initial value: ";
  SList<int>::Iterator k = j.begin();
  CPPUNIT_ASSERT(*k == j.front());
  cout << "PASSED" << endl;
  
  cout << "checking multiple values after increments: ";
  for(int i = 0; i < 4; i++)
  {
    k++;
    j.pop_front();
    CPPUNIT_ASSERT(*k == j.front());
  }
  cout << "PASSED" << endl;
}

void Test_slist::test_iterator_equal_operator()
{
  cout << endl << "Testing iterator == operator: " << endl;
  
  SList<int> j;
  
  j.push_front(2);
  j.push_front(1);
  j.push_front(4);
  
  SList<int> f;

  f.push_front(7);
  f.push_front(9);
  f.push_front(11);
  
  cout << "checking identical iterators using ==: ";
  SList<int>::Iterator k = j.begin();
  SList<int>::Iterator n = j.begin();
  CPPUNIT_ASSERT(k == n);
  cout << "PASSED" << endl;
  
  cout << "checking different iterators using ==: ";
  k = j.begin();
  n = f.begin();
  CPPUNIT_ASSERT(!(k == n));
  cout << "PASSED" << endl;
}

void Test_slist::test_iterator_not_equal_operator()
{
  cout << endl << "Testing iterator != operator: " << endl;
  
  SList<int> j;
  
  j.push_front(2);
  j.push_front(1);
  j.push_front(4);
  
  SList<int> f;

  f.push_front(7);
  f.push_front(9);
  f.push_front(11);
  
  cout << "checking identical iterators using !=: ";
  SList<int>::Iterator k = j.begin();
  SList<int>::Iterator n = j.begin();
  CPPUNIT_ASSERT(!(k != n));
  cout << "PASSED" << endl;
  
  cout << "checking different iterators using !=: ";
  k = j.begin();
  n = f.begin();
  CPPUNIT_ASSERT(k != n);
  cout << "PASSED" << endl;
}
