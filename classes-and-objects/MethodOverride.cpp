#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    virtual void SomeMethod()
    {
        cout << "Method in Base class" << endl;
    }

    virtual ~Base()
    {
        cout << "Base destroyed" << endl;
    }
};

class Derived : public Base
{
public:
    void SomeMethod() override
    {
        cout << "Method in Derived class" << endl;
    }

    ~Derived() override
    {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Base third{ Derived{} };
    third.SomeMethod();
}