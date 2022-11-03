#pragma once

#include "Person.h"

#include <string>

namespace HR
{
    class Employee : public Person
    {
    private:
        int m_employeeID{};

    public:
        using Person::Person;
        Employee(std::string firstname, std::string lastname, int employeeID);

        std::string ToString() const override;
    };
}
