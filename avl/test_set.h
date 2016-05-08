/*
  File: test_set.h
  Author: Matthew White CS153 B
  Contains the set testing prototypes
*/
#ifndef TEST_SET_H
#define TEST_SET_H
#include<cppunit/extensions/HelperMacros.h>
#include<cppunit/config/SourcePrefix.h>
#include"set.h"

class Test_set : public CPPUNIT_NS::TestFixture
{
 public:
  Test_set();
  
 private:
  CPPUNIT_TEST_SUITE(Test_set);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_addition_operator);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST(test_multiplication_operator);
  CPPUNIT_TEST(test_subtraction_operator);
  CPPUNIT_TEST(test_insert);
  CPPUNIT_TEST(test_erase);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_empty);
  CPPUNIT_TEST(test_size);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_addition_operator();
  void test_assignment_operator();
  void test_multiplication_operator();
  void test_subtraction_operator();
  void test_insert();
  void test_erase();
  void test_clear();
  void test_empty();
  void test_size();
};

#endif
