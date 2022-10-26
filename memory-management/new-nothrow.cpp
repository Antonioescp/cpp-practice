#include <iostream>

using std::cout;
using std::endl;
// calls to new using noexcept will not throw when
// there is no available memory, instead will return a
// nullptr, is ok to call delete on a nullptr
int main()
{
	cout << "Creating object" << endl;
	int* ptr = new(std::nothrow) int{};
	delete ptr;

	if (ptr != nullptr)
		cout << "Object created" << endl;
	else
		cout << "Couldn't create, low mem" << endl;
}
