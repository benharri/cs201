//Ben Harris
//Header file for prototypes of List methods

#ifndef _LIST_
#define _LIST_

#include <iostream>
#include <string>
#include <cstdlib>
#include "Node.h"
using namespace std;

class Node;
class List{
private: // Each list contains only the pointer to its head Node.
	Node *head;
public:
	List(); // List Constructor
	~List(); // List Destructor
	void add(string s,string l); // Adds a Node to the tail of the list, incrementing the counter if a duplicate string is entered.
	void print(); // Loops through the array twice: once to find the highest count, then a second time to print each Node that has that count value.
	void remove(string s); // Calls remove on the nodes that match string s
	void sethead(Node* n); // Head mutator
};

#endif
