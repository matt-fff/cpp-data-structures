/*
  File: test_bst.h
  Author: Matthew White CS153 B
  Contains the prototypes for the bst testing functions
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
#include "bst.h"

class Test_bst : public CPPUNIT_NS::TestFixture
{
 public:
  Test_bst();

 private:
  CPPUNIT_TEST_SUITE(Test_bst);
  CPPUNIT_TEST(test_default_constructor);
  CPPUNIT_TEST(test_insert);
  CPPUNIT_TEST(test_remove);
  CPPUNIT_TEST(test_search);
  CPPUNIT_TEST(test_clear);
  CPPUNIT_TEST(test_empty);
  CPPUNIT_TEST(test_size);
  CPPUNIT_TEST(test_pre_search);
  CPPUNIT_TEST(test_in_search);
  CPPUNIT_TEST(test_post_search);
  CPPUNIT_TEST(test_preiter);
  CPPUNIT_TEST(test_postiter);
  CPPUNIT_TEST(test_initer);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;
  
 protected:
  void test_default_constructor();
  void test_insert();
  void test_remove();
  void test_search();
  void test_clear();
  void test_empty();
  void test_size();
  void test_pre_search();
  void test_post_search();
  void test_in_search();  
  void test_preiter();
  void test_postiter();
  void test_initer();
};

#endif //TEST_BAG_H
