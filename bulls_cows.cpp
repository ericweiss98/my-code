#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <random>
#include <sstream>
#include <chrono>

using namespace std;

vector<int> intToVector(int value, int correctSize) {
    
    vector<int> finalVect;
    int tempVal = 0;
    int vectVal = 0;
    int powerVal = 0;
    int i = 0;
    
    //create the vector
    for (i = 1; i <= correctSize; ++i) {
        powerVal = pow(10,i);
        vectVal = value % powerVal;
        value -= vectVal;
        vectVal = vectVal / pow(10,i-1);
        finalVect.insert(finalVect.begin(), vectVal);
    }
    return finalVect;
}

int main() {
	
	//variables
	int correctSize = 0;
	int origSize = 0;
	int correctint = 0;
	int guessint = 0;
	vector<int> guessVect;
	vector<int> correctVect;
	int randNum = 0;
	int cow = 0;
	int bull = 0;
	int i = 0;
	int j = 0;
	int k = 0;
    bool multDigit = false;

	//get size
	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> correctSize;
	
	//set original size to check if cheat code used
	origSize = correctSize;
	
	//check if the cheat is inputted
	while (correctSize == 0) {
		//cheat is inputted, select desired code
	    cout << "Enter code: ";
		cin >> correctint;
		
		//get desired characters
		cout << "Enter number of digits in code: ";
		cin >> correctSize;
	}
	
	if (origSize == 0) {
	    
	    correctVect = intToVector(correctint, correctSize);
	    	
    	//output number to guess
    	cout << "Number to guess: ";
	
	    for (i = 0; i < correctSize - 1; ++i) {
	        cout << correctVect.at(i) << "-";
	    }
	    cout << correctVect.at(correctSize - 1) << endl;
	}

	//create values for the correct string if not already chosen
	if (origSize != 0) {
	    
    	for (i = 0; i < correctSize; ++i) {
    	    srand(std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
            
            //declare vector size
            correctVect.resize(correctSize);
            
    	   	randNum = (rand() % 9) + 1;
    		correctVect.at(i) = (randNum);
    		//make sure k always resets to 0 before the nested for loop
    		k = 0;
    		//make any repeat values change if found
    		if (i > 0) {
        	    for (j = 0; j < 100; ++j) {
        			//reset k if it is the same length so it doesn't start looking too far
        	        if (k == i) {
    	            k -= i;
        	        }
        	        if (correctVect.at(i) == correctVect.at(k)) {
        	            randNum = (rand() % 9) + 1;
        		        correctVect.at(i) = (randNum);
        	        }
        	        ++k;
        	    }
    		}
    	}
        //output number to guess
	    cout << "Number to guess: ";
	    for (i = 0; i < correctSize - 1; ++i) {
	        cout << correctVect.at(i) << "-";
	    }
	    cout << correctVect.at(correctSize - 1) << endl;
	}
	
	//start guessing game
		
    //get the guesses
	while (guessVect != correctVect) {
    	cout << "Enter Guess: ";
        cin >> guessint;
        
        guessVect = intToVector(guessint, correctSize);
        
        //reset multDigit each time
        multDigit = false;
        
        //initialize cows and bulls to reset
        cow = 0;
        bull = 0;
    	        
        //check for repeated numbers
        for (i = 0; i < correctSize; ++i) {
            for (j = 0; j < i; ++j) {
                if (guessVect.at(i) == guessVect.at(j)) {
                    multDigit = true;
                }
            }
        }
        //check size
        if (guessint >= pow(10,correctSize)) {
            cout << "You can only enter " << correctSize << " digits."<< endl;
        }
        
        else if (multDigit == true) {
            cout << "Each number must be different." << endl;
        }
        else {
	        //find cows and bulls
	        for (i = 0; i < correctSize; ++i) {
	            for (j = 0; j < correctSize; ++j) {
	                if (guessVect.at(i) == correctVect.at(j)) {   
	                    if (i == j) {
	                        bull += 1;
	                    }
	                    else {
	                        cow += 1;
	                    }
	                }
	            }
	        }
	        if (bull < correctSize) {
	            //output bulls and cows if not perfect
	            cout << bull << " bulls" << endl;
	            cout << cow << " cows" << endl;
	        }
	        //winner
	        if (bull == correctSize) {
	            cout << correctSize << " bulls... ";
	            for (j = 0; j < correctSize - 1; ++j) {
	                cout << guessVect.at(j) << "-" ;
	            }
	            cout << guessVect.at(correctSize - 1) << " is correct!" << endl;
	        }
        }
    }
	return 0;
}