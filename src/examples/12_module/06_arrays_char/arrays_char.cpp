//cpp
#include "arrays_char.h"
#include<iostream>

void use_char_array() 
{
	char letter = 'a';
	char name[] = "John";
	std::cout << name << "\n";
}

void use_char_array_w_size() 
{
	const int SIZE = 5;
	char name[SIZE] = "Mary";//uses 0 1 2 3 index slots
	name[4] = '\0'; //index slot 4
	std::cout << name << "\n\n";

	for (int i = 0; name[i] != '\0'; ++i) 
	{
		std::cout << name[i] << "\n";
	}

}