//Ben Harris
//Template for an linked list that can be used as a array.

#ifndef _ARRAYLL_
#define _ARRAYLL_

#include <iostream>
#include <string>
#include <cstdlib>
#include "ArrayLLN.h"
using namespace std;

template <class T> class ArrayLL{
private:
	ArrayLLN<T> * head;
public:
	ArrayLL(){ head = nullptr; }
	~ArrayLL(){ delete head; }
	void sethead(ArrayLLN<T>* t){ head = t; }

	int length(){ // returns length of the list
		int cnt = 0;
		for (ArrayLLN<T>*P = head; P != nullptr; cnt++, P = P->getnext());
		return cnt;
	}
	T remove(int pos){ // removes the node at pos
		ArrayLLN<T> *P = head, *Q = nullptr;
		for (int cnt = 0; cnt < pos; cnt++, Q = P, P = P->getnext());
		T tempcontents = P->getcontents();
		P->removeself(P, Q, this);
		return tempcontents;
	}
	T& operator[] (const int pos){ // overloads [], which returns a reference to the node at pos
		ArrayLLN<T>* P = head;
		for (int cnt = 0; cnt < pos; cnt++, P = P->getnext());
		return P->getcontents();
	}
	void insert(int pos, T stuff){ // inserts a node at pos with stuff contents
		if (pos == 0) head = new ArrayLLN<T>(stuff, head); // insert at head, with head as next pointer
		else if (pos > 0 && pos < length()){ // if inserting not at the head or tail
			ArrayLLN<T> *P = head, *Q = nullptr;
			for (int i = 0; i < pos; i++, Q = P, P = P->getnext());
			if (Q) Q->setnext(new ArrayLLN<T>(stuff, P));
			else P->setnext(new ArrayLLN<T>(stuff, P->getnext()));
		}
		else if (pos == length()) // if inserting at the tail.
			if (head == NULL) head = new ArrayLLN<T>(stuff, NULL);
			else head->addback(stuff);
		else return;
	}

};

#endif 
