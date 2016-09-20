//Ben Harris
//This program builds a list based on user input and prints the
//most commonly entered words, printing all in the case of a tie.

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG3.h"
#include "List.h"
using namespace std;

int main(int argc, char **argv){
	string input =" ";
	List * list = new List();
	while (input!=""){
		cout << "Input<<";
		getline(cin, input);
		if(input!="")list->add(input);
	}
	list->print();
	delete list;
	return 0;
}
