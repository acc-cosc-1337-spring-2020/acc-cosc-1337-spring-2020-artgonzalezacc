//

#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<cstddef>
#include<stddef.h>
/*
Rule of 3 - C++98
*/
template<typename T>
class Vector 
{
public:
	Vector();
	Vector(size_t sz);
	Vector(const Vector<T>& v);//copy constructor - Rule of 3 c++98
	Vector<T>& operator=(const Vector<T>& v);//copy assignment- Rule of 3 c++98
	Vector(Vector<T>&& v);//move constructor Rule of 5 - c++11
	Vector<T> &operator=(Vector<T>&& v);//move assignment Rule of 5 - c++11
	size_t Size()const { return size; }
	T& operator[](int i) { return nums[i]; }
	T& operator[](int i)const { return nums[i]; }
	void Reserve(size_t new_allocation);
	size_t Capacity()const { return space; }
	void Resize(size_t new_size);
	void Push_Back(T value);
	~Vector();//destructor-Rule of 3 c++98
private:
	size_t size;
	size_t space{ 0 };
	T* nums;
	const int RESERVE_DEFAULT_SIZE{ 8 };
	const int RESERVE_DEFAULT_MULTIPLIER{ 2 };
};

#endif // !1

//doesn't belong to class
//free function
void use_vector();

Vector<int> get_vector();