// Ben Harris
// PG5 Main 
// This program recreates PG4 using a template of a Linked List. 
// The ArrayLL template interfaces with the linkedlist as if it were an array.

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG5.h"
#include "ArrayLL.h"
using namespace std;

int main(int argc, char **argv){ // PG5 main

	string input = "";
	cout << "cLibrary Version 2.0 -- type help for a list of commands" << endl;
	ArrayLL<string> list;

	while (converttolower(input).substr(0, 4) != "exit"){ // quit program when exit command is found

		cout << "Enter command: ";
		getline(cin, input);
		string lower = converttolower(input);

		if (lower.substr(0, 3) == "add"){ // insert a new node in alphabetical order, not allowing duplicates (case-insensitive)

			bool found = false;
			string linputstr = converttolower(input.substr(5, input.length() - 6));

			for (int i = 0; i < list.length(); i++) // Make sure no duplicates are entered
				if (converttolower(list[i]) == linputstr)
					found = true;

			int j = 0;
			for (j = 0; j < list.length(); j++) // Find where in the list that it needs to be inserted
				if (converttolower(list[j]) > linputstr)
					break;
			
			if (!found) list.insert(j, input.substr(5, input.length() - 6));

		}
		
		if (lower.substr(0, 5) == "print"){ // prints the entire list, which should be in alphabetical order
			cout << endl;
			for (int i = 0; i < list.length(); i++)
				cout << list[i] << endl;
			cout << endl << "There are " << list.length() << " titles in the library." << endl;
		}

		if (lower.substr(0, 6) == "remove"){ // removes all the items in the library that contain search string 
			string lv = lower.substr(8, input.length() - 9);
			for (int i = 0; i < list.length(); i++){
				string ll = converttolower(list[i]);
				if (ll.find(lv) >= 0 && ll.find(lv) < ll.length()){
					cout << "\"" << list.remove(i) << "\"" << " was removed from the library." << endl;
					i--;
				}
			}
		}
		
		if (lower.substr(0, 4) == "help" || lower.substr(0, 4) == "halp"){ // prints info for each function
			cout << endl << "These are the commands that this program accepts: " << endl << endl;
			cout << "add \"book title\" \t--adds a new entry with book title as the name" << endl;
			cout << "remove \"search term\" \t--deletes all books that contain search term" << endl;
			cout << "print \t\t\t--prints out the entire library in alphabetical order" << endl;
			cout << "exit \t\t\t--exits the program (also clears the library)" << endl << endl;
		}
	}
	return 0;
}

string converttolower(string s){for (unsigned int i = 0; i < s.length(); i++) s[i] = tolower(s[i]); return s;}
