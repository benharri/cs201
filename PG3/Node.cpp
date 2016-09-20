//Ben Harris
//Node.cpp contains the code for each node

#include <iostream>
#include <string>
#include <cstdlib>
#include "Node.h"
using namespace std;

Node::Node(string s, Node *n){
	cnt = 1;
	value = s;
	next = n;
}
Node::~Node(){
	delete next;
	cnt = 0;
	//farewell
}
string Node::getvalue(){
	return value;
}
int Node::getcount(){
	return cnt;
}
Node * Node::getnext(){
	return next;
}
void Node::add(string s){
	if (value == s)cnt++;
	else if (next == NULL) next = new Node(s, NULL);
	else next->add(s);
}
