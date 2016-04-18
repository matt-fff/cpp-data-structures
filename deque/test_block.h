/*
  File: test_block.h
  Contains the class and prototypes for the test_block class
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
#include "block.h"

class Test_block : public CPPUNIT_NS::TestFixture
{
 public:
  Test_block();

 private:
  CPPUNIT_TEST_SUITE(Test_block);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_param_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST(test_push_front);
  CPPUNIT_TEST(test_pop_front);
  CPPUNIT_TEST(test_push_back);
  CPPUNIT_TEST(test_pop_back);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_bracket_operator);
  CPPUNIT_TEST(test_size);
  CPPUNIT_TEST(test_max_size);
  CPPUNIT_TEST(test_ffull);
  CPPUNIT_TEST(test_bfull);
  CPPUNIT_TEST(test_empty);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_param_constructor();
  void test_copy_constructor();
  void test_assignment_operator();
  void test_push_front();
  void test_pop_front();
  void test_push_back();
  void test_pop_back();
  void test_clear();
  void test_bracket_operator();
  void test_size();
  void test_max_size();
  void test_ffull();
  void test_bfull();
  void test_empty();  
};

#endif
