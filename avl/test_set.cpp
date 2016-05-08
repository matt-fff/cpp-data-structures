/*
  File: test_set.cpp
  Author: Matthew White CS153 B
  Contains the set testing implementations
*/
#include<cstdlib>
#include<ctime>
#include<iostream>
using std::cout;
using std::endl;
#include"test_set.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_set);

Test_set::Test_set() : TEST_MAX(500)
{
}

void Test_set::test_default_constructor()
{
	cout << endl << "Testing Constructor" << endl;
	Set<int> a;
	cout << "Set is empty: ";
	CPPUNIT_ASSERT(a.empty());
	cout << "PASSED" << endl;
	
	cout << "Size is 0: ";
	CPPUNIT_ASSERT(a.size() == 0);
	cout << "PASSED" << endl;
}

void Test_set::test_addition_operator()
{
	cout << endl << "Testing Union" << endl;
	Set<int> a, b, u;
	int a_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b_array[] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
	int u_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
	for (unsigned int i = 0; i < 9; i++)
	{
		a.insert (a_array[i]);
		b.insert (b_array[i]);
	}
	u = a + b;
	
	cout << "Ensuring correct numbers have been merged: ";
	BTInorderIterator<int> i = u.begin();
	for (unsigned int j = 0; j < u.size(); i++, j++)
	{
		CPPUNIT_ASSERT (u_array[j] == *i);
	}
	cout << "PASSED" << endl;
}

void Test_set::test_assignment_operator()
{
  cout << endl << "Testing assignment operator" << endl;
  Set<int> b;
	
  int array1[] = {16,8,24,4,12,20,28};
  
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
  }
  
  Set<int> c = b;
  cout << "checking copy from known array: ";
  for(int i = 0; i < 7; i++)
  {
	CPPUNIT_ASSERT(c.find(array1[i]) != NULL);
  }
  CPPUNIT_ASSERT(c.find(7) == NULL);//control search
  cout << "PASSED" << endl;
  
   
  srand(int(time(NULL)));
  Set<int> bb;
  int array2[TEST_MAX];
  for(int k = 0; k < TEST_MAX; k++)
  {
    array2[k] = k;
  }
  
  //shuffle
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array2[random1];
	array2[random1] = array2[random2];
	array2[random2] = temp;
  }

  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.insert(array2[i]);
  }
  
  Set<int> cc = bb;
  cout << "checking inserts from crazy shuffle process: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
	CPPUNIT_ASSERT(cc.find(array2[i]) != NULL);
  }
  cout << "PASSED" << endl;
}

void Test_set::test_multiplication_operator()
{
	cout << endl << "Testing Intersection" << endl;
	Set<int> a, b, n;
	int a_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b_array[] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
	int n_array[] = {6, 7, 8, 9};
	for (unsigned int i = 0; i < 9; i++)
	{
		a.insert (a_array[i]);
		b.insert (b_array[i]);
	}
	n = a * b;
	cout << "Ensuring correct numbers have been merged: ";
	BTInorderIterator<int> i = n.begin();
	for (unsigned int j = 0; j < n.size(); i++, j++)
	{
		CPPUNIT_ASSERT (n_array[j] == *i);
	}
	cout << "PASSED" << endl;
}

void Test_set::test_subtraction_operator()
{
	cout << endl << "Testing difference" << endl;
	
	Set<int> a, b, d;
	int a_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b_array[] = {6, 7, 8, 9, 10, 11, 12, 13, 14};
	int d_array[] = {1, 2, 3, 4, 5};
	for (unsigned int i = 0; i < 9; i++)
	{
		a.insert (a_array[i]);
		b.insert (b_array[i]);
	}
	d = a - b;
	cout << "Ensuring correct numbers have been removed: ";
	BTInorderIterator<int> i = d.begin();
	for (unsigned int j = 0; j < d.size(); i++, j++)
	{
		CPPUNIT_ASSERT (d_array[j] == *i);
	}
	cout << "PASSED" << endl;
}

void Test_set::test_insert()
{
  cout << endl << "Testing insert" << endl;
  Set<int> b;
	
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "checking inserts from array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(b.find(array1[k]) != NULL);
	}
  }
  CPPUNIT_ASSERT(b.find(7) == NULL);//control search
  cout << "PASSED" << endl;
  
   
  srand(int(time(NULL)));
  Set<int> bb;
  int array2[TEST_MAX];
  for(int k = 0; k < TEST_MAX; k++)
  {
    array2[k] = k;
  }
  
  //shuffle
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array2[random1];
	array2[random1] = array2[random2];
	array2[random2] = temp;
  }
  
  cout << "checking inserts from crazy shuffle process: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.insert(array2[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(bb.find(array2[k]) != NULL);
	}
  }
  int array3[TEST_MAX];
  for(int k = 0; k < TEST_MAX; k++)
  {
    array3[k] = k;
  }
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array3[random1];
	array3[random1] = array3[random2];
	array3[random2] = temp;
  }
  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.insert(array3[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(bb.find(array3[k]) != NULL);
	}
  }
  CPPUNIT_ASSERT(bb.find(TEST_MAX+1) == NULL);//control search
  cout << "PASSED" << endl;
}

