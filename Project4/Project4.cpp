/*******************************************************************************
Project 4

Algorithm:	Read infile of employees into variables. Process certain
			values by sending them to functions. Return values back to
			values. output them to file
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void posType (char); // function that will convert the posCode to a position name
void ageGroup (int); // function that will convert the age to a group using a switch
void hour2annual (float); // function to convert hourly to annual wage
int Code (int);      // function that will convert code to pay code

  
int main() 
{ 
    int fileLines(0); // number of lines in file
	char init1('X'),init2('X'),init3('X'); // the three initials
	char posCode('X'); // position of worker
	int age(0); // age of worker
	float dollarsPerHour(0.); // salary of employee (per hour)
	int payCode(0); //pay code
	int payCodeConv(0); // pay code converted
	ifstream inFile;     // define ifstream to inFile command
	inFile.open("Employees.txt"); // open 
	
	cout << "Name" << setw(15) << "Position" << setw(12) << "Age" << setw(12) << "Annual" << setw(12) << "Pay Code\n";

	while (inFile.good())
	{
		inFile >> init1 >> init2 >> init3 >> posCode >> age >> dollarsPerHour >> payCode; // read input from file
		
		cout << init1 << init2 << init3 << setw(16);
		posType(posCode);
		cout << setw(12);
		ageGroup(age);
		cout << setw(12);
		hour2annual(dollarsPerHour);
		payCodeConv = Code(payCode);
		cout << setw(11)<< payCodeConv << endl;
	}

	return 0;
}

void posType (char posCode)
{
	switch (posCode)
	{
	case 'A':
		cout << "Management";
		break;
	case 'B':
		cout <<	"Supervisor";
		break;
	case 'C':
		cout << "Clerical";
		break;
	default:
		cout << "Invalid";
		break;
	}
}
void ageGroup (int age)
{
	if (age < 25)
		cout << "group 1";
	else if ((age >= 25) && (age <= 40))
		cout << "group 2";
	else if ((age >= 41) && (age <= 65))
		cout << "group 3";
	else if (age > 65)
		cout << "group 4";
	else
		cout << "invalid";
}
void hour2annual (float dollarsPerHour)
{
	float converted(0);
	converted = (dollarsPerHour * 2080);
	
	// set precision of output to 2
    cout.setf(ios::fixed);  
    cout.setf(ios::showpoint);  
    cout.precision(2);
	cout << converted;
}
int Code (int posCode)
{
	int digit1(0), digit2(0), digit3(0), digit4(0), sum(0);
	
	digit1 = (posCode / 1000);
	posCode %= 1000;
	digit2 = (posCode / 100);
	posCode %= 100;
	digit3 = (posCode / 10);
	posCode %= 10;
	digit4 = (posCode / 1); // not necessary. included for clarity. alt would be just assign posCode to digit4
	sum = (digit1 + digit2 + digit3 + digit4);
	return sum;
}