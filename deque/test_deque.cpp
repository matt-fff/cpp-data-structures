/*
  File: test_deque.cpp
  Contains the test implementations for test_deque
*/
#include "test_deque.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test_deque);


Test_deque::Test_deque() : TEST_MAX(5000)
{
}

void Test_deque::test_default_constructor()
{
  cout << endl << endl << "TEST DEQUE" << endl << endl;
  cout << endl << "Testing default constructor: " << endl;
  
  Deque<int> b;
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking block size is 3: ";
  CPPUNIT_ASSERT(b.block_size() == 3);
  cout << "PASSED" << endl;
  
  cout << "checking empty: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  cout << "checking that bracket operator throws exception: ";
  try
  {
    CPPUNIT_ASSERT(b[0]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  } 
  
}

void Test_deque::test_param_constructor()
{
  cout << endl << "Testing parameter constructor: " << endl;
  
  Deque<int> b(7);
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking block size is 7: ";
  CPPUNIT_ASSERT(b.block_size() == 7);
  cout << "PASSED" << endl;
  
  cout << "checking empty: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  cout << "checking that bracket operator throws exception: ";
  try
  {
    CPPUNIT_ASSERT(b[0]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  } 
}

void Test_deque::test_copy_constructor()
{
  cout << endl << "Testing copy constructor: " << endl;
  
  Deque<int> b;
  
  b.push_back(0);
  b.push_back(1);
  b.push_back(2);
  b.push_back(17);
  b.push_back(42);
  
  Deque<int> c(b);
  
  cout << "checking equal size: ";
  CPPUNIT_ASSERT(b.size() == c.size());
  cout << "PASSED" << endl;
  
  cout << "checking equal block size: ";
  CPPUNIT_ASSERT(b.block_size() == c.block_size());
  cout << "PASSED" << endl;
  
  c.pop_back();
  c.push_back(7);
  
  cout << "checking all values, ensuring deep copy: ";
  for(int k = 0; k < b.size(); k++)
  {
    if(k == b.size()-1)
	{
	  CPPUNIT_ASSERT(b[k] != c[k]);
	}
	else
	{
	  CPPUNIT_ASSERT(b[k] == c[k]);
	}
  }
  cout << "PASSED" << endl;
}

void Test_deque::test_push_front()
{
  cout << endl << "Testing push front: " << endl;
  
  Deque<int> b;
  
  b.push_front(4);  
  
  cout << "checking size after 1 push: ";
  CPPUNIT_ASSERT(b.size() == 1);
  cout << "PASSED" << endl;
  
  cout << "checking value of 1st push: ";
  CPPUNIT_ASSERT(b[0] == 4);
  cout << "PASSED" << endl;
  
  b.push_front(3);
  b.push_front(2);
  
  cout << "checking value after new pushes: ";
  CPPUNIT_ASSERT(b[0] == 2);
  cout << "PASSED" << endl;
  
  cout << "checking size after new pushes: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
  
  cout << "pushing when first block is full: ";
  b.push_front(19);
  cout << "PASSED" << endl;
  
  cout << "checking value after full push: ";
  CPPUNIT_ASSERT(b[0] == 19);
  cout << "PASSED" << endl;
  
  cout << "checking size after full push: ";
  CPPUNIT_ASSERT(b.size() == 4);
  cout << "PASSED" << endl;
}

void Test_deque::test_pop_front()
{
  cout << endl << "Testing pop front: " << endl;
  
  Deque<int> b;
  
  cout << "trying pop front when empty: ";
  b.pop_front();
  cout << "PASSED" << endl;
  
  b.push_front(4);
  b.push_front(5);
  b.push_front(9);
  b.push_front(17);
  b.pop_front();
  b.pop_front();
  
  cout << "checking size after pushes and pops: ";
  CPPUNIT_ASSERT(b.size() == 2);
  cout << "PASSED" << endl;
  
  cout << "checking for out of range at old index #: ";
  try
  {
    CPPUNIT_ASSERT(b[2]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  cout << "checking first value in the block: ";
  CPPUNIT_ASSERT(b[0] == 5);
  cout << "PASSED" << endl;
}

void Test_deque::test_push_back()
{
  cout << endl << "Testing push back: " << endl;
  
  Deque<int> b;
  
  b.push_back(4);  
  
  cout << "checking size after 1 push: ";
  CPPUNIT_ASSERT(b.size() == 1);
  cout << "PASSED" << endl;
  
  cout << "checking value of 1st push: ";
  CPPUNIT_ASSERT(b[b.size()-1] == 4);
  cout << "PASSED" << endl;
  
  b.push_back(3);
  b.push_back(2);
  
  cout << "checking value after new pushes: ";
  CPPUNIT_ASSERT(b[b.size()-1] == 2);
  cout << "PASSED" << endl;
  
  cout << "checking size after new pushes: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
  
  cout << "pushing when first block is full: ";
  b.push_back(19);
  cout << "PASSED" << endl;
  
  cout << "checking value after full push: ";
  CPPUNIT_ASSERT(b[b.size()-1] == 19);
  cout << "PASSED" << endl;
  
  cout << "checking size after full push: ";
  CPPUNIT_ASSERT(b.size() == 4);
  cout << "PASSED" << endl;
}

void Test_deque::test_pop_back()
{
  cout << endl << "Testing pop back: " << endl;
  
  Deque<int> b;
  
  cout << "trying pop back when empty: ";
  b.pop_back();
  cout << "PASSED" << endl;
  
  b.push_back(4);
  b.push_back(5);
  b.push_back(9);
  b.push_back(17);
  b.pop_back();
  b.pop_back();
  
  cout << "checking size after pushes and pops: ";
  CPPUNIT_ASSERT(b.size() == 2);
  cout << "PASSED" << endl;
  
  cout << "checking for out of range at old index #: ";
  try
  {
    CPPUNIT_ASSERT(b[2]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  cout << "checking last value in the block: ";
  CPPUNIT_ASSERT(b[1] == 5);
  cout << "PASSED" << endl;
}

void Test_deque::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  
  Deque<int> b;
  
  cout << "trying clear when empty: ";
  b.clear();
  cout << "PASSED" << endl;
  
  b.push_back(4);
  b.push_back(5);
  b.push_back(9);
  
  b.clear();
  cout << "testing size after pushes and clear: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "testing empty after pushes and clear: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  cout << "testing block size after pushes and clear: ";
  CPPUNIT_ASSERT(b.block_size() == 3);
  cout << "PASSED" << endl;
  
  cout << "checking for out of range at old index #: ";
  try
  {
    CPPUNIT_ASSERT(b[0]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
}

void Test_deque::test_assignment_operator()
{
  cout << endl << "Testing assignment operator: " << endl;
  
  Deque<int> b;
  
  b.push_back(0);
  b.push_back(1);
  b.push_back(2);
  b.push_back(17);
  b.push_back(42);
  
  Deque<int> c = b;
  
  cout << "checking equal size: ";
  CPPUNIT_ASSERT(b.size() == c.size());
  cout << "PASSED" << endl;
  
  cout << "checking equal block size: ";
  CPPUNIT_ASSERT(b.block_size() == c.block_size());
  cout << "PASSED" << endl;
  
  c.pop_back();
  c.push_back(7);
  
  cout << "checking all values, ensuring deep copy: ";
  for(int k = 0; k < b.size(); k++)
  {
    if(k == b.size()-1)
	{
	  CPPUNIT_ASSERT(b[k] != c[k]);
	}
	else
	{
	  CPPUNIT_ASSERT(b[k] == c[k]);
	}
  }
  cout << "PASSED" << endl;
}

void Test_deque::test_bracket_operator()
{
  cout << endl << "Testing bracket operator: " << endl;
  
  Deque<int> b;
  
  cout << "trying operator when empty: ";
  try
  {
    CPPUNIT_ASSERT(b[0]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  b.push_front(17);
  b.push_front(9);
  
  cout << "Verifying values after barrage of pushes: ";
  CPPUNIT_ASSERT(b[0] == 9);
  CPPUNIT_ASSERT(b[1] == 17);
  b.push_front(3);
  b.push_front(4);

  CPPUNIT_ASSERT(b[0] == 4);
  CPPUNIT_ASSERT(b[1] == 3);
  CPPUNIT_ASSERT(b[2] == 9);
  cout << "PASSED" << endl;
  
  b.clear();
  b.push_front(1);
  b.push_front(2);
  b.push_front(3);
  b.pop_front();
  b.pop_back();
  
  cout << "Testing block with only center data: ";
  CPPUNIT_ASSERT(b[0] == 2);
  cout << "PASSED" << endl;
}

void Test_deque::test_size()
{
  cout << endl << "Testing size: " << endl;
  
  Deque<int> b;
  
  cout << "checking initial value is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  b.push_back(1);
  b.push_back(2);
  b.push_back(3);
  b.push_back(1);
  b.push_back(2);
  
  cout << "checking value after 5 pushes: ";
  CPPUNIT_ASSERT(b.size() == 5);
  cout << "PASSED" << endl;
  
  b.pop_back();
  b.pop_back();
  
  cout << "checking value after 2 pops: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
}

void Test_deque::test_block_size()
{
  cout << endl << "Testing block size: " << endl;
  
  Deque<int> b;
  Deque<int> c(19);
  Deque<int> d(12);
  
  cout << "checking default value is 3: ";
  CPPUNIT_ASSERT(b.block_size() == 3);
  cout << "PASSED" << endl;
  
  cout << "checking value is 19: ";
  CPPUNIT_ASSERT(c.block_size() == 19);
  cout << "PASSED" << endl;
  
  cout << "checking value is 12: ";
  CPPUNIT_ASSERT(d.block_size() == 12);
  cout << "PASSED" << endl;
}

void Test_deque::test_empty()
{
  cout << endl << "Testing empty: " << endl;
  
  Deque<int> b;
  
  cout << "checking empty initially: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  b.push_front(2);
  b.push_front(2);
  b.push_back(2);
  
  cout << "checking empty after pushes: ";
  CPPUNIT_ASSERT(!b.empty());
  cout << "PASSED" << endl;
  
  b.pop_back();
  cout << "checking empty after pops: ";
  CPPUNIT_ASSERT(!b.empty());
  cout << "PASSED" << endl;
  
  b.clear();
  cout << "checking empty after clear: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
}
