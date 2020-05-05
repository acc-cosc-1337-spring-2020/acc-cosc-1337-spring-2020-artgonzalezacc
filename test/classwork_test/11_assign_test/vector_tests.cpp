#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test class copy with stack variables") 
{
	Vector<int> v1(3);
	Vector<int> v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
}

TEST_CASE("Test class copy with dynamic(heap) variables") 
{
	Vector<int> v1(3);
	Vector<int> v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
	v1[1] = 5;

	REQUIRE(v1[1] != v2[1]);
	REQUIRE(v1[1] == 5);
	REQUIRE(v2[1] == 0);
}

TEST_CASE("Test class copy dynamic heap w 2 variables") 
{
	Vector<double> v1(3);
	Vector<double> v2(3);
	v2 = v1;
	v1[1] = 5;

	REQUIRE(v1[1] != v2[2]);
}

TEST_CASE("Test vector capacity and reserve") 
{
	Vector<double> v(3);
	REQUIRE(v.Capacity() == 3);
	REQUIRE(v.Size() == 3);
	
	v.Reserve(6);
	REQUIRE(v.Capacity() == 6);
	REQUIRE(v.Size() == 3);
}

TEST_CASE("Test vector resize") 
{
	Vector<int> v(3);
	v[0] = 3;
	v[1] = 4;
	v[2] = 5;
	
	v.Resize(6);
	REQUIRE(v[0] == 3);
	REQUIRE(v[1] == 4);
	REQUIRE(v[2] == 5);
	REQUIRE(v[3] == 0);
	REQUIRE(v[4] == 0);
	REQUIRE(v[5] == 0);
}

TEST_CASE("Test vector push back") 
{
	Vector<int> v(3);
	v.Push_Back(5);

	REQUIRE(v[3] == 5);
}

TEST_CASE("Test default constructor w push back") 
{
	Vector<double> v;
	REQUIRE(v.Capacity() == 0);
	v.Push_Back(5);
	REQUIRE(v.Capacity() == 8);
	REQUIRE(v.Size() == 1);

}
