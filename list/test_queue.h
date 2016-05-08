/*
  File: test_queue.h
  Author: Matthew White CS153 B
  Contains the class and prototypes for the test_queue class
*/
#ifndef TEST_BAG_H
#define TEST_BAG_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout;
using std::endl;
#include<cmath>
#include "queue.h"

class Test_queue : public CPPUNIT_NS::TestFixture
{
 public:
  Test_queue();

 private:
  CPPUNIT_TEST_SUITE(Test_queue);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_push);
  CPPUNIT_TEST(test_pop);
  CPPUNIT_TEST(test_front);
  CPPUNIT_TEST(test_back);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_size);
  CPPUNIT_TEST(test_empty);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_copy_constructor();
  void test_push();
  void test_pop();
  void test_front();
  void test_back();
  void test_clear();
  void test_size();
  void test_empty();
  void test_assignment_operator();
};

#endif
