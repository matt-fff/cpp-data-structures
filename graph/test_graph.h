/*
  File: test_graph.h
  Author: Matthew White CS153 B
  Contains the graph testing class prototypes
*/
#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>
#include "graph.h"
#include "solver.h"
#include <iostream>
#include <set>

using std::endl;
using std::cout;

class Test_graph : public CPPUNIT_NS::TestFixture
{
 public:
  Test_graph();
 private:
  CPPUNIT_TEST_SUITE(Test_graph);
  CPPUNIT_TEST(test_constructor);
  CPPUNIT_TEST(test_copy_constructor);
  CPPUNIT_TEST(test_file_constructor);
  CPPUNIT_TEST(test_assignment_operator);
  CPPUNIT_TEST(test_insertEdge);
  CPPUNIT_TEST(test_insertNode);
  CPPUNIT_TEST(test_remove_edge);
  CPPUNIT_TEST(test_remove_node);
  CPPUNIT_TEST(test_find_node);
  CPPUNIT_TEST(test_find_edge);
  CPPUNIT_TEST(test_edge_iterator);
  CPPUNIT_TEST(test_node_iterator);
  CPPUNIT_TEST(find_route);
  CPPUNIT_TEST_SUITE_END();
  //unsigned int TREE_SIZE;
 protected:
  void test_constructor();
  void test_copy_constructor();
  void test_file_constructor();
  void test_assignment_operator();
  void test_insertEdge();
  void test_insertNode();
  void test_remove_edge();
  void test_remove_node();
  void test_find_node();
  void test_find_edge();
  void test_edge_iterator();
  void test_node_iterator();
  void find_route();
};

#endif
