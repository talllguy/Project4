/*******************************************************************************
Project 4

Algorithm:	Read infile of employees into variables. Process certain
			values by sending them to functions. Return values back to
			values. output them to file
*/

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

void posType (char); // function that will convert the posCode to a position name
void ageGroup (int); // function that will convert the age to a group using a switch
int Code (int);      // function that will convert code to pay code

  
int main() 
{ 
    int fileLines(0); // number of lines in file
	char init1('X'),init2('X'),init3('X'); // the three initials
	char posCode('X'); // position of worker
	int age(0); // age of worker
	float dollarsPerHour(0.); // salary of employee (per hour)
	int payCode(0); //pay code

	ifstream inFile;     // define ifstream to inFile command
	
	fileLines = count(istreambuf_iterator<char>(inFile),istreambuf_iterator<char>(), '\n');

	inFile.open("Employees.txt");
	inFile >> init1 >> init2 >> init3 >> posCode >> age >> dollarsPerHour >> payCode; // read input from file

	//test to output on screen first
	cout << "Name" << setw(12) << "Position" << setw(12) << "Age" << setw(12) << "Annual" << setw(12) << "Pay Code\n";
	cout << init1 << init2 << init3 << setw(12) << posCode << setw(12) << age << setw(12) << dollarsPerHour << setw(12) << payCode << endl;
	
	
	//cout << "There should be " << fileLines << " lines.\n"; // test of the lines counter

	//for (int i = 0; i < fileLines; i++)
	//{
	//	cout << init1 << init2 << init3 << setw(12) << posCode << setw(12) << age << setw(12) << dollarsPerHour << setw(12) << payCode << endl;
	//}
	return 0;
}

