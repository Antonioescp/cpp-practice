#include "Manager.h" 

namespace HR
{
    std::string Manager::ToString() const
    {
        return Employee::ToString() + " Manager";
    }
}