void Test_set::test_erase()
{
  cout << endl << "Testing remove: " << endl;
  Set<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "checking removes from array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
  }
  
  for(int i = 0; i < 7; i++)
  {
    b.remove(array1[i]);
	for(int k = 0; k < 7; k++)
	{
	  if(k > i)
	  {
	    CPPUNIT_ASSERT(b.find(array1[k]) != NULL);
	  }
	  else
	  {
	    CPPUNIT_ASSERT(b.find(array1[k]) == NULL);
	  }
	}
  }
  cout << "PASSED" << endl;

  srand(int(time(NULL)));
  Set<int> bb;
  int array2[TEST_MAX];
  for(int k = 0; k < TEST_MAX; k++)
  {
    array2[k] = k;
  }
  
  //shuffle
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array2[random1];
	array2[random1] = array2[random2];
	array2[random2] = temp;
  }
  
  //insert
  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.insert(array2[i]);
  }
  
  cout << "trying remove with a number that isn't there: ";
  bb.remove(TEST_MAX+1);
  bb.remove(-1);
  cout << "PASSED" << endl;
  
  //shuffle again so we're removing in a different order
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array2[random1];
	array2[random1] = array2[random2];
	array2[random2] = temp;
  }
  
  cout << "checking removes from crazy shuffle process: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.remove(array2[i]);
	for(int k = 0; k < TEST_MAX; k++)
	{
	  if(k > i)
	  {
	    CPPUNIT_ASSERT(bb.find(array2[k]) != NULL);
	  }
	  else
	  {
	    CPPUNIT_ASSERT(bb.find(array2[k]) == NULL);
	  }
	}
  }
  cout << "PASSED" << endl;
}

void Test_set::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  
  cout << "Checking when empty: ";
  
  srand(int(time(NULL)));
  Set<int> bb;
  bb.clear();
  cout << "PASSED" << endl;
  
  int array1[TEST_MAX];
  for(int k = 0; k < TEST_MAX; k++)
  {
    array1[k] = k;
  }
  
  //shuffle
  for(int k = 0; k < TEST_MAX; k++)
  {
    int random1 = rand()%TEST_MAX;
	int random2 = rand()%TEST_MAX;
	int temp = array1[random1];
	array1[random1] = array1[random2];
	array1[random2] = temp;
  }
  
  for(int k = 0; k < TEST_MAX; k++)
  {
    bb.insert(array1[k]);
  }
  
  bb.clear();
  
  cout << "Making sure nothing can be found after clear: ";
  for(int k = 0; k < TEST_MAX; k++)
  {
    CPPUNIT_ASSERT(bb.find(array1[k]) == NULL);
  }
  cout << "PASSED" << endl;
  
  cout << "Checking for size 0: ";
  CPPUNIT_ASSERT(bb.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "Checking empty: ";
  CPPUNIT_ASSERT(bb.empty());
  cout << "PASSED" << endl;
}

void Test_set::test_empty()
{
  cout << endl << "Testing empty: " << endl;
 
  Set<int> bb;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "testing empty with inserts: ";
  for(int i = 0; i < 7; i++)
  {
    bb.insert(array1[i]);
	CPPUNIT_ASSERT(!bb.empty());
  }
  cout << "PASSED" << endl;
  
  cout << "testing empty with removes: ";
  for(int i = 7; i >= 0; i--)
  {
    CPPUNIT_ASSERT(!bb.empty());
    bb.remove(array1[i]);	
  }
  CPPUNIT_ASSERT(bb.empty());
  cout << "PASSED" << endl;
  
  bb.insert(8);
  
  bb.clear();
  
  cout << "Checking empty after clear: ";
  CPPUNIT_ASSERT(bb.empty());
  cout << "PASSED" << endl;
}

void Test_set::test_size()
{
  cout << endl << "Testing size: " << endl;
  
  Set<int> bb;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "testing size with inserts: ";
  for(int i = 0; i < 7; i++)
  {
    bb.insert(array1[i]);
	CPPUNIT_ASSERT(bb.size() == i+1);
  }
  cout << "PASSED" << endl;
  
  cout << "testing size with removes: ";
  for(int i = 7; i >= 0; i--)
  {
    bb.remove(array1[i]);
	CPPUNIT_ASSERT(bb.size() == i);
  }
  cout << "PASSED" << endl;
  
  bb.clear();
  
  cout << "Checking for size 0: ";
  CPPUNIT_ASSERT(bb.size() == 0);
  cout << "PASSED" << endl;
}
