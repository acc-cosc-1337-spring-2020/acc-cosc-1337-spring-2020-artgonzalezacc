//

#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<cstddef>
#include<stddef.h>
/*
Rule of 3 - C++98
*/
class Vector 
{
public:
	Vector(size_t sz);
	Vector(const Vector& v);//copy constructor - Rule of 3 c++98
	Vector& operator=(const Vector& v);//copy assignment- Rule of 3 c++98
	Vector(Vector&& v);//move constructor Rule of 5 - c++11
	Vector&operator=(Vector&& v);//move assignment Rule of 5 - c++11
	size_t Size()const { return size; }
	int& operator[](int i) { return nums[i]; }
	int& operator[](int i)const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	~Vector();//destructor-Rule of 3 c++98
private:
	size_t size;
	size_t space{ 0 };
	int* nums;
};

#endif // !1

//doesn't belong to class
//free function
void use_vector();

Vector get_vector();