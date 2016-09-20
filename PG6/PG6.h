// Ben Harris
// Header for program 6
// This program reads a file, uses the first four bytes as an integer record size and sorts the rest of the file in recordsz chunks.

#ifndef _PG6_
#define _PG6_

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char **argv);
string readstring(fstream &f, int recordpos, int len);
void writestring(fstream &f, int recordpos, int len, string s);

#endif
