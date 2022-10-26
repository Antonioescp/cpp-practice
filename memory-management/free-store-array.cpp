#include <iostream>

using std::cout;
using std::endl;

int main()
{
	// This is an array allocated in the free store,
	// the advantage is that you can use a runtime
	// value to set its size, the disadvantage is
	// that you need to free its memory manually
	// using the delete[] operator, initialization
	// is the same as the stack array, see
	// stack-array.cpp
	int size{100};
	int* arr = new(std::nothrow) int[size]{};
	delete[] arr;

	return 0;
}
