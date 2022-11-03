#include "Director.h"

namespace HR
{
    std::string Director::ToString() const
    {
        return Employee::ToString() + " Director";
    }
}