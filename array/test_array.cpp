/*
  File: test_array.cpp
  Function implementations for the test_array class
*/

#include"test_array.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_array);

Test_array::Test_array() : TEST_MAX(20)
{
}

void Test_array::test_default_constructor()
{
  Array<int> a;

  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(a.size() == 0);
  cout << "PASSED" << endl;

  cout << "checking that max_size is " << TEST_MAX << ": ";
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;
}

void Test_array::test_bracket_operator()
{
  Array<int> a;

  cout << endl << "TEST BRACKET OPERATOR" << endl;
  cout << "checking write exception: ";
  try
    {
      a[1] = 50;
      CPPUNIT_ASSERT(false);
    }
  catch(out_of_range& e)
    {
      cout << "PASSED" << endl;
    }

  cout << "checking read exception: ";
  try
    {
      int test = a[1];
      CPPUNIT_ASSERT(false);
    }
  catch(out_of_range& e)
    {
      cout << "PASSED" << endl;
    }
}

void Test_array::test_push_back()
{
  Array<int> a;

  cout << endl << "TEST PUSH BACK" << endl;
  cout << "checking one push: ";
  a.push_back(3);
  CPPUNIT_ASSERT(a[0] == 3);
  CPPUNIT_ASSERT(a.size() == 1);
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;

  cout << "checking multiple pushes: ";
  for(int i = a.size(); i < TEST_MAX; i++)
    {
      a.push_back(i);
      CPPUNIT_ASSERT(a[i] == i);
      CPPUNIT_ASSERT(a.size() == i+1);
      CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
    }
  cout << "PASSED" << endl;

  cout << "checking that overflow is ignored: ";
  a.push_back(100);
  CPPUNIT_ASSERT(a.size() == TEST_MAX);
  CPPUNIT_ASSERT(a[TEST_MAX-1] == TEST_MAX-1);
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;
}

void Test_array::test_pop_back()
{
  Array<int> a;

  cout << endl << "TEST POP BACK" << endl;
  cout << "checking one pop: ";
  a.push_back(24);
  a.pop_back();
  CPPUNIT_ASSERT(a.size() == 0);
  CPPUNIT_ASSERT(a.max_size() == 20);
  cout << "PASSED" << endl;

  cout << "checking multiple pops: ";
  for(int i = 0; i < a.max_size(); i++)
    {
      a.push_back(i);
    }

  for(int i = 0; i < TEST_MAX; i++)
    {
      CPPUNIT_ASSERT(a[a.max_size()-(i+1)] == a.max_size()-(i+1));
      CPPUNIT_ASSERT(a.size() == a.max_size()-i);
      a.pop_back();
    }
  cout << "PASSED" << endl;

  cout << "checking that underflow is ignored: ";
  a.pop_back();
  CPPUNIT_ASSERT(a.size() == 0);
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;
}

void Test_array::test_clear()
{
  Array<int> a;
  cout << endl << "TEST CLEAR" << endl;
  cout << "checking clear when full: ";
  for(int i = 0; i < TEST_MAX; i++)
    {
      a.push_back(i);
    }

  a.clear();
  CPPUNIT_ASSERT(a.size() == 0);
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;

  cout << "checking clear when already empty: ";
  a.clear();
  CPPUNIT_ASSERT(a.size() == 0);
  CPPUNIT_ASSERT(a.max_size() == TEST_MAX);
  cout << "PASSED" << endl;
}
