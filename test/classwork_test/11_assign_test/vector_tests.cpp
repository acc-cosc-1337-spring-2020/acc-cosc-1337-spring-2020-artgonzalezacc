#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "vector.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test class copy with stack variables") 
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
}

TEST_CASE("Test class copy with dynamic(heap) variables") 
{
	Vector v1(3);
	Vector v2 = v1;

	REQUIRE(v1.Size() == v2.Size());
	v1[1] = 5;

	REQUIRE(v1[1] != v2[1]);
	REQUIRE(v1[1] == 5);
	REQUIRE(v2[1] == 0);
}

TEST_CASE("Test class copy dynamic heap w 2 variables") 
{
	Vector v1(3);
	Vector v2(3);
	v2 = v1;
	v1[1] = 5;

	REQUIRE(v1[1] != v2[2]);
}

TEST_CASE("Test vector capacity and reserve") 
{
	Vector v(3);
	REQUIRE(v.Capacity() == 3);
	REQUIRE(v.Size() == 3);
	
	v.Reserve(6);
	REQUIRE(v.Capacity() == 6);
	REQUIRE(v.Size() == 3);
}
