#include <iostream>
#include "Data.h"
#include <memory>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

void UseResource(weak_ptr<Data>& resource)
{
	auto shared{ resource.lock() };
	if (shared)
		cout << "The resource is available" << endl;
	else
		cout << "The resource is no longer available" << endl;
}

int main()
{
	auto shared{ make_shared<Data>() };
	weak_ptr<Data> test{ shared };
	UseResource(test);
	test.reset();
	UseResource(test);
}
