#include <iostream>
#include <span>

using std::cout;
using std::endl;

// This function modifies the original array
void DoubleValues(int* val, size_t size)
{
	for (int i{}; i < size; i++)
	{
		val[i] *= 2;
	}
}
// These are the same
// void DoubleInts(int val[], size_t size);
// void DoubleInts(int val[2], size_t size);
// the size 2 given to the first parameter is
// simply ignored


// There is a way to accept stack arrays with a 
// certain size
void StackWithSizeTwo(int (&arr)[2])
{
	return;
}

// you can even make it a template
template <class T, size_t N>
void UseStackArray(T (&arr)[N])
{
	return;
}

// on c++20 you can use std::span which wraps the array
// and its size
void UseArray(std::span<int> arr)
{
	cout << "the size is " << arr.size() << endl;
	return;
}

int main()
{
	int arr[]{1, 2, 3};
	UseArray(arr);
}
