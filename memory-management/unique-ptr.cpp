#include <iostream>
#include <memory>
#include "Basic.h"

using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;

// unique_ptr frees resources when an exceptions occurs
// and when it goes out of scope
//
// make_unique does the allocation for us, instead of us
// using new explicitly, with make_unique primitives are
// zero-initialized and objects default constructed

// you can also have your own functions to allocate
// and free memory
Basic* NewBasic()
{
	return new Basic;
}

void FreeBasic(Basic* obj)
{
	delete obj;
}

int main()
{
	// This is the recommended way to create a
	// unique_ptr, since the syntax is more
	// readable
	auto test = make_unique<Basic>();
	
	// This is also valid but is way less readable
	unique_ptr<Basic> obj{ new Basic{} };
	
	// you can manually realease the resource
	// losing ownership
	// obj.release();
	// or free it and set it to another value
	// obj.reset(new Basic{});
	// or just free it and set the pointer to
	// null
	obj.reset();

	// Using own allocation
	unique_ptr<Basic, decltype(&FreeBasic)> ptr{ NewBasic(), FreeBasic };
	return 0;
}
