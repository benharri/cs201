//Ben Harris
//List Node Template

#ifndef _ARRAYLLN_
#define _ARRAYLLN_

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG5.h"
#include "ArrayLL.h"
using namespace std;

template <class T> class ArrayLL;

template <class T> class ArrayLLN{
private:
	T contents;
	ArrayLLN<T> *next;
public:
	
	ArrayLLN(T t, ArrayLLN<T>* n){ // Constructor
		contents = t;
		next = n;
	}
	~ArrayLLN(){delete next;} // Destructor
	void setcontents(T t){contents = t;} // contents mutator
	T& getcontents(){return contents;} // contents accessor
	ArrayLLN<T> * getnext(){return next;} // next ptr accessor
	void setnext(ArrayLLN<T>* n){next = n;} // next ptr mutator

	void removeself(ArrayLLN<T>* curr, ArrayLLN<T>* prev, ArrayLL<T>* l){ // deletes curr using prev, sets l's head if !prev
		ArrayLLN<T>*temp = curr->getnext();
		if (prev) prev->setnext(temp);
		else l->sethead(temp);
		curr->setnext(nullptr);
		delete curr;
	}

	void addback(T stuff){ // adds new node at the end of the list.
		if (!next) next = new ArrayLLN<T>(stuff, nullptr);
		else next->addback(stuff);
	}

};

#endif
