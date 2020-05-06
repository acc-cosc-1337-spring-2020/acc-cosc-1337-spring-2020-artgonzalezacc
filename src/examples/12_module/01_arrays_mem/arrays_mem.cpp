//write code for for stack_array and display each element to screen
#include<iostream>

void use_hours_array() 
{
	const int SIZE = 5;
	int hours[SIZE];

	for (int i = 0; i < SIZE; ++i) 
	{
		hours[i] = i * 10;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << hours[i] << "\n";
	}
}

void use_hours_array_init_list() 
{
	const int SIZE = 5;
	int hours[SIZE] = {5, 10, 30, 20, 7};

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << hours[i] << "\n";
	}

}

void use_hours_array_init_list_auto() 
{
	const int SIZE = 5;
	int hours[SIZE] = { 5, 10, 30, 20, 7 };

	for (auto hour : hours) 
	{
		std::cout << hour << "\n";
	}
}