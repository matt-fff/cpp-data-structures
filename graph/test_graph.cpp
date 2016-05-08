/*
  File: test_graph.cpp
  Author: Matthew White CS153 B
  Contains the graph testing class implementations
*/
#include "test_graph.h"
#include <fstream>
#include <string>

CPPUNIT_TEST_SUITE_REGISTRATION(Test_graph);

Test_graph::Test_graph()
{
}


void Test_graph::test_constructor()
{
	//cout << endl <<
}

void Test_graph::test_copy_constructor()
{
	cout << endl << "Testing Copy Constructor" << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	graph map1(fin);
	fin.close();
	
	graph map2(map1);
	
	map2.removeNode(map2.find("bentonville"));//to ensure deep copy
	cout << "Checking all nodes copied: ";
	bool bentonvilleAppeared = false;
	for(graph::NodeIterator k = map1.beginNode(); k != map1.endNode(); k++)
	{
		if((*k)->name != "bentonville")
		{
			CPPUNIT_ASSERT(map2.find((*k)->name) != NULL);
		}
		else
		{
			bentonvilleAppeared = true;
			CPPUNIT_ASSERT(map2.find((*k)->name) == NULL);
		}
	}
	cout << "PASSED" << endl;
	
	cout << "Checking node was deleted from one and not the other: ";
	CPPUNIT_ASSERT(bentonvilleAppeared);
	cout << "PASSED" << endl;
}

