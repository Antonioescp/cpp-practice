#include "Employee.h"

#include <charconv>

namespace HR
{

    Employee::Employee(std::string firstname, std::string lastname, int employeeID)
        : Person{ firstname, lastname }
        , m_employeeID{ employeeID }
    { }

    std::string Employee::ToString() const
    {
        return Person::ToString() + " Employee " + std::to_string(m_employeeID);
    }
}