#include <iostream>
#include <memory>
#include "Basic.h"
#include "Data.h"

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

	// aliasing
	auto objWithMember{ make_shared<Data>() };
	auto alias{ shared_ptr<int>{ objWithMember, &objWithMember->data } };

	cout << alias.use_count() << endl;
	objWithMember.reset();
	cout << alias.use_count() << endl;
	
	cout << *alias << endl;

	return 0;
}
