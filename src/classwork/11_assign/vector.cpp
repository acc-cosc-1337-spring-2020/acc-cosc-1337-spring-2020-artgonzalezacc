#include "vector.h"
#include<iostream>
/*
Initialize nums to size dynamic array.
Initialize each array element to 0.
*/
Vector::Vector(size_t sz) 
	: size{sz}, nums{new int[sz]}
{
	for (size_t i = 0; i < sz; ++i) 
	{
		nums[i] = 0;
	}
}

/*
 Copy v.size to new class
 Create new dynamic memory array
 Initialize array elements to the v.nums array values
*/
Vector::Vector(const Vector & v)
	: size{v.size}, nums{new int[v.size]}
{
	for (size_t i = 0; i < size; ++i) 
	{
		nums[i] = v[i];
	}
}

/*
Allocate temporary dynamic array of size v (v1)
Copy v1 elements to temp array
Deallocate old v2 nums array
Point v2 nums array to temp array
Set v2 size to v1 size
return a self copy of Vector
*/
Vector & Vector::operator=(const Vector & v)
{
	int* temp = new int[v.size];

	for (size_t i = 0; i < v.size; ++i) 
	{
		temp[i] = v[i];
	}

	delete nums;

	nums = temp;
	size = v.size;

	return *this;
}

/*
Release dynamic memory
Deallocate memory
*/
Vector::~Vector() 
{
	std::cout << "\nrelease memory\n";
	delete[] nums;
}

//=====================
//free function
void use_vector() 
{
	Vector* v1 = new Vector(3);
	delete v1;
	v1 = nullptr;
}