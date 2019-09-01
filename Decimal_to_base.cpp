#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;
int main()
{
	//variables
	int decVal;
	int baseVal;
	int i = 0;
	int j = 0;
	int valLength;
	int tempVal;
	int singleValNum;
	int basePower;
	
	//inputs
	cout << "Enter a decimal value :";
	cin >> decVal;
	cout << " Enter a base (2-16) :";
	cin >> baseVal;
	
	//check for appropriate base val
	while ((baseVal < 2) || (baseVal > 16)) {
		cout << " Enter a base (2-16) :";
		cin >> baseVal;
	}
	 if (decVal == 0) {		//work in progress
	    valLength = 0;
	    string finalVal;
	    finalVal = '0';
			
		//outputs
		cout << " " << endl;
		cout << "Base-10 value : " << decVal << endl;
		cout << "Base-" << baseVal << " value : " << finalVal << endl;
		cout << "Digits required : " << valLength << endl;

	} 
	else {
    	
    	//find length of number
    	while (pow(baseVal,i) <= decVal) {
    		valLength = i + 1;
    		++i;
    	}
    	
    	//assign a temp val and set string
    	tempVal = decVal;
    	string finalVal(valLength, ' ');
        
    	//find val of base version
    	for (i = (valLength); i > 0; --i) {
    		//resets the letter every loop
    		char hex ='A';
    		//sets the power currently on for the digit
    	    basePower =pow(baseVal,i-1);
    	    //number in digit
    		singleValNum = tempVal/basePower;
    		//remaining
    		tempVal = tempVal % basePower;
    		if (singleValNum < 10) {
    		    //makes an int to char
    			finalVal.at(j) = (singleValNum + '0');
    		}
    		else {
    			singleValNum -= 10;
	    		//adjusts letter as necessary
	    		hex = hex + singleValNum;
	    		finalVal.at(j) = hex;
	    	}
	    	//increments the location the digit is put in
		    ++j;
	    }
	
		//outputs
		cout << " " << endl;
		cout << "Base-10 value : " << decVal << endl;
		cout << "Base-" << baseVal << " value : " << finalVal << endl;
		cout << "Digits required : " << valLength << endl;
	}
    return 0;
}