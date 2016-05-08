/*
File: test_list.cpp
Author: Matthew White CS153 B
Contains the implementations for the test_list class
*/
#include "test_list.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test_list);


Test_list::Test_list() : TEST_MAX(5000)
{
}

void Test_list::test_default_constructor()
{
  cout << endl << endl << "TEST LIST" << endl << endl;

  cout << endl << "Testing default constructor: " << endl;
  List<int> j;
  
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
  
  cout << "checking that back is NULL: ";
  try
  {
    CPPUNIT_ASSERT(j.back());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
}

void Test_list::test_copy_constructor()
{
  cout << endl << "Testing copy constructor: " << endl;
  List<int> j;
  List<int>::Iterator i;
  
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k*2);
  }
  
  List<int> f(j);
  List<int>::Iterator k;
  
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

void Test_list::test_push_front()
{
  cout << endl << "Testing push front: " << endl;
  List<int> j;

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

void Test_list::test_pop_front()
{
  cout << endl << "Testing pop front: " << endl;
  List<int> j;

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

void Test_list::test_push_back()
{
  cout << endl << "Testing push back: " << endl;
  List<int> j;

  j.push_back(5);
  cout << "checking value from one push: ";
  CPPUNIT_ASSERT(j.back() == 5);
  cout << "PASSED" << endl;

  cout << "checking values from pushes to TEST_MAX: ";
  for(unsigned k = 0; k < TEST_MAX; k++)
  {
    j.push_back(k);
    CPPUNIT_ASSERT(j.back() == k);
  }
  cout << "PASSED" << endl;
}

void Test_list::test_pop_back()
{
  cout << endl << "Testing pop back: " << endl;
  List<int> j;

  j.pop_back();
  for(unsigned k = 0; k < TEST_MAX; k++)
  {
    j.push_back(k);
  }

  cout << "checking back value after TEST_MAX pushes and pops: ";
  for(unsigned k = TEST_MAX-1; k > 0; k--)
  {
   CPPUNIT_ASSERT(j.back() == k);
   j.pop_back();
 }
 cout << "PASSED" << endl;

 cout << "checking pop back when empty: ";

 for(unsigned k = 0; k < 10; k++)
 {
  j.pop_back();
}
cout << "PASSED" << endl;
}

void Test_list::test_remove()
{
  cout << endl << "Testing remove: " << endl;
  List<int> j;

  cout << "checking remove on empty list: ";
  j.remove(2);
  CPPUNIT_ASSERT(j.empty());
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

  j.push_front(1);
  j.push_front(4);
  j.push_front(2);
  j.push_front(2);
  j.push_front(7);
  j.push_front(8);
  j.push_front(2);
  j.push_front(9);
  j.push_front(2);

  cout << "checking remove on mixed list: ";
  j.remove(2);
  for(List<int>::Iterator k = j.begin(); k != j.end(); k++)
  {
  //cout << *k << ", ";
    CPPUNIT_ASSERT(*k != 2);
  }
  cout << "PASSED" << endl;
}

void Test_list::test_front()
{
  cout << endl << "Testing front: " << endl;
  List<int> j;

  cout << "checking front when empty: ";
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

void Test_list::test_back()
{
  cout << endl << "Testing back: " << endl;
  List<int> j;

  cout << "checking back when empty: ";
  try
  {
    CPPUNIT_ASSERT(j.back());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }

  j.push_back(5);
  cout << "checking back after one push: ";
  CPPUNIT_ASSERT(j.back() == 5);
  cout << "PASSED" << endl;

  cout << "checking back after pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_back(k/2+5);
    CPPUNIT_ASSERT(j.back() == k/2+5);
  }
  cout << "PASSED" << endl;
}

void Test_list::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  List<int> j;


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

void Test_list::test_size()
{
  cout << endl << "Testing size: " << endl;
  List<int> j;

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

void Test_list::test_empty()
{
  cout << endl << "Testing empty: " << endl;
  List<int> j;

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


void Test_list::test_assignment_operator()
{
  cout << endl << "Testing assignment operator: " << endl;
  List<int> j;
  List<int>::Iterator i;

  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push_front(k*2);
  }

  List<int> f;
  f = j;
  List<int>::Iterator k;

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

void Test_list::test_iterator_default_constructor()
{
  cout << endl << "Testing iterator default constructor: " << endl;
  List<int>::Iterator k;

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

void Test_list::test_iterator_parameter_constructor()
{
  cout << endl << "Testing iterator parameter constructor: " << endl;

  Node<int>* j = new Node<int>();
  j->data = 2;

  List<int>::Iterator k(j);

  cout << "checking that the iter. and its param. point to same data: ";
  CPPUNIT_ASSERT(k == j);
  cout << "PASSED" << endl;

  delete j;
}

void Test_list::test_iterator_reference_operator()
{
  cout << endl << "Testing iterator * operator: " << endl;
  Node<int>* j = new Node<int>();
  j->data = 2;

  List<int>::Iterator k(j);

  cout << "checking that the proper data is returned: ";
  CPPUNIT_ASSERT(*k == j->data);
  cout << "PASSED" << endl;

  delete  j;
}

void Test_list::test_iterator_increment_operator()
{
  cout << endl << "Testing iterator incrementer: " << endl;

  List<int> j;

  j.push_front(2);
  j.push_front(1);
  j.push_front(4);
  j.push_front(2);
  j.push_front(7);
  j.push_front(8);

  cout << "checking initial value: ";
  List<int>::Iterator k = j.begin();
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

void Test_list::test_iterator_decrement_operator()
{
  cout << endl << "Testing iterator decrementer: " << endl;

  List<int> j;

  j.push_back(2);
  j.push_back(1);
  j.push_back(4);
  j.push_back(2);
  j.push_back(7);
  j.push_back(8);

  cout << "checking initial value: ";
  List<int>::Iterator k = j.end();
  CPPUNIT_ASSERT(*k == j.back());
  cout << "PASSED" << endl;

  cout << "checking multiple values after decrements: ";
  for(int i = 0; i < 3; i++)
  {
    k--;
    j.pop_back();
    CPPUNIT_ASSERT(*k == j.back());
  }
  cout << "PASSED" << endl;
}

void Test_list::test_iterator_equal_operator()
{
  cout << endl << "Testing iterator == operator: " << endl;

  List<int> j;

  j.push_front(2);
  j.push_front(1);
  j.push_front(4);

  List<int> f;

  f.push_front(7);
  f.push_front(9);
  f.push_front(11);

  cout << "checking identical iterators using ==: ";
  List<int>::Iterator k = j.begin();
  List<int>::Iterator n = j.begin();
  CPPUNIT_ASSERT(k == n);
  cout << "PASSED" << endl;

  cout << "checking different iterators using ==: ";
  k = j.begin();
  n = f.begin();
  CPPUNIT_ASSERT(!(k == n));
  cout << "PASSED" << endl;
}

void Test_list::test_iterator_not_equal_operator()
{
  cout << endl << "Testing iterator != operator: " << endl;

  List<int> j;

  j.push_front(2);
  j.push_front(1);
  j.push_front(4);

  List<int> f;

  f.push_front(7);
  f.push_front(9);
  f.push_front(11);

  cout << "checking identical iterators using !=: ";
  List<int>::Iterator k = j.begin();
  List<int>::Iterator n = j.begin();
  CPPUNIT_ASSERT(!(k != n));
  cout << "PASSED" << endl;

  cout << "checking different iterators using !=: ";
  k = j.begin();
  n = f.begin();
  CPPUNIT_ASSERT(k != n);
  cout << "PASSED" << endl;
}
