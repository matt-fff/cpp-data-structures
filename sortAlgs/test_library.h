/*
  File: test_library.h
  Contains the prototypes for the test_library class
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
#include "library.h"

class Test_library : public CPPUNIT_NS::TestFixture
{
 public:
  Test_library();

 private:
  CPPUNIT_TEST_SUITE(Test_library);
  CPPUNIT_TEST(test_quick_sort);
  CPPUNIT_TEST(test_merge_sort);
  CPPUNIT_TEST(test_partition);
  CPPUNIT_TEST_SUITE_END();
  unsigned int TEST_MAX;

 protected:
  void test_quick_sort();
  void test_merge_sort();
  void test_partition();
};

#endif
