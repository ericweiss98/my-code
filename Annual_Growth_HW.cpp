#include <iostream>
#include <string>
using namespace std;

int main()
{
	/* variables */
	string firstName;
	string lastName;
	double birthYear;
	double currentYear = 2018;
	double Age;
	double heightFt;
	double heightInch;
	double FtToCm;
	double InchToCm;
	double heightCm;
	double growthRate;
	
	
	/* input the information */
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;
	cout << "Enter your birth year: ";
	cin >> birthYear;
	cout << "Enter your height in feet (Rounded down): ";
	cin >> heightFt;
	cout << "Enter your remaining inches: ";
	cin >> heightInch;
	cout << endl;
	
	/* calculations */
	Age = currentYear - birthYear;
	FtToCm = heightFt * 2.54  * 12;
	InchToCm = heightInch * 2.54;
	heightCm = FtToCm + InchToCm;
	growthRate = (heightCm - 51) / Age;
	
	/* outputs */
	cout << "Hello " << firstName << " " << lastName << "." << endl;
	cout << "You are " << Age << " years old in " << currentYear << "." << endl;
	cout << "Your height is " << heightCm << " cm." << endl;
	cout << "You grew an average of " << growthRate << " cm per year (assuming you were 51 cm at birth)." << endl;
	
    return 0;
}
