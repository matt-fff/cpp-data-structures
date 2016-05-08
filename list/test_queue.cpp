/*
File: test_queue.cpp
Author: Matthew White CS153 B
Contains the implementations for the test_queue class
*/
#include "test_queue.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test_queue);


Test_queue::Test_queue() : TEST_MAX(5000)
{
}

void Test_queue::test_default_constructor()
{
  cout << endl << endl << "TEST QUEUE" << endl << endl;
  cout << endl << "Testing default constructor: " << endl;
  Queue<int> j;
  
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

void Test_queue::test_copy_constructor()
{
  cout << endl << "Testing copy constructor: " << endl;
  Queue<int> j;
  
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push(k);
  }
  
  Queue<int> f(j);
  
  cout << "checking that the copies are identical: ";
  while(!j.empty() && !f.empty())
  {
    CPPUNIT_ASSERT(j.front() == f.front());
    j.pop();
    f.pop();
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_push()
{
  cout << endl << "Testing push: " << endl;
  Queue<int> j;
  
  j.push(5);
  cout << "checking value from one push: ";
  CPPUNIT_ASSERT(j.back() == 5);
  cout << "PASSED" << endl;
  
  cout << "checking values from pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push(k*2);
    CPPUNIT_ASSERT(j.back() == k*2);
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_pop()
{
  cout << endl << "Testing pop: " << endl;
  Queue<int> j;
  
  j.pop();
  for(unsigned k = 0; k < TEST_MAX; k++)
  {
    j.push(k);
  }
  
  cout << "checking front value after TEST_MAX pushes and pops: ";
  for(unsigned k = 0; k < TEST_MAX; k++)
  {
   CPPUNIT_ASSERT(j.front() == k);
   j.pop();
 }
 cout << "PASSED" << endl;
 
 cout << "checking pop front when empty: ";
 
 for(unsigned k = 0; k < 10; k++)
 {
  j.pop();
}
cout << "PASSED" << endl;
}

void Test_queue::test_front()
{
  cout << endl << "Testing front: " << endl;
  Queue<int> j;

  cout << "checking front when empty: ";
  try
  {
    CPPUNIT_ASSERT(j.front());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }

  j.push(5);
  cout << "checking front after one push: ";
  CPPUNIT_ASSERT(j.front() == 5);
  cout << "PASSED" << endl;

  cout << "checking front after pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.pop();
    j.push(k/2+5);
    CPPUNIT_ASSERT(j.front() == k/2+5);
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_back()
{
  cout << endl << "Testing back: " << endl;
  Queue<int> j;

  cout << "checking back when empty: ";
  try
  {
    CPPUNIT_ASSERT(j.back());
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }

  j.push(5);
  cout << "checking back after one push: ";
  CPPUNIT_ASSERT(j.back() == 5);
  cout << "PASSED" << endl;

  cout << "checking back after pushes to TEST_MAX: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push(k/2+5);
    CPPUNIT_ASSERT(j.back() == k/2+5);
  }
  cout << "PASSED" << endl;
}

void Test_queue::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  Queue<int> j;


  cout << "checking front is NULL after pushes and clear: ";
  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push(k/2+5);
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

void Test_queue::test_size()
{
  cout << endl << "Testing size: " << endl;
  Queue<int> j;

  cout << "checking initial size: ";
  CPPUNIT_ASSERT(j.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking size after pushes: ";
  j.push(5);
  j.push(6);
  CPPUNIT_ASSERT(j.size() == 2);
  cout << "PASSED" << endl;

  cout << "checking size after pop: ";
  j.pop();
  CPPUNIT_ASSERT(j.size() == 1);
  cout << "PASSED" << endl;
}

void Test_queue::test_empty()
{
  cout << endl << "Testing empty: " << endl;
  Queue<int> j;

  cout << "checking empty initially: ";
  CPPUNIT_ASSERT(j.empty());
  cout << "PASSED" << endl;

  j.push(5);
  cout << "checking empty after push: ";
  CPPUNIT_ASSERT(!j.empty());
  cout << "PASSED" << endl;

  j.pop();
  cout << "checking empty after pop: ";
  CPPUNIT_ASSERT(j.empty());
  cout << "PASSED" << endl;
}

void Test_queue::test_assignment_operator()
{
  cout << endl << "Testing assignment operator: " << endl;
  Queue<int> j;

  for(unsigned k = 1; k < TEST_MAX; k++)
  {
    j.push(k*2);
  }

  Queue<int> f = j;

  cout << "checking that the copies are identical: ";
  while(!j.empty() && !f.empty())
  {
    CPPUNIT_ASSERT(j.front() == f.front());
    j.pop();
    f.pop();
  }
  cout << "PASSED" << endl;
}
