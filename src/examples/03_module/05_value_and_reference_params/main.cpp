#include<iostream>

using std::cout;

int main() 
{
	int num = 5;
	cout << "Value of num is: " << num << " Address is " << &num;

	int &num_ref = num;
	num_ref = 10;
	cout << "\nValue of num is: " << num << " Address is " << &num;

	return 0;
}