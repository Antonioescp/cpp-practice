#include "Manager.h"
#include "Director.h"

#include <memory>
#include <iostream>
#include <vector>

using namespace HR;
using namespace std;

int main()
{
    vector<unique_ptr<Person>> humanResources;

    unique_ptr<Person> test;
    test = make_unique<Manager>();

    humanResources.emplace_back(new Manager("John", "Smith"));
    humanResources.emplace_back(new Director("Toni", "Perez", 10));
    humanResources.emplace_back(new Employee("Carlos", "Godinez", 20));

    for ( const auto& p : humanResources )
    {
        cout << p->ToString() << endl;
    }
}