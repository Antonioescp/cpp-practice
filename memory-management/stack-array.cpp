#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// This is a stack array, its size, 10 in this
	// case, needs to be known at compile time,
	// which means you cant use a runtime value to
	// set a stack array size, some compilers allow
	// it but is not part of C++ standard spec, so 
	// using a runtime value should be avoided
	// the {} initializes to 0 the 10 elements,
	// you can also provide values like { 1, 2, 3}
	// if the amount of elements is less than the
	// especified size then the remaining elements
	// will zero-initialized, as if {} was used for
	// each one of them, you should be familiar
	// with zero-initialization
	// https://en.cppreference.com/w/cpp/language/zero_initialization
	int arr[10]{};

	return 0;
}
