#include<iostream>
#include "switch.h"

using std::cin;  using std::cout;

int main() 
{
	int option;

	cout << "Enter a number: ";
	cin >> option;

	string result = menu(option);
	cout << result;

	return 0;
}