#pragma once

#include "Employee.h"

namespace HR
{
    class Director : public Employee
    {
    public:
        using Employee::Employee;
        std::string ToString() const override;
    };
}