module;

#include <iostream>

export module Module.Greeter;

export void Greet()
{
    std::cout << "Hello world" << std::endl;
}