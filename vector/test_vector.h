/*
  File: test_vector.h
  Contains the class declaration and prototypes for test_vector
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
#include "vector.h"

class Test_vector : public CPPUNIT_NS::TestFixture
{
 public:
  Test_vector();

 private:
  CPPUNIT_TEST_SUITE(Test_vector);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_push_back);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST(test_pop_back);
  CPPUNIT_TEST(test_bracket_operator);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_push_back();
  void test_clear();
  void test_copy_constructor();
  void test_assignment_operator();
  void test_pop_back();
  void test_bracket_operator();
};

#endif
