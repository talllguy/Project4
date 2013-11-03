/*******************************************************************************
Project 4

Algorithm:	Read infile of employees into variables. Process certain
			values by sending them to functions. Return values back to
			values. output them to file
*/

#include <fstream>
#include <iostream>
using namespace std;

void posType (char); // function that will convert the posCode to a position name
void ageGroup (int); // function that will convert the age to a group using a switch
int Code (int);      // function that will 

  
int main() 
{ 
    char init1('X'),init2('X'),init3('X'); // the three initials
	char posCode('X'); // position of worker
	int age(0); // age of worker
	float dollarsPerHour(0.); // salary of employee (per hour)
	int payCode(0); //pay code

	ifstream inFile;     // define ifstream to inFile command
	inFile.open("employees.txt");

	inFile >> init1 >> init2 >> init3 >> classCode >> age >> dollarsPerHour >> payCode;

}

