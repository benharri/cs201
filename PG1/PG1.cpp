//Ben Harris
//This program converts decimal to dozenal.

#include <iostream> //import
#include <string>
#include <cstdlib>
#include <sstream>
#include "PG1.h"
using namespace std;

//main method runs at execution time
int main (int argc, char **argv) { //signature
	cout << "Enter a number in decimal:  ";
	string input;
	getline (cin,input);
	cout << input << " in dozenal is " << dozenal (input) << endl;
	system ("pause");
	return 0;
}
//this method divides by 12 and returns the quotient, to be stored
string div12 (string dividend, int &remainder) {
	
	int save = 0;
	string quotient = "";
	
	for (int i = 0 ; i < dividend.length() ; i++){

		if(save != 0){

			save = (save * 10) + (dividend[i]-'0');
			int j = save/12; //divide by 12
			char c = j+'0'; //convert to char
			quotient = quotient+c;
			save = save%12;
			
		}
		else {
			save = dividend[i]-'0';
			quotient += '0';
		}			
	}
	remainder = save;
	return quotient;
}
//this method calls the div12 method and stores each remainders as the next digit
string dozenal (string input) {

	string dozenalNumber = "";
	int remainder = 0;

	while( atoi(div12(input,remainder).c_str()) != 0 ) {

		input = div12(input,remainder);

		char remainderChar;

		if(remainder == 10){
			remainderChar = 'A';
		}else if (remainder == 11){
			remainderChar = 'B';
		}else remainderChar = remainder+'0';

		dozenalNumber = remainderChar+dozenalNumber;

	}


		input = div12(input,remainder);

		char remainderChar = remainder;

		if(remainder == 10){
			remainderChar = 'A';
		}else if (remainder == 11){
			remainderChar = 'B';
		}else remainderChar = remainder+'0';

		dozenalNumber = remainderChar+dozenalNumber;

	return dozenalNumber;
}
