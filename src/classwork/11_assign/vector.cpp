#include "vector.h"
#include<iostream>
/*
Initialize nums to size dynamic array.
Initialize each array element to 0.
*/
Vector::Vector(size_t sz) 
	: size{sz}, nums{new int[sz]}, space{sz}
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
Get the dynamic memory from v
Get the size from v
Point the v.nums to nullptr
*/
Vector::Vector(Vector && v)
	: size{v.size}, nums{v.nums}
{
	v.size = 0;
	v.nums = nullptr;
}

/*
Deallocate original dynamic memory
Get the dynamic memory from v
Get the size from v
Point v.nums to nullptr
Set v.size to 0
*/
Vector & Vector::operator=(Vector && v)
{
	delete nums;
	nums = v.nums;
	size = v.size;
	v.nums = nullptr;
	v.size = 0;
	
	return *this;
}

/*
Make sure new alllocation is greater than space
Create temporary dynamic array of size new allocation
Copy values from old memory array to temporary array
Delete the old memory array (nums)
Set nums to temporary memory array
Set space = new allocation
*/
void Vector::Reserve(size_t new_allocation) 
{
	if (new_allocation <= space) 
	{
		return;
	}

	int* temp = new int[new_allocation];

	for (size_t i = 0; i < size; ++i) 
	{
		temp[i] = nums[i];
	}

	delete[] nums;

	nums = temp;

	space = new_allocation;
}

/*
Reserve space
Initialize element values beyond size to 0
*/
void Vector::Resize(size_t new_size) 
{
	Reserve(new_size);

	for (size_t i = size ; i < new_size; ++i) 
	{
		nums[i] = 0;
	}

	size = new_size;
}

void Vector::Push_Back(int value)
{
	if (space == 0) 
	{
		Reserve(RESERVE_DEFAULT_SIZE);
	}
	else if(size == space)
	{//should this be resize or reserve? 
		Reserve(space * RESERVE_DEFAULT_MULTIPLIER);
	}

	nums[size] = value;
	++size;
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

Vector get_vector()
{
	Vector v(3);

	return v;
}
