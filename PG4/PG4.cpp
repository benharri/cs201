//Ben Harris
//This program manages a library of books by title, stored in a linked list

#include<iostream>
#include<string>
#include<cstdlib>
#include<cctype>
#include "PG4.h"
#include "List.h"
using namespace std;

int main(int argc, char **argv){
	string input = " ";
	List * list = new List();
	cout << "cLibrary Version 1.0 -- type help for a list of commands" << endl;
	while (converttolower(input).substr(0,4) != "exit"){

		cout << "Enter command: ";
		getline(cin, input);
		string lower = converttolower(input);
		if (lower.substr(0, 3) == "add") list->add(input.substr(5, input.length() - 6),lower.substr(5, input.length() -6));
		if (lower.substr(0, 6) == "remove") list->remove(lower.substr(8, input.length() - 9));
		if (lower == "print") list->print();
		if (list && lower == "clear") {delete list; List * list = new List();}
		if (lower.substr(0,4) == "help" || lower.substr(0,4) == "halp"){
			cout << endl << "These are the commands that this program accepts: " << endl << endl;
			cout << "add \"book title\" \t--adds a new entry with book title as the name" << endl;
			cout << "remove \"search term\" \t--deletes all books that contain search term" << endl;
			cout << "print \t\t\t--prints out the entire library in alphabetical order" << endl;
			cout << "clear \t\t\t--clears the entire library" << endl;
			cout << "exit \t\t\t--exits the program (also clears the library)" << endl << endl;
		}
	}
	delete list;
	return 0;
}

string converttolower(string s){
	for (int i = 0; i < (int) s.length(); i++) s[i] = tolower(s[i]); return s;
}
