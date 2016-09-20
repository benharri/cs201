//Ben Harris
//List.cpp defines the methods for a List

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
#include "Node.h"
using namespace std;

List::List(){
	head = NULL;
}
List::~List(){
	delete head;
}
void List::add(string s){
	if (head == NULL)head = new Node(s, NULL);
	else head->add(s);
}
void List::print(){
	int maxcnt = 0;
	Node* n = head;
	while (n != NULL){
		if (n->getcount() > maxcnt) maxcnt = n->getcount();
		n = n->getnext();
	}
	cout << endl << "<<Commonest Words>>"<<endl<<endl;
	n = head;
	while (n != NULL){
		if (n->getcount() == maxcnt) cout << n->getvalue() << endl;
		n = n->getnext();
	}cout << endl;
}
