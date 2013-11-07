/*******************************************************************************
COSC 501   
Project 4  
Elliott Plack   
31 OCT 2013           Due date: 10 NOV 2013

Problem:	Bob's bank wants to process employee data stored in one file into a
			more readable format.
Algorithm:	Read in a file of employees into variables, process with functions,
			and output to another file. Four functions:
			posType: convert posCode (e.g. 'A') into a position name, using a
				switch case statement.
			ageGroup: function that uses several if/else statements to output
				a specific output group depending on conditions
			hour2annual: A super simple function that converts the hourly
				salary to yearly.
			code: function that uses division and % to add the values up of an
				integer's digits. returns value to main
			main function takes in all data from a file and then outputs the
				data to another file in a good looking way.
******************************************************************************/

// headers to include
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void posType (char); // function that will convert the posCode to a position name
void ageGroup (int); // function that will convert the age to a group using a switch
void hour2annual (float); // function to convert hourly to annual wage
int Code (int);      // function that will convert code to pay code
// global so they work in void functions
ifstream inFile;     // define ifstream to inFile command
ofstream outFile;    // define outfile2
  
int main() 
{ 
    // define variables that will be used in 
	int fileLines(0); // number of lines in file
	char init1('X'),init2('X'),init3('X'); // the three initials
	char posCode('X'); // position of worker
	int age(0); // age of worker
	float dollarsPerHour(0.); // salary of employee (per hour)
	int payCode(0); //pay code
	int payCodeConv(0); // pay code converted

	inFile.open("Employees.txt"); // open input file
	outFile.open("EmployeeOutput.txt"); // open output spool 

	// write header out of loop
	outFile << "Name" << setw(15) << "Position" << setw(12) << "Age" << setw(12) << "Annual" << setw(12) << "Pay Code\n";

	while (inFile.good()) // takes care of bad files and eof
	{
		inFile >> init1 >> init2 >> init3 >> posCode >> age >> dollarsPerHour >> payCode; // read input from file
		
		//output (formatting done with setw experimentally)
		outFile << init1 << init2 << init3 << setw(16);
		posType(posCode);
		outFile << setw(12);
		ageGroup(age);
		outFile << setw(12);
		hour2annual(dollarsPerHour);
		payCodeConv = Code(payCode);
		outFile << setw(11)<< payCodeConv << endl;
	}
	inFile.close();
	outFile.close();
	return 0;
}

void posType (char posCode)
{
	switch (posCode) // simple switch to convert char
	{
	case 'A':
		outFile << "Management";
		break;
	case 'B':
		outFile <<	"Supervisor";
		break;
	case 'C':
		outFile << "Clerical";
		break;
	default:
		outFile << "Invalid";
		break;
	}
}
void ageGroup (int age)
{
	if (age < 25) // for age conversions, better to use if / else
		outFile << "group 1";
	else if ((age >= 25) && (age <= 40))
		outFile << "group 2";
	else if ((age >= 41) && (age <= 65))
		outFile << "group 3";
	else if (age > 65)
		outFile << "group 4";
	else
		outFile << "invalid";
}
void hour2annual (float dollarsPerHour) // not required in design but this simplifies things
{
	float converted(0);
	converted = (dollarsPerHour * 2080);
	
	// set precision of output to 2
    outFile.setf(ios::fixed);  
    outFile.setf(ios::showpoint);  
    outFile.precision(2);
	outFile << converted;
}
int Code (int posCode)
{
	int digit1(0), digit2(0), digit3(0), digit4(0), sum(0);
	
	//using the fact that int division drops the decimal, uses division to find digit values
	digit1 = (posCode / 1000);
	posCode %= 1000; // drops a digit
	digit2 = (posCode / 100);
	posCode %= 100;
	digit3 = (posCode / 10);
	posCode %= 10;
	digit4 = (posCode / 1); // not necessary. included for clarity. alt would be just assign posCode to digit4
	sum = (digit1 + digit2 + digit3 + digit4);
	return sum;
}