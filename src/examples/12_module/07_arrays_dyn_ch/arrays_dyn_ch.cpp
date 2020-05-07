#include "arrays_dyn_ch.h"
#include<iostream>


void use_dyn_char_array()
{
	const int SIZE = 10;
	char* name = new char[SIZE];//ALLOCATE
	std::cout << "Enter name: ";
	std::cin.getline(name, 10);
	std::cout << name << "\n";

	delete[] name;
}

void use_dyn_char_array_manual() 
{
	const int SIZE = 10;
	char* name = new char[SIZE];
	name[0] = 'J';
	name[1] = 'o';
	name[2] = 'e';
	name[3] = '\0';

	std::cout << name << "\n";

	delete[] name;
}
