#include "Person.h"

namespace HR
{
    Person::Person(std::string firstname, std::string lastname)
        : m_firstname{ firstname }, m_lastname{ lastname }
    {
        std::cout << "Person has been constructed" << std::endl;
    }

    Person::Person(const Person& src)
        : m_firstname{ src.GetFirstname() }, m_lastname{ src.GetLastname() }
    {
        std::cout << "Person has been copy-constructed" << std::endl;
    }

    void Person::SetFirstname(std::string_view firstname)
    {
        m_firstname = firstname;
    }

    std::string Person::GetFirstname() const
    {
        return m_firstname;
    }

    void Person::SetLastname(std::string lastname)
    {
        m_lastname = lastname;
    }

    std::string Person::GetLastname() const
    {
        return m_lastname;
    }

    std::string Person::GetInitials() const
    {
        std::string initials;
        initials += m_firstname.at(0);
        initials += ". ";
        initials += m_lastname.at(0);
        initials += '.';
        return initials;
    }

    void Person::Print() const
    {
        std::cout
            << "My name is "
            << m_firstname
            << " and my last name is "
            << m_lastname
            << std::endl;
    }

    std::string Person::ToString() const
    {
        return m_lastname + ", " + m_firstname;
    }

    Person& Person::operator=(const Person& rhs)
    {
        m_firstname = rhs.GetFirstname();
        m_lastname = rhs.GetLastname();

        std::cout << "Person has been assigned" << std::endl;
        return *this;
    }
}