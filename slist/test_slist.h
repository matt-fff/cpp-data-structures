/*
  File: test_slist.h
  Contains test prototypes for the slist class
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
#include "slist.h"

class Test_slist : public CPPUNIT_NS::TestFixture
{
 public:
  Test_slist();

 private:
  CPPUNIT_TEST_SUITE(Test_slist);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_push_front);
  CPPUNIT_TEST(test_pop_front);
  CPPUNIT_TEST(test_remove);
  CPPUNIT_TEST(test_front);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_size);
  CPPUNIT_TEST(test_empty);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST(test_iterator_default_constructor);
  CPPUNIT_TEST(test_iterator_parameter_constructor);
  CPPUNIT_TEST(test_iterator_reference_operator);
  CPPUNIT_TEST(test_iterator_increment_operator);
  CPPUNIT_TEST(test_iterator_equal_operator);
  CPPUNIT_TEST(test_iterator_not_equal_operator);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_default_constructor();
  void test_copy_constructor();
  void test_push_front();
  void test_pop_front();
  void test_remove();
  void test_front();
  void test_clear();
  void test_size();
  void test_empty();
  void test_assignment_operator();
  void test_iterator_default_constructor();
  void test_iterator_parameter_constructor();
  void test_iterator_reference_operator();
  void test_iterator_increment_operator();
  void test_iterator_equal_operator();
  void test_iterator_not_equal_operator();
};

#endif
