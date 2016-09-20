//Ben Harris
//List.cpp defines the methods for a List

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "PG4.h"
using namespace std;

List::List(){
	head = NULL;
}
List::~List(){
	delete head;
}
void List::add(string s, string l){
	if (head && head->getvalue() == l) {
    cout << "already in library. aborted." << endl;
    return;
  }
	if (!head || converttolower(head->getvalue()) > l) head = new Node(s, head);
	else head = head->add(s, l);
}

void List::print(){

	cout << endl << "Library List" << endl << endl;
	if (head) head->print();
	cout << endl;
}

void List::remove(string s){
	if (head) head = head->remove(s, NULL, this);
}

void List::sethead(Node * n){ head = n; }

