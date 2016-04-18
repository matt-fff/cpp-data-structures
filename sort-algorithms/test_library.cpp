/*
  File: test_library.cpp
  Contains the implementations for the test_library class
*/
#include "test_library.h"
CPPUNIT_TEST_SUITE_REGISTRATION(Test_library);

Test_library::Test_library() : TEST_MAX(5000)
{
}

void Test_library::test_quick_sort()
{
  cout << endl << "Testing Quick Sort" << endl;
  vector<int> v;
  v.push_back(16);
  v.push_back(3);
  v.push_back(24);
  v.push_back(22);
  v.push_back(26);
  v.push_back(6);
  v.push_back(5);
  v.push_back(4);
  v.push_back(1);
  cout << "Unsorted: ";
  for(int k = 0; k < v.size(); k++)
  {
    cout << v[k] << ", ";
  }
  quick_sort(v);
  cout << endl << "Sorted: ";
  for(int k = 0; k < v.size(); k++)
  {
    cout << v[k] << ", ";
  }
  
  cout << endl << "Checking that each value is greater than or equal to the last: ";
  for(int k = 0; k < v.size()-1; k++)
  {
    CPPUNIT_ASSERT(v[k] <= v[k+1]);
  }
  cout << "PASSED" << endl;
}

void Test_library::test_partition()
{
  cout << endl << "Testing Partition" << endl;
  vector<int> v;
  v.push_back(16);
  v.push_back(3);
  v.push_back(24);
  v.push_back(22);
  v.push_back(26);
  v.push_back(6);
  v.push_back(5);
  v.push_back(4);
  v.push_back(1);
  //we just test for known results from the partition
  
  cout << "checking return values (1): ";
  CPPUNIT_ASSERT(partition(v, 0, 8) == 5);
  cout << "PASSED" << endl;

  cout << "checking return values (2): ";
  CPPUNIT_ASSERT(partition(v, 6, 8) == 6);
  cout << "PASSED" << endl;
  
  cout << "checking return values (3): ";
  CPPUNIT_ASSERT(partition(v, 7, 8) == 8);
  cout << "PASSED" << endl;
  
  cout << "checking return values (4): ";
  CPPUNIT_ASSERT(partition(v, 0, 4) == 0);
  cout << "PASSED" << endl;
  
  cout << "checking return values (4): ";
  CPPUNIT_ASSERT(partition(v, 1, 4) == 1);
  cout << "PASSED" << endl;
  
  cout << "checking return values (5): ";
  CPPUNIT_ASSERT(partition(v, 2, 4) == 4);
  cout << "PASSED" << endl;
  
  cout << "checking return values (4): ";
  CPPUNIT_ASSERT(partition(v, 2, 3) == 2);
  cout << "PASSED" << endl;
  
  cout << endl << "Checking that each value is greater than or equal to the last: ";
  for(int k = 0; k < v.size()-1; k++)
  {
    CPPUNIT_ASSERT(v[k] <= v[k+1]);
  }
  cout << "PASSED" << endl;
}

void Test_library::test_merge_sort()
{
  cout << endl << "Testing Merge Sort" << endl;
  vector<int> v;
  v.push_back(16);
  v.push_back(3);
  v.push_back(24);
  v.push_back(22);
  v.push_back(26);
  v.push_back(6);
  v.push_back(5);
  v.push_back(4);
  v.push_back(1);
  cout << "Unsorted: ";
  for(int k = 0; k < v.size(); k++)
  {
    cout << v[k] << ", ";
  }
  merge_sort(v);
  cout << endl << "Sorted: ";
  for(int k = 0; k < v.size(); k++)
  {
    cout << v[k] << ", ";
  }
  
  cout << endl << "Checking that each value is greater than or equal to the last: ";
  for(int k = 0; k < v.size()-1; k++)
  {
    CPPUNIT_ASSERT(v[k] <= v[k+1]);
  }
  cout << "PASSED" << endl;
}
