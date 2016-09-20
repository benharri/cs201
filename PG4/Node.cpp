//Ben Harris
//Node.cpp contains the code for each node

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "Node.h"
#include "List.h"
#include "PG4.h"
using namespace std;

Node::Node(string s, Node *n){
	value = s;
	next = n;
}
Node::~Node(){delete next;}
string Node::getvalue(){return value;}
int Node::getcount(){return cnt;}
Node * Node::getnext(){return next;}
void Node::setnext(Node *n){ next = n; }

Node * Node::add(string s, string l){

	string lvalue = converttolower(value);

	if (lvalue == l) return this;
	if (l < lvalue) return new Node(s, this);

	if (!next){ next = new Node(s, NULL); return this; }

	next = next->add(s,l);
	return this;
}

void Node::print(){
	cout << value << endl;
	if (next) next->print();
}

Node* Node::remove(string s, Node *prev, List *l){
	string lvalue = converttolower(value);
	if (next) next = next->remove(s, this, l);
	if (lvalue.find(s) < value.length() && lvalue.find(s) >= 0){
		Node *t = next;
		next = NULL;
		delete this;
		return t;
	}
	return this;
}

