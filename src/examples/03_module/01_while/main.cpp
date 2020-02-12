#include "while.h"
#include<iostream>

using std::cout; using std::cin;

int main() 
{
	int num, sum;

	cout << "Enter a number: ";
	cin >> num;

	sum = sum_of_squares(num);

	cout << "Sum of squares for " << num << " is " << sum;

	return 0;
}