//I warn you, this test is nasty
void Test_graph::test_file_constructor()
{
	cout << endl << "Testing File Constructor: " << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	graph map(fin);
	fin.close();
	fin.open("connections.txt", fstream::in);	
	
	cout << "ensuring all edges from file can be found: ";
	while(fin.good())
	{
		//this loop ignores the irrelevent stuff
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
    
		if(fin.good())
		{
			string source, target;
			string tempEdges, tempMph, tempMiles;
			int sourceEdges;
			double mph, miles;
	
			//get the source
			while(fin.good() 
				&& fin.peek() != ' '
				&& fin.peek() != '\t'
				&& fin.peek() != '\n')
			{
				source.push_back(fin.get());
			}
	
			//skip past nonsense
			while(fin.good() 
				&& (fin.peek() == ' '
				|| fin.peek() == '\t'
				|| fin.peek() == '\n'))
			{
				fin.ignore();
			}
	
			//get the number of edges
			while(fin.good() 
				&& fin.peek() != ' '
				&& fin.peek() != '\t'
				&& fin.peek() != '\n')
			{
				tempEdges.push_back(fin.get());
			}
			sourceEdges = atoi(tempEdges.c_str());
	
			//get all of the destinations and their cost
			for(int k = 0; k < sourceEdges; k++)
			{
				//skip past nonsense
				while(fin.good() 
					&& (fin.peek() == ' '
					|| fin.peek() == '\t'
					|| fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the target
				while(fin.good() 
					&& fin.peek() != ' '
					&& fin.peek() != '\t'
					&& fin.peek() != '\n')
				{
					target.push_back(fin.get());
				}
		
				//skip past nonsense
				while(fin.good() 
					&& (fin.peek() == ' '
					|| fin.peek() == '\t'
					|| fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the distance
				while(fin.good() 
					&& fin.peek() != ' '
					&& fin.peek() != '\t'
					&& fin.peek() != '\n')
				{
				tempMiles.push_back(fin.get());
				}
				miles = atof(tempMiles.c_str());
		
				//skip past nonsense
				while(fin.good() 
					&& (fin.peek() == ' '
					|| fin.peek() == '\t'
					|| fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the mph
				while(fin.good() 
					&& fin.peek() != ' '
					&& fin.peek() != '\t'
					&& fin.peek() != '\n')
				{
					tempMph.push_back(fin.get());
				}
				mph = atof(tempMph.c_str());
		
				CPPUNIT_ASSERT(map.find(source, target, mph, miles) != NULL);
				tempMph = tempMiles = target = "";
			}
		}
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_assignment_operator()
{
	cout << endl << "Testing Assignment Operator" << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	graph map1(fin);
	fin.close();
	
	graph map2;
	map2 = map1;
	
	map2.removeNode(map2.find("bentonville"));//to ensure deep copy
	cout << "Checking all nodes copied: ";
	bool bentonvilleAppeared = false;
	for(graph::NodeIterator k = map1.beginNode(); k != map1.endNode(); k++)
	{
		if((*k)->name != "bentonville")
		{
			CPPUNIT_ASSERT(map2.find((*k)->name) != NULL);
		}
		else
		{
			bentonvilleAppeared = true;
			CPPUNIT_ASSERT(map2.find((*k)->name) == NULL);
		}
	}
	cout << "PASSED" << endl;
	
	cout << "Checking node was deleted from one and not the other: ";
	CPPUNIT_ASSERT(bentonvilleAppeared);
	cout << "PASSED" << endl;
}

void Test_graph::test_insertEdge()
{
	cout << endl << "Testing Insert Edge" << endl;

	double mph[] = {85, 75, 65, 55, 45, 35};
	double miles[]	= {12.3, 19.4, 10.23, 1, 99, 203.2};
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};
	
	graph map1;
	
	cout << "Testing nodes and edges found after edge inserts: ";
	for(int k = 0; k < 6; k++)
	{
		map1.insertEdge(names[k], names[k+1], mph[k], miles[k]);
		for(int j = 0; j < k; j++)
		{
			//test to find nodes
			CPPUNIT_ASSERT(map1.find(names[j]) != NULL);
			CPPUNIT_ASSERT(map1.find("Not a place") == NULL);
			
			//test to find edges
			CPPUNIT_ASSERT(map1.find(names[j], names[j+1], mph[j], miles[j]) != NULL);
			CPPUNIT_ASSERT(map1.find("Not", "A Place", 12, 19) == NULL);
		}
		CPPUNIT_ASSERT(map1.find(names[k+1]) != NULL);
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_insertNode()
{
	cout << endl << "Testing Insert Node" << endl;
	
	graph map1;	
	
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};	
	
	cout << "Testing nodes found after node inserts: ";
	for(int k = 0; k < 7; k++)
	{
		map1.insertNode(names[k]);
		
		for(int j = 0; j < k; j++)
		{
			CPPUNIT_ASSERT(map1.find(names[j]) != NULL);
			CPPUNIT_ASSERT(map1.find("Not a place!") == NULL);
		}
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_remove_edge()
{
	cout << endl << "Testing Remove Edge" << endl;
	
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	graph map1(fin);
	fin.close();
	
	double mph[] = {85, 75, 65, 55, 45, 35};
	double miles[]	= {12.3, 19.4, 10.23, 1, 99, 203.2};
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};
	
	for(int k = 0; k < 6; k++)
	{
		map1.insertEdge(names[k], names[k+1], mph[k], miles[k]);
	}
	
	cout << "Checking removed edges are gone and remaining edges are accessible: ";
	for(int k = 0; k < 6; k++)
	{
		//are the remaining edges intact?
		for(int j = k; j < 6; j++)
		{
			CPPUNIT_ASSERT(map1.find(names[j], names[j+1], mph[j], miles[j]) != NULL);
		}
		
		map1.removeEdge(map1.find(names[k], names[k+1], mph[k], miles[k]));
		
		//are the removed edges gone?
		for(int j = 0; j < k; j++)
		{
			CPPUNIT_ASSERT(map1.find(names[j], names[j+1], mph[j], miles[j]) == NULL);
		}
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_remove_node()
{
	cout << endl << "Testing Remove Node" << endl;
	
	graph map1;	
	
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};	
	
	for(int k = 0; k < 7; k++)
	{
		map1.insertNode(names[k]);
	}
	
	cout << "Checking removed nodes are gone and remaining nodes are accessible: ";
	for(int k = 0; k < 7; k++)
	{
		for(int j = k; j < 7; j++)
		{
			CPPUNIT_ASSERT(map1.find(names[j]) != NULL);
		}
		
		map1.removeNode(map1.find(names[k]));
		
		for(int j = 0; j < k; j++)
		{
			CPPUNIT_ASSERT(map1.find(names[j]) == NULL);
		}
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_find_node()
{
	cout << endl << "Testing Find Node" << endl;
	
	double mph[] = {85, 75, 65, 55, 45, 35};
	double miles[]	= {12.3, 19.4, 10.23, 1, 99, 203.2};
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};
	
	graph map1;
	
	cout << "Testing nodes and edges found after edge inserts: ";
	for(int k = 0; k < 6; k++)
	{
		map1.insertEdge(names[k], names[k+1], mph[k], miles[k]);
		for(int j = 0; j < k; j++)
		{
			//test to find nodes
			CPPUNIT_ASSERT(map1.find(names[j]) != NULL);
			CPPUNIT_ASSERT(map1.find("Not a place") == NULL);
		}
		CPPUNIT_ASSERT(map1.find(names[k+1]) != NULL);
	}
	cout << "PASSED" << endl;
	
	graph map2;	
	
	for(int k = 0; k < 7; k++)
	{
		map2.insertNode(names[k]);
	}
	
	cout << "Checking removed nodes are not found and remaining nodes are found: ";
	for(int k = 0; k < 7; k++)
	{
		for(int j = k; j < 7; j++)
		{
			CPPUNIT_ASSERT(map2.find(names[j]) != NULL);
		}
		
		map2.removeNode(map2.find(names[k]));
		
		for(int j = 0; j < k; j++)
		{
			CPPUNIT_ASSERT(map2.find(names[j]) == NULL);
		}
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_find_edge()
{
	cout << endl << "Testing Find Edge" << endl;
	
	double mph[] = {85, 75, 65, 55, 45, 35};
	double miles[]	= {12.3, 19.4, 10.23, 1, 99, 203.2};
	string names[] = {"Jerry", "Tom", "Hershey", "Doomtown", "Umbrellaville", "Union", "Rolla"};
	
	graph map1;
	
	cout << "Testing nodes and edges found after edge inserts: ";
	for(int k = 0; k < 6; k++)
	{
		map1.insertEdge(names[k], names[k+1], mph[k], miles[k]);
		for(int j = 0; j < k; j++)
		{
			//test to find edges
			CPPUNIT_ASSERT(map1.find(names[j], names[j+1], mph[j], miles[j]) != NULL);
			CPPUNIT_ASSERT(map1.find("Not", "A Place", 12, 19) == NULL);
		}
		CPPUNIT_ASSERT(map1.find(names[k+1]) != NULL);
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_edge_iterator()
{
	cout << endl << "Testing Edge Iterator" << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	graph map(fin);
	fin.close();
	fin.open("connections.txt", fstream::in);	
	
	//must use multiset to allow for duplicate values
	multiset<string> sourceA;
	multiset<string> targetA;
	multiset<double> mphA;
	multiset<double> milesA;
	
	while(fin.good())
	{
		//this loop ignores the irrelevent stuff
		while(fin.good() && (fin.peek() == ' ' || fin.peek() == '\t' || fin.peek() == '\n'))
		{
			fin.ignore();
		}
    
		if(fin.good())
		{
			string source, target;
			string tempEdges, tempMph, tempMiles;
			int sourceEdges;
			double mph, miles;
	
			//get the source
			while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t'	&& fin.peek() != '\n')
			{
				source.push_back(fin.get());
			}
	
			//skip past nonsense
			while(fin.good() && (fin.peek() == ' '	|| fin.peek() == '\t' || fin.peek() == '\n'))
			{
				fin.ignore();
			}
	
			//get the number of edges
			while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t'	&& fin.peek() != '\n')
			{
				tempEdges.push_back(fin.get());
			}
			sourceEdges = atoi(tempEdges.c_str());
	
			//get all of the destinations and their cost
			for(int k = 0; k < sourceEdges; k++)
			{
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' ' || fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the target
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t'	&& fin.peek() != '\n')
				{
					target.push_back(fin.get());
				}
		
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' '	|| fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the distance
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
				{
				tempMiles.push_back(fin.get());
				}
				miles = atof(tempMiles.c_str());
		
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' '	|| fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}
		
				//get the mph
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
				{
					tempMph.push_back(fin.get());
				}
				mph = atof(tempMph.c_str());
		
				sourceA.insert(source);
				targetA.insert(target);
				mphA.insert(mph);
				milesA.insert(miles);
				tempMph = tempMiles = target = "";
			}
		}
	}
	

	cout << "Checking that every edge's target, source, mph, and miles is found: ";
	
	for(edgeIterator k = map.beginEdge(); !k.ended(); k++)
	{
		CPPUNIT_ASSERT(sourceA.find((*k)->l->name) != sourceA.end() || sourceA.find((*k)->r->name) != sourceA.end());
		CPPUNIT_ASSERT(targetA.find((*k)->r->name) != targetA.end() || targetA.find((*k)->l->name) != targetA.end());
		CPPUNIT_ASSERT(mphA.find((*k)->mph) != mphA.end());		
		CPPUNIT_ASSERT(milesA.find((*k)->miles) != milesA.end());
	}
	cout << "PASSED" << endl;
}

void Test_graph::test_node_iterator()
{
	cout << endl << "Testing Node Iterator" << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);

	set<string>	towns;
	
	graph map(fin);
	fin.close();
	fin.open("connections.txt", fstream::in);	
	
	//you can probably ignore most of the stuff that goes on in this loop
	//it puts all node names in towns.  That's all.
	while(fin.good())
	{
		//this loop ignores the irrelevent stuff
		while(fin.good() 
			&& (fin.peek() == ' '
			|| fin.peek() == '\t'
			|| fin.peek() == '\n'))
		{
			fin.ignore();
		}
    
		if(fin.good())
		{
			string source, tempEdges;
			int sourceEdges;
	
			//get the source
			while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
			{
				source.push_back(fin.get());
			}
			towns.insert(source);
			source = "";	
	
			//skip past nonsense
			while(fin.good() && (fin.peek() == ' '	|| fin.peek() == '\t' || fin.peek() == '\n'))
			{
				fin.ignore();
			}
	
			//get the number of edges
			while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
			{
				tempEdges.push_back(fin.get());
			}
			sourceEdges = atoi(tempEdges.c_str());
			
			//get all of the destinations and their cost
			for(int k = 0; k < sourceEdges; k++)
			{
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' ' || fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}		
				//target
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
				{
					fin.ignore();
				}		
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' ' || fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}		
				//distance
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
				{
					fin.ignore();
				}		
				//skip past nonsense
				while(fin.good() && (fin.peek() == ' ' || fin.peek() == '\t' || fin.peek() == '\n'))
				{
					fin.ignore();
				}	
				//mph
				while(fin.good() && fin.peek() != ' ' && fin.peek() != '\t' && fin.peek() != '\n')
				{
					fin.ignore();
				}
			}
		}
	}
	
	cout << "Checking that every town is found in the iterator: ";
	for(set<node*>::iterator k = map.beginNode(); k != map.endNode(); k++)
	{
		CPPUNIT_ASSERT(towns.find((*k)->name) != towns.end());
		towns.erase((*k)->name);
	}
	cout << "PASSED" << endl;
	
	cout << "Checking that the iterator covered everything: ";
	CPPUNIT_ASSERT(towns.empty());
	cout << "PASSED" << endl;
}

void Test_graph::find_route()
{
	cout << endl << "Running Solver for supply chain management problem: " << endl
	     << "Note: Lowest cost path is based on shortest time, not shortest distance" << endl << endl;
	fstream fin;
	fin.open("connections.txt", fstream::in);
	
	
	graph missoura(fin);
	
	string cities[] = {"rockport", "stjoseph", "kansascity",
							 "joplin", "bethany",
							 "cameron", "sedalia", "springfield",
							 "branson", "lancaster", "macon", 
							 "columbia", "jeffersoncity", "rolla", 
							 "westplains", "alexandria", "hannibal", 
							 "stlouis", "sikeston"};
	
	for(int k = 0; k < 19; k++)
	{
		shortestPath("bentonville", cities[k], missoura).print();
		cout << endl;
	}
}

