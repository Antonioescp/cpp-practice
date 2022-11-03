#pragma once

#include "Employee.h"

namespace HR
{
    class Manager : public Employee
    {
    public:
        using Employee::Employee;
        std::string ToString() const override;
    };
}