/*
  File: test_block.cpp
  Contains the test implementations for test_block
*/
#include "test_block.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test_block);


Test_block::Test_block() : TEST_MAX(5000)
{
}

void Test_block::test_default_constructor()
{
  cout << endl << endl << "TEST BLOCK" << endl << endl;
  cout << endl << "Testing default constructor: " << endl;
  
  Block<int> b;
  
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking max size is 3: ";
  CPPUNIT_ASSERT(b.max_size() == 3);
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

void Test_block::test_param_constructor()
{
  cout << endl << "Testing parameter constructor: " << endl;
  
  Block<int> b(5);
  
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking max size is 5: ";
  CPPUNIT_ASSERT(b.max_size() == 5);
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

void Test_block::test_copy_constructor()
{
  cout << endl << "Testing copy constructor: " << endl;
  
  Block<int> b;
  
  b.push_back(0);
  b.push_back(1);
  b.push_back(2);
  
  Block<int> c(b);
  
  cout << "checking equal size: ";
  CPPUNIT_ASSERT(b.size() == c.size());
  cout << "PASSED" << endl;
  
  cout << "checking equal max size: ";
  CPPUNIT_ASSERT(b.max_size() == c.max_size());
  cout << "PASSED" << endl;
  
  c.pop_back();
  c.push_back(7);
  
  cout << "checking all values, ensuring deep copy: ";
  for(int k = 0; k < b.size(); k++)
  {
    if(k == 2)
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

void Test_block::test_assignment_operator()
{
  cout << endl << "Testing assignment operator: " << endl;
  
  Block<int> b;
  
  b.push_back(0);
  b.push_back(1);
  b.push_back(2);
  
  Block<int> c = b;
  
  cout << "checking equal size: ";
  CPPUNIT_ASSERT(b.size() == c.size());
  cout << "PASSED" << endl;
  
  cout << "checking equal max size: ";
  CPPUNIT_ASSERT(b.max_size() == c.max_size());
  cout << "PASSED" << endl;
  
  c.pop_back();
  c.push_back(7);
  
  cout << "checking all values, ensuring deep copy: ";
  for(int k = 0; k < b.size(); k++)
  {
    if(k == 2)
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

void Test_block::test_push_front()
{
  cout << endl << "Testing push front: " << endl;
  
  Block<int> b;
  
  b.push_front(4);  
  
  cout << "checking size after 1 push: ";
  CPPUNIT_ASSERT(b.size() == 1);
  cout << "PASSED" << endl;
  
  cout << "checking value of 1st push: ";
  CPPUNIT_ASSERT(b[0] == 4);
  cout << "PASSED" << endl;
  
  cout << "checking ffull when it isn't: ";
  CPPUNIT_ASSERT(!b.ffull());
  cout << "PASSED" << endl;
  
  b.push_front(3);
  b.push_front(2);
  
  cout << "checking value of new pushes: ";
  CPPUNIT_ASSERT(b[0] == 2);
  cout << "PASSED" << endl;
  cout << "checking ffull when it is: ";
  CPPUNIT_ASSERT(b.ffull());
  cout << "PASSED" << endl;
  cout << "checking size after new pushes: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
  
  cout << "trying a push when full: ";
  b.push_front(2);
  cout << "PASSED" << endl;
}

void Test_block::test_pop_front()
{
  cout << endl << "Testing pop front: " << endl;
  
  Block<int> b;
  
  cout << "trying pop front when empty: ";
  b.pop_front();
  cout << "PASSED" << endl;
  
  b.push_front(4);
  b.push_front(5);
  b.push_front(9);
  b.pop_front();
  
  cout << "checking size after pushes and pop: ";
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

void Test_block::test_push_back()
{
  cout << endl << "Testing push back: " << endl;
  
  Block<int> b;
  
  b.push_back(4);  
  
  cout << "checking size after 1 push: ";
  CPPUNIT_ASSERT(b.size() == 1);
  cout << "PASSED" << endl;
  
  cout << "checking value of 1st push: ";
  CPPUNIT_ASSERT(b[0] == 4);
  cout << "PASSED" << endl;
  
  cout << "checking bfull when it isn't: ";
  CPPUNIT_ASSERT(!b.bfull());
  cout << "PASSED" << endl;
  
  b.push_back(3);
  b.push_back(2);
  
  cout << "checking value of 2nd push: ";
  CPPUNIT_ASSERT(b[2] == 2);
  cout << "PASSED" << endl;
  cout << "checking bfull when it is: ";
  CPPUNIT_ASSERT(b.bfull());
  cout << "PASSED" << endl;
  
  cout << "checking size after 3rd push: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
  
  cout << "trying a push when full: ";
  b.push_back(2);
  cout << "PASSED" << endl;
}

void Test_block::test_pop_back()
{
  cout << endl << "Testing pop back: " << endl;
  
  Block<int> b;
  
  cout << "trying pop back when empty: ";
  b.pop_back();
  cout << "PASSED" << endl;
  
  b.push_back(4);
  b.push_back(5);
  b.push_back(9);
  b.pop_back();
  
  cout << "checking size after pushes and pop: ";
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

void Test_block::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  
  Block<int> b;
  
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

void Test_block::test_bracket_operator()
{
  cout << endl << "Testing bracket operator: " << endl;
  
  Block<int> b;
  
  cout << "trying operator when empty: ";
  try
  {
    CPPUNIT_ASSERT(b[0]);
  }
  catch(out_of_range& e)
  {
    cout << "PASSED" << endl;
  }
  
  b.push_front(9);
  cout << "Verifying proxy index of 0 at actual index of 2: ";
  CPPUNIT_ASSERT(b[0] == 9);
  cout << "PASSED" << endl;
  
  b.push_front(3);
  b.push_front(4);
  
  cout << "Verifying #'s in full block: ";
  CPPUNIT_ASSERT(b[0] == 4 || b[1] == 3 || b[2] == 9);
  cout << "PASSED" << endl;
  
  b.pop_front();
  b.pop_back();
  
  cout << "Testing block with only center data: ";
  CPPUNIT_ASSERT(b[0] == 3);
  cout << "PASSED" << endl;
}

void Test_block::test_size()
{
  cout << endl << "Testing size: " << endl;
  
  Block<int> b;
  
  cout << "checking initial value is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
  
  b.push_back(1);
  b.push_back(2);
  b.push_back(3);
  
  cout << "checking value after 3 pushes: ";
  CPPUNIT_ASSERT(b.size() == 3);
  cout << "PASSED" << endl;
  
  b.pop_back();
  b.pop_back();
  
  cout << "checking value after 2 pops: ";
  CPPUNIT_ASSERT(b.size() == 1);
  cout << "PASSED" << endl;
}

void Test_block::test_max_size()
{
  cout << endl << "Testing size: " << endl;
  
  Block<int> b;
  
  cout << "checking value from default constructor: ";
  CPPUNIT_ASSERT(b.max_size() == 3);
  cout << "PASSED" << endl;
  
  Block<int> c(9);
  
  cout << "checking value from parameter constructor: ";
  CPPUNIT_ASSERT(c.max_size() == 9);
  cout << "PASSED" << endl;
}

void Test_block::test_ffull()
{
  cout << endl << "Testing ffull: " << endl;
  
  Block<int> b;
  
  b.push_front(4); 
  
  cout << "checking ffull when it isn't: ";
  CPPUNIT_ASSERT(!b.ffull());
  cout << "PASSED" << endl;
  
  b.push_front(3);
  b.push_front(2);
  
  cout << "checking ffull when it is: ";
  CPPUNIT_ASSERT(b.ffull());
  cout << "PASSED" << endl;
}

void Test_block::test_bfull()
{
  cout << endl << "Testing bfull: " << endl;
  
  Block<int> b;
  
  b.push_back(4); 
  
  cout << "checking bfull when it isn't: ";
  CPPUNIT_ASSERT(!b.bfull());
  cout << "PASSED" << endl;
  
  b.push_back(3);
  b.push_back(2);
  
  cout << "checking bfull when it is: ";
  CPPUNIT_ASSERT(b.bfull());
  cout << "PASSED" << endl;
}

void Test_block::test_empty()
{
  cout << endl << "Testing empty: " << endl;
  
  Block<int> b;
  
  cout << "checking empty initially: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  b.push_front(2);
  
  cout << "checking empty when not: ";
  CPPUNIT_ASSERT(!b.empty());
  cout << "PASSED" << endl;
  
  b.clear();
  cout << "checking empty after clear: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
}
