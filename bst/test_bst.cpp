/*
  File: test_bst.cpp
  Author: Matthew White CS153 B
  Contains the implementations for the bst testing functions
*/
#include "test_bst.h"
#include <algorithm>
CPPUNIT_TEST_SUITE_REGISTRATION(Test_bst);

Test_bst::Test_bst() : TEST_MAX(500)
{
}

void Test_bst::test_default_constructor()
{
  cout << endl << "Testing default constructor: " << endl;
  BST<int> b;
  
  cout << "checking empty: ";
  CPPUNIT_ASSERT(b.empty());
  cout << "PASSED" << endl;
  
  cout << "checking size is 0: ";
  CPPUNIT_ASSERT(b.size() == 0);
  cout << "PASSED" << endl;
}

void Test_bst::test_insert()
{
  cout << endl << "Testing insert: " << endl;
  BST<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "checking inserts from array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(b.search(array1[k]));
	}
  }
  CPPUNIT_ASSERT(!b.search(7));//control search
  cout << "PASSED" << endl;
  
   
  srand(int(time(NULL)));
  BST<int> bb;
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
	  CPPUNIT_ASSERT(bb.search(array2[k]));
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
	  CPPUNIT_ASSERT(bb.search(array3[k]));
	}
  }
  CPPUNIT_ASSERT(!bb.search(TEST_MAX+1));//control search
  cout << "PASSED" << endl;
}

void Test_bst::test_remove()
{
  cout << endl << "Testing remove: " << endl;
  BST<int> b;
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
	    CPPUNIT_ASSERT(b.search(array1[k]));
	  }
	  else
	  {
	    CPPUNIT_ASSERT(!b.search(array1[k]));
	  }
	}
  }
  cout << "PASSED" << endl;

  srand(int(time(NULL)));
  BST<int> bb;
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
	    CPPUNIT_ASSERT(bb.search(array2[k]));
	  }
	  else
	  {
	    CPPUNIT_ASSERT(!bb.search(array2[k]));
	  }
	}
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_search()
{
  cout << endl << "Testing search: " << endl;
  
  BST<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "searching from predefined array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(b.search(array1[k]));
	}
  }
  CPPUNIT_ASSERT(!b.search(7));//control search
  cout << "PASSED" << endl;
  
   
  srand(int(time(NULL)));
  BST<int> bb;
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
  
  cout << "searching from crazy shuffle process: ";
  for(int i = 0; i < TEST_MAX; i++)
  {
    bb.insert(array2[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(bb.search(array2[k]));
	}
  }
  CPPUNIT_ASSERT(!bb.search(TEST_MAX+1));//control search
  
  //second shuffle so we search in different order
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
    bb.search(array2[i]);
  }
  cout << "PASSED" << endl;
  
}

void Test_bst::test_clear()
{
  cout << endl << "Testing clear: " << endl;
  
  cout << "Checking when empty: ";
  
  srand(int(time(NULL)));
  BST<int> bb;
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
    CPPUNIT_ASSERT(!bb.search(array1[k]));
  }
  cout << "PASSED" << endl;
  
  cout << "Checking for size 0: ";
  CPPUNIT_ASSERT(bb.size() == 0);
  cout << "PASSED" << endl;
  
  cout << "Checking empty: ";
  CPPUNIT_ASSERT(bb.empty());
  cout << "PASSED" << endl;
}

void Test_bst::test_empty()
{
  cout << endl << "Testing empty: " << endl;
 
  BST<int> bb;
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

void Test_bst::test_size()
{
  cout << endl << "Testing size: " << endl;
  
  BST<int> bb;
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

void Test_bst::test_pre_search()
{
  cout << endl << "Testing pre search: " << endl;
  
  BST<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "searching from predefined array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(*(b.pre_search(array1[k])) == array1[k]);
	}
  }
  cout << "PASSED" << endl;
  BST<int> bb;
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
	  CPPUNIT_ASSERT(*(bb.pre_search(array2[k])) == array2[k]);
	}
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_post_search()
{
  cout << endl << "Testing post search: " << endl;
  
  BST<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "searching from predefined array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(*(b.post_search(array1[k])) == array1[k]);
	}
  }  
  cout << "PASSED" << endl;
  
  BST<int> bb;
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
	  CPPUNIT_ASSERT(*(bb.post_search(array2[k])) == array2[k]);
	}
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_in_search()
{
  cout << endl << "Testing in search: " << endl;
  
  BST<int> b;
  int array1[] = {16,8,24,4,12,20,28};
  
  cout << "searching from predefined array: ";
  for(int i = 0; i < 7; i++)
  {
    b.insert(array1[i]);
	for(int k = 0; k <= i; k++)
	{
	  CPPUNIT_ASSERT(*(b.in_search(array1[k])) == array1[k]);
	}
  }  
  cout << "PASSED" << endl;
 
  /*int array2[TEST_MAX];
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
	  cout << endl << "i: " << i << "\tk: " << k << endl;
	  cout << "tarray[k]: " << array2[k] << endl;
	  CPPUNIT_ASSERT(*(bb.in_search(array2[k])) == array2[k]);
	}
  }
  cout << "PASSED" << endl;*/

}

void Test_bst::test_preiter()
{
  cout << endl << "Testing pre iterator: " << endl;  
  int array[] = {17,11,33,4,15,35,8,14,34,47};
  int order[] = {17,11,4,8,15,14,33,35,34,47};
  BST<int> b;
  
  
  for(int k = 0; k < 10; k++)
  {
    b.insert(array[k]);
  }
  
  BTPreorderIterator<int> i = b.pre_begin();
  
  cout << "Using known tree to test for order: ";
  for(int j = 0;
  i != b.pre_end(); j++, i++)
  {
    //cout << "i: " << *i << "\torder: " << order[j] << endl;
	cout << "i: " << *i << endl;
    CPPUNIT_ASSERT(*i == order[j]);
	CPPUNIT_ASSERT(*i != 9);//control test
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_postiter()
{
  cout << endl << "Testing post iterator: " << endl;
  int array[] = {17,11,33,4,15,35,8,14,34,47};
  int order[] = {8,4,14,15,11,34,47,35,33,17};
  BST<int> b;
  
  
  for(int k = 0; k < 10; k++)
  {
    b.insert(array[k]);
  }
  
  BTPostorderIterator<int> i = b.post_begin();
  
  cout << "Using known tree to test for order: ";
  for(int j = 0;
  i != b.post_end(); j++, i++)
  {
    //cout << "i: " << *i << "\torder: " << order[j] << endl;
	cout << "i: " << *i << endl;
    CPPUNIT_ASSERT(*i == order[j]);
	CPPUNIT_ASSERT(*i != 9);//control test
  }
  cout << "PASSED" << endl;
}

void Test_bst::test_initer()
{
  cout << endl << "Testing in iterator: " << endl;
  int array[] = {17,11,33,4,15,35,8,14,34,47};
  int order[] = {4,8,11,14,15,17,33,34,35,47};
  BST<int> b;
  
  
  for(int k = 0; k < 10; k++)
  {
    b.insert(array[k]);
  }
  
  BTInorderIterator<int> i = b.in_begin();
  
  cout << "Using known tree to test for order: ";
  for(int j = 0;
  i != b.in_end();
  j++, i++)
  {
    cout << "i: " << *i << endl;// << *i << "\torder: " << order[j] << endl;
    CPPUNIT_ASSERT(*i == order[j]);
	CPPUNIT_ASSERT(*i != 9);//control test
  }
  cout << "PASSED" << endl;
}

