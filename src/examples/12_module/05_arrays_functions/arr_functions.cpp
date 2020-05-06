//
#include<iostream>
#include "arr_functions.h"
//define iterate_array and loop through with ++ increment
#include<iostream>

void iterate_array(int * nums, const int SIZE)
{
	
	for (int i = 0; i < SIZE; ++i) 
	{
		std::cout << nums[i] << "\n";
	}
}
