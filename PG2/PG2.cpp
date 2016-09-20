//Ben Harris
//This program shuffles a deck of cards, deals ten hands of five,
//then checks for poker hands excluding straight, flush, and straight flush

#include <iostream>
#include <string>
#include <cstdlib>
#include "time.h"
#include "PG2.h"
using namespace std;

int main (int argc, char **argv){//main method
	//initialize deck and randomize it
	srand((unsigned)time(0));
	int *deck = new int[52];
	for(int i=0;i<52;i++){
		deck[i]=i;
	}
	shuffle(deck);

	//start to deal the hands
	for(int j = 0; j<10;j++){//deals ten hands

		int rankcount[13] = {0};
		for(int i = j*5;i<j*5+5;i++){//print, then check each hand for duplicates
			rankcount[deck[i]/4]++;
			cout << getRankName(deck[i]) << " of " << getSuitName(deck[i]) << endl;

		}
		cout<<endl;
		if (inArray(rankcount, 2, 13) && inArray(rankcount, 3, 13))cout << "FULL HOUSE";
		else if (dupeinarray(rankcount, 2, 13))cout << "TWO PAIR";
		else if (inArray(rankcount, 4, 13))cout << "FOUR OF A KIND";
		else if (inArray(rankcount, 3, 13))cout << "THREE OF A KIND";
		else if(inArray(rankcount,2,13))cout<<"ONE PAIR";
		else cout<<"NOTHING";
		cout<<endl;
		cout<<endl;

	}
	//remove systempause before turning in
	//system("pause");
	delete[] deck;
	return 0;
}

string getSuitName(int card){//returns the suit of the input card
	string suits[4] = {"Hearts","Clubs","Diamonds","Spades"};
	return suits[card%4];
}
string getRankName(int card){//returns the rank of the input card
	string ranks[13] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
	return ranks[card/4];
}
void swapTwo(int a, int b,int *d){//swaps two ints a and b within an array d
	d[b] = d[a]+d[b];
	d[a] = d[b]-d[a];
	d[b] = d[b]-d[a];
}
void shuffle(int *d){//swaps each element with a random index at or before the current index, shuffling the deck
	for(int i = 1; i<52;i++){
		int r = rand()%(i+1);
		swapTwo(i,r,d);
	}
}
bool inArray(int *d,int toinsert, int sz){//returns true if toinsert is found in array d; checks only up to size
	for(int i = 0; i<sz;i++){
		if(toinsert == d[i])return true;
	}return false;
}
bool dupeinarray(int *d, int dupetocheck, int sz){//checks for duplicate dupetocheck in array d
	int cnt = 0;
	for (int i = 0; i < sz; i++){
		if (d[i] == dupetocheck)cnt++;
	}
	if (cnt > 1)return true;
	else return false;
}
