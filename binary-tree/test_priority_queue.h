/*
  File: test_priority_queue.h
  Author: Matthew White CS153 B
  Contains the priority queue testing class prototypes
*/
#ifndef TEST_BST_H
#define TEST_BST_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include"priority_queue.h"
#include<iostream>

using std::endl;
using std::cout;

class Test_priority_queue : public CPPUNIT_NS::TestFixture
{
 public:
  Test_priority_queue();
 private:
  CPPUNIT_TEST_SUITE(Test_priority_queue);
  CPPUNIT_TEST(test_push);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST(test_copy);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TREE_SIZE;
 protected:
  void test_push();
  void test_pop();
  void test_copy();
};

#endif
