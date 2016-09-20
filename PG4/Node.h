//Ben Harris
//Node.h is a header file for Node methods

#ifndef _NODE_
#define _NODE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
using namespace std;

class List;
class Node{
private: // Each Node contains a value, count, and a pointer to the next Node in the list.
	string value;
	int cnt;
	Node *next;
public:
	Node(string s, Node *n); // Node Constructor
	~Node(); // Node Destructor
	string getvalue(); // Value accessor
	int getcount(); // Count accessor
	Node * getnext(); // Next pointer accessor
	void setnext(Node* n); // Next pointer mutator
	Node * add(string s,string l); // Adds a new Node to a list, incrementing the count for a Node if the same string is entered more than once.
	void print(); // Tells each node to print itself and its next
	Node* remove(string s, Node *prev, List *l); // Remove the nodes with matching string s and returns the new head
};

#endif
