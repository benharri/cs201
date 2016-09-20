//Ben Harris
//Header file for PG2

#ifndef _PG2_
#define _PG2_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main (int argc, char **argv);
string getSuitName(int card);
string getRankName(int card);
void swapTwo(int a, int b,int *d);
void shuffle(int *d);
bool inArray(int *d,int toinsert, int sz);
bool dupeinarray(int *d, int dupetocheck, int sz);
#endif
