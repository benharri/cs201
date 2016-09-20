// Ben Harris
// Main: Program6
// This program reads a file, uses the first four bytes as an integer record size and sorts the rest of the file in recordsz chunks.

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include "PG6.h"
using namespace std;

int main(int argc, char **argv){ 
	string fn = "";
	streampos fsz;
	cout << "Enter the name of the file that you want to sort." << endl << "File Name: ";
	getline(cin, fn); // Get file name from user
	fstream f (fn, ios::in | ios::out | ios::binary); // Open file from input location for read and write and as binary
	if (f.is_open()){

		char * recordsz = new char[4];
		f.read(recordsz, (streamsize) 4); // Read first four bytes
		int rsz = atoi(recordsz); // Store first four bytes as int record size
		f.seekg(0, f.end);
		fsz = f.tellg(); // Get length of file
		int recordcnt = ((int)fsz-4) / rsz; // Get # of records 
		f.seekg(0, f.beg);
		
		// Begin shell sort
		int d = recordcnt;
		while (d > 1){
			d = (d == 2) ? 1 : d % 2 == 1 ? (d + 1) / 2 : d % 4 == 0 ? d / 2 + 1 : d / 2 + 2;
			for (int i = d; i < recordcnt; i++) // Use readstring and writestring methods to get and put strings in the file
				for (int j = i - d; j >= 0 && readstring(f,j,rsz) > readstring(f,j + d,rsz); j -= d){
				string t = readstring(f,j,rsz);
				writestring(f, j, rsz, readstring(f,j + d,rsz));
				writestring(f, j+d, rsz, t);
				}
		}
		cout << "Sort successful." << endl;
		f.close();
	}
	else cout << "Error: file could not be opened or does not exist." << endl;
	system("pause");
}

string readstring(fstream &f, int recordpos, int len){ // This method seeks to the position of recordpos * len, reads len bytes and returns that string
	char* t = new char[len];
	f.seekg(recordpos*len + 4, ios::beg);
	f.read(t, len);
	return (string)t;
}

void writestring(fstream &f, int recordpos, int len, string s){ // Writes string s to f at position recordpos*len
	f.seekp(recordpos*len + 4, ios::beg);
	char * t = new char[s.length()];
	for (unsigned int i = 0; i < s.length(); i++) t[i] = s[i];
	f.write(t, len);
}
