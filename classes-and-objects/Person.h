#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace HR
{
    class Person
    {
    private:
        std::string m_firstname;
        std::string m_lastname;

    public:
        Person() = default;
        Person(std::string firstname, std::string lastname);
        Person(const Person& src);

        void SetFirstname(std::string_view firstname);
        std::string GetFirstname() const;

        void SetLastname(std::string lastname);
        std::string GetLastname() const;

        std::string GetInitials() const;

        void Print() const;

        virtual std::string ToString() const;

        Person& operator=(const Person& rhs);

        virtual ~Person() = default;
    };
}