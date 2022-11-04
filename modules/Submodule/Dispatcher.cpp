module;

#include <iostream>

export module Module.Dispatcher;

export void Dispatch()
{
    std::cout << "Goodbye world" << std::endl;
}