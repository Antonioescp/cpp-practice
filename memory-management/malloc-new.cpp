#include <stdlib.h>
#include <iostream>

class Box
{
public:
	Box()
	{
		std::cout << "I have been constructed\n";
	}

	~Box()
	{
		std::cout << "I have been destroyed\n";
	}
};

// calls to new and delete call the constructor and
// destructor respectively while malloc and free
// dont
int main()
{
	Box* ptr = new Box{};
	delete ptr;

	ptr = (Box*)malloc(sizeof(Box));
	free(ptr);

	return 0;
}
