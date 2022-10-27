#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Basic
{

public:
	Basic()
	{
		cout << "Basic constructed" << endl;
	}

	~Basic()
	{
		cout << "Basic destroyed" << endl;
	}
};
