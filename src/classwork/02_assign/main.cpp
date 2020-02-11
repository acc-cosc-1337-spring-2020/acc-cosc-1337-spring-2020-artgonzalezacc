//Write the include statement for decision.h here
#include "decision.h"
#include <iostream>

//Write include for capturing input from keyboard and displaying output to screen


//Write namespace using statements for cout and cin
using std::cout; using std::cin;

int main() 
{
	//create a double variable named hours
	//create a double variable named hourly_rate
	double hours, hourly_rate;

	//Prompt user for keyboard input for hours and hourly_rate
	//save the input to variables hours and hourly_rate
	cout << "Enter hours: ";
	cin >> hours;
	cout << "Enter hourly rate: ";
	cin >> hourly_rate;

	//Create a double variable named gross_salary
	//Call the gross_pay function and save its return value to the gross_salary variable
	double gross_salary;
	gross_salary = gross_pay(hours, hourly_rate);

	//Display the gross_salary variable as follows:
	//Example ---->>>     Gross pay: 150.00   
	cout << "Gross pay: " << gross_salary;

	return 0;
}

