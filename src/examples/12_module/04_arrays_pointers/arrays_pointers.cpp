//cpp
#include "arrays_pointers.h"
#include <iostream>
void use_hours_array_w_pointer() 
{
	const int SIZE = 5;
	int hours[SIZE] = { 5, 10, 30, 20, 7 };

	int* hours_ptr = hours;

	std::cout << *hours_ptr << "\n";
	*hours_ptr++;
	std::cout << *hours_ptr << "\n";
	*hours_ptr--;
	std::cout << *hours_ptr << "\n";
}

void use_hours_array_w_pointer_loop() 
{
	const int SIZE = 5;
	int hours[SIZE] = { 5, 10, 30, 20, 7 };

	int* hours_ptr = hours;

	for (int i = 0; i < SIZE; ++i) 
	{
		std::cout << *hours_ptr << "\n";
		hours_ptr++;
	}

	for (int i = 0; i < SIZE; ++i)
	{
		hours_ptr--;
		std::cout << *hours_ptr << "\n";
	}
}
