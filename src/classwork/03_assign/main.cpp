//write includes statements
#include<iostream>
#include "loops.h"

//write using statements for cin and cout
using std::cin; using std::cout;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	int choice;

	do 
	{
		int num, result;
		cout << "Enter a number: ";
		cin >> num;
		result = factorial(num);

		cout << "Factorial of " << num << " is " << result << "\n";

		cout << "Enter 1 to continue...";
		cin >> choice;

	} while (choice == 1);


	return 0;
}