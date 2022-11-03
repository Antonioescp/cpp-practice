#include <iostream>
#include <vector>
#include <optional>
#include <string>

using namespace std;

class Criminal
{
    friend class Interviewer;
    friend std::string GetReport(const Criminal&);

private:
    std::string m_confession;

public:
    Criminal(std::string crime)
        : m_confession{ "Yes, I did " + crime }
    { }
};

class Interviewer
{
public:
    std::string GetToTalk(const Criminal& criminal)
    {
        return criminal.m_confession;
    }
};

std::string GetReport(const Criminal& criminal)
{
    return "The criminal confessed, saying: \"" + criminal.m_confession + "\".";
}

int main()
{
    Criminal pedro{ "kill a cat" };
    Interviewer ramirez;

    cout << ramirez.GetToTalk(pedro) << endl;
    cout << GetReport(pedro) << endl;
}