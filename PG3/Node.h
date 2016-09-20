//Ben Harris
//Node.h is a header file for Node methods

#ifndef _NODE_
#define _NODE_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Node{
private: // Each Node contains a vale, count, and a pointer to the next Node in the list.
	string value;
	int cnt;
	Node *next;
public:
	Node(string s, Node *n); // Node Constructor
	~Node(); // Node Destructor
	string getvalue(); // Value accessor
	int getcount(); // Count accessor
	Node * getnext(); // Next pointer accessor
	void add(string s); // Adds a new Node to a list, incrementing the count for a Node if the same string is entered more than once.
};

#endif
