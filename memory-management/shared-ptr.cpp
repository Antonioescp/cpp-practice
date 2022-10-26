#include <iostream>
#include <memory>
#include "Basic.h"

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

// shared_ptr is used to share ownership of the same
// object, the object is destroyed until all shared_ptr
// instances refering to the same object are destroyed

int main()
{
	// sharing a resource
	auto obj{ make_shared<Basic>() };
	auto sameObj{ obj };
	
	cout << sameObj.use_count() << endl;
	obj.reset();	
	cout << sameObj.use_count() << endl;
	return 0;
}
