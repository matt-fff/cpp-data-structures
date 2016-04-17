/*
  File: test_array.h
  Function prototypes and the class declaration for the test_array class
*/

#ifndef TEST_ARRAY_H
#define TEST_ARRAY_H

#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout;
using std::endl;

#include"array.h"
class Test_array : public CPPUNIT_NS::TestFixture
{
 public:
  Test_array();

 private:
  CPPUNIT_TEST_SUITE(Test_array);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_bracket_operator);
  CPPUNIT_TEST(test_push_back);
  CPPUNIT_TEST(test_pop_back);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_bracket_operator();
  void test_push_back();
  void test_pop_back();
  void test_clear();
};

#endif
