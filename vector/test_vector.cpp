/*
  File: test_vector.cpp
  Contains the vector testing implementations
*/

#include "test_vector.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_vector);

Test_vector::Test_vector() : TEST_MAX(4000)
{
}

void Test_vector::test_default_constructor()
{
  cout << endl << "TEST DEFAULT CONSTRUCTOR" << endl;
  Vector<int> v;
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(v.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking that max size is 1: ";
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
}

void Test_vector::test_push_back()
{
  cout << endl << "TEST PUSH BACK" << endl;
  
  cout << "checking values after two pushes: ";
  Vector<int> v;
  v.push_back(34);
  CPPUNIT_ASSERT(v.size() == 1);
  CPPUNIT_ASSERT(v[0] == 34);
  CPPUNIT_ASSERT(v.max_size() == 1);
  
  v.push_back(12);
  CPPUNIT_ASSERT(v.size() == 2);
  CPPUNIT_ASSERT(v[1] == 12);
  CPPUNIT_ASSERT(v.max_size() == 2);
  cout << "PASSED" << endl;
  
  cout << "checking values to TEST_MAX: ";
  for(int k = 2; k < TEST_MAX; k++)
  {
    v.push_back(k);
	CPPUNIT_ASSERT(v.size() == k+1);
	CPPUNIT_ASSERT(v[k] == k);
	CPPUNIT_ASSERT(v.max_size() == pow(2, floor(log(k)/log(2))+1));
  }
  cout << "PASSED" << endl;
}

void Test_vector::test_clear()
{
  cout << endl << "TEST CLEAR" << endl;
  Vector<int> v;
  for(int k = 0; k < TEST_MAX; k++)
  {
    v.push_back(k);
  }
  v.clear();
  
  cout << "checking that size is 0: ";
  CPPUNIT_ASSERT(v.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "checking that max size is 1: ";
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
  
  v.clear();
}

void Test_vector::test_copy_constructor()
{
  cout << endl << "TEST COPY CONSTRUCTOR" << endl;
  cout << "checking size, value, and max size after copy: ";
  Vector<int> v;
  v.push_back(7);
  v.push_back(21);
  v.push_back(17);
  v.push_back(24);
  v.push_back(111);
  Vector<int> d(v);
  CPPUNIT_ASSERT(v.max_size() == d.max_size());
  CPPUNIT_ASSERT(v.size() == d.size());
  d[1] = 2;//to ensure it wasn't a shallow copy
  
  for(int k = 0; k < v.size(); k++)
  {
    if(k != 1)
	{
	  CPPUNIT_ASSERT(v[k] == d[k]);
	}
	else
	{
	  CPPUNIT_ASSERT(v[k] != d[k]);
	}
  }
  
  cout << "PASSED" << endl;
}

void Test_vector::test_assignment_operator()
{
  cout << endl << "TEST ASSIGNMENT OPERATOR" << endl;
  
  Vector<int> v;
  cout << "checking values after assignment: ";
  for(int k = 0; k < TEST_MAX; k++)
  {
    v.push_back(1);
	v[k] = k/4;
	CPPUNIT_ASSERT(v[k] == k/4);
  }
  cout << "PASSED" << endl;
}

void Test_vector::test_pop_back()
{
  cout << endl << "TEST POP BACK" << endl;
  Vector<int> v;
  
  //pushes lots of stuff onto the vector
  for(int k = 0; k < TEST_MAX; k++)
  {
    v.push_back(k);
  }
  
  cout << "checking single pop results: ";
  v.pop_back();
  CPPUNIT_ASSERT(v[v.size()-1] == 3998);
  CPPUNIT_ASSERT(v.max_size() == 4096);
  cout << "PASSED" << endl;
  
  cout << "checking size and scaling: ";
  //pops all the stuff off, checking for errors
  for(int k = v.size(); k > 1; k--)
  {
    v.pop_back();
	//cout << "size: " << v.size() << "\tmax size: " << v.max_size() << endl;
	CPPUNIT_ASSERT(v.size() == k-1);
	CPPUNIT_ASSERT(v.size() > v.max_size()/4);
	CPPUNIT_ASSERT(v.size() < v.max_size());
  }
  cout << "PASSED" << endl;
  
  cout << "checking special case of size zero: ";
  v.pop_back();
  CPPUNIT_ASSERT(v.size() == 0);
  CPPUNIT_ASSERT(v.max_size() == 1);
  cout << "PASSED" << endl;
  
  v.pop_back();
}

void Test_vector::test_bracket_operator()
{
  cout << endl << "TEST BRACKET OPERATOR" << endl;
  
  Vector<int> v;
  cout << "checking values returned after pushes: ";
  for(int k = 0; k < TEST_MAX; k++)
  {
    v.push_back(k/4);
	CPPUNIT_ASSERT(v[k] == k/4);
  }
  cout << "PASSED" << endl;

  cout << "checking values returned after bracket assignment: ";  
  v[0] = 4;
  v[9] = 87;
  
  CPPUNIT_ASSERT(v[0] == 4);
  CPPUNIT_ASSERT(v[9] == 87);
  cout << "PASSED" << endl;
}
