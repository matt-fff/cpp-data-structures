/*
  File: test_priority_queue.cpp
  Author: Matthew White CS153 B
  Contains the priority queue testing class implementations
*/
#include"test_priority_queue.h"

CPPUNIT_TEST_SUITE_REGISTRATION(Test_priority_queue);

Test_priority_queue::Test_priority_queue() : TREE_SIZE(5000)
{
}

void Test_priority_queue::test_push()
{
  cout << endl << "Testing push" << endl;
  Priority_queue<int> b;
	
  int array1[] = {4,8,12,16,20,24,28};
  
  cout << "checking pushes from ordered array: ";
  for(int i = 0; i < 7; i++)
  {
    b.push(array1[i]);
	CPPUNIT_ASSERT(b.top() == array1[i]);
  }
  b.push(1);
  CPPUNIT_ASSERT(b.top() == array1[6]);//control search
  cout << "PASSED" << endl;
  
   
  srand(int(time(NULL)));
  Priority_queue<int> bb;
  
  int inOrder[TREE_SIZE];
  int shuffled[TREE_SIZE];
  for(int k = 0; k < TREE_SIZE; k++)
  {
    inOrder[k] = k;
	shuffled[k] = k;
  }
  
  //shuffles the array
  for(int k = 0; k < TREE_SIZE; k++)
  {
    int random1 = rand()%TREE_SIZE;
	int random2 = rand()%TREE_SIZE;
	int temp = shuffled[random1];
	shuffled[random1] = shuffled[random2];
	shuffled[random2] = temp;
  }
  
  cout << "checking top values from crazy shuffle process: ";
  //inserts the shuffled array
  for(int i = 0; i < TREE_SIZE; i++)
  {
    bb.push(shuffled[i]);
  }
  
  //uses inOrder array to make sure the highest number
  //is on top every time
  for(int i = TREE_SIZE-1; i >= 0; i--)
  {
	CPPUNIT_ASSERT(bb.top() == inOrder[i]);
	CPPUNIT_ASSERT(bb.top() != (-1));//control test
	bb.pop();
  }
  
  cout << "PASSED" << endl;
}

void Test_priority_queue::test_pop()
{
  cout << endl << "Testing pop" << endl;
  Priority_queue<int> b;
	
  int array1[] = {4,8,12,16,20,24,28};
  
  cout << "checking pops using an ordered array: ";
  for(int i = 0; i < 7; i++)
  {
    b.push(array1[i]);
  }
  
  for(int i = 6; i >= 0; i--)
  {
	CPPUNIT_ASSERT(b.top() == array1[i]);
    b.pop();
  }
  cout << "PASSED" << endl;
 
  cout << "checking for exception when trying to see top of empty queue: ";
  try
  {
    CPPUNIT_ASSERT(b.top());
  }
  catch(out_of_range& e)
  {
      cout << "PASSED" << endl;
  }
  
   
  srand(int(time(NULL)));
  Priority_queue<int> bb;
  
  int inOrder[TREE_SIZE];
  int shuffled[TREE_SIZE];
  for(int k = 0; k < TREE_SIZE; k++)
  {
    inOrder[k] = k;
	shuffled[k] = k;
  }
  
  //shuffles the array
  for(int k = 0; k < TREE_SIZE; k++)
  {
    int random1 = rand()%TREE_SIZE;
	int random2 = rand()%TREE_SIZE;
	int temp = shuffled[random1];
	shuffled[random1] = shuffled[random2];
	shuffled[random2] = temp;
  }
  
  cout << "checking top values from crazy shuffle process: ";
  //inserts the shuffled array
  for(int i = 0; i < TREE_SIZE; i++)
  {
    bb.push(shuffled[i]);
  }
  
  //uses inOrder array to make sure the highest number
  //is on top every time
  for(int i = TREE_SIZE-1; i >= 0; i--)
  {
	CPPUNIT_ASSERT(bb.top() == inOrder[i]);
	CPPUNIT_ASSERT(bb.top() != (-1));//control test
	bb.pop();
  }
  
  cout << "PASSED" << endl;
  
  cout << "testing pop on empty queue: ";
  Priority_queue<int> z;
  z.pop();
  cout << "PASSED" << endl;
}

void Test_priority_queue::test_copy()
{
  cout << endl << "Testing copy constructor and assignment operator" << endl;
  
  srand(int(time(NULL)));
  
  int inOrder[TREE_SIZE];
  int shuffled[TREE_SIZE];
  for(int k = 0; k < TREE_SIZE; k++)
  {
    inOrder[k] = k;
	shuffled[k] = k;
  }
  
  //shuffles the array
  for(int k = 0; k < TREE_SIZE; k++)
  {
    int random1 = rand()%TREE_SIZE;
	int random2 = rand()%TREE_SIZE;
	int temp = shuffled[random1];
	shuffled[random1] = shuffled[random2];
	shuffled[random2] = temp;
  }
  
  Priority_queue<int> b;  
  
  cout << "checking top values from copy constructor: ";
  //inserts the shuffled array
  for(int i = 0; i < TREE_SIZE; i++)
  {
    b.push(shuffled[i]);
  }
  
  Priority_queue<int> c(b);
 
  //uses inOrder array to make sure the highest number
  //is on top every time
  for(int i = TREE_SIZE-1; i >= 0; i--)
  {
	CPPUNIT_ASSERT(b.top() == inOrder[i] && c.top() == inOrder[i]);
	CPPUNIT_ASSERT(b.top() != (-1));//control test
	b.pop();
	c.pop();
  }
  
  cout << "PASSED" << endl;
  
  Priority_queue<int> bb;
  Priority_queue<int> cc;
  
  
  cout << "checking top values from assignment operator: ";
  //inserts the shuffled array
  for(int i = 0; i < TREE_SIZE; i++)
  {
    bb.push(shuffled[i]);
  }
  
  cc = bb;
  
  //uses inOrder array to make sure the highest number
  //is on top every time
  for(int i = TREE_SIZE-1; i >= 0; i--)
  {
	CPPUNIT_ASSERT(bb.top() == inOrder[i] && cc.top() == inOrder[i]);
	CPPUNIT_ASSERT(bb.top() != (-1));//control test
	bb.pop();
	cc.pop();
  }
  
  cout << "PASSED" << endl;
  
  Priority_queue<int> bbb;
  Priority_queue<int> ccc;
  
  //inserts the shuffled array
  for(int i = 0; i < TREE_SIZE; i++)
  {
    bbb.push(shuffled[i]);
  }
  
  ccc = bbb;
  
  ccc.pop();
  
  cout << "checking top values different after one-sided pop: ";
  CPPUNIT_ASSERT(bbb.top() != ccc.top());
  cout << "PASSED" << endl;
  
  cout << "checking pushes with copied queue: ";
  int array1[] = {7009,8000,8005,8009,9000,9009,9099};
  
  for(int i = 0; i < 7; i++)
  {
    ccc.push(array1[i]);
	CPPUNIT_ASSERT(ccc.top() == array1[i]);
  }
  ccc.push(1);
  CPPUNIT_ASSERT(ccc.top() == array1[6]);//control search
  cout << "PASSED" << endl;
  
}
