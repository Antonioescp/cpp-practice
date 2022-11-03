#include <iostream>
#include <vector>
#include <memory>
#include <charconv>

using namespace std;

class Tester
{
private:
    bool m_moved{ false };
    bool m_isCopy{ false };
    int m_id;

    static int s_currentID;
public:
    Tester()
        : m_id{ s_currentID++ }
    {
        cout << "Tester " + to_string(m_id) + " using dflt-ctor" << endl;
    }

    Tester(const Tester& src)
        : m_id{ s_currentID++ }
    {
        m_isCopy = true;
        cout << "Tester " + to_string(m_id) + " using copy-ctor" << endl;
    }

    Tester(Tester&& src)
        : m_id{ s_currentID++ }
    {
        src.m_moved = true;
        cout << "Tester " + to_string(m_id) + " using move-ctor" << endl;
    }

    Tester& operator=(const Tester& rhs)
    {
        m_isCopy = true;
        cout << "Tester " + to_string(m_id) + " using copy-assign" << endl;
        return *this;
    }

    Tester& operator=(Tester&& rhs)
    {
        rhs.m_moved = true;
        cout << "Tester " + to_string(m_id) + " using move-assign" << endl;
        return *this;
    }

    virtual ~Tester()
    {
        cout << "** Tester " + to_string(m_id) + " deleted" << endl;
        cout << "** isCopy: " << boolalpha << m_isCopy << endl
            << "** Moved: " << m_moved << endl;
    }
};

int Tester::s_currentID{};

int main()
{
    vector<Tester> yikes;

    cout << "Trying stack vector" << endl;
    cout << "-- Trying push back" << endl;
    yikes.push_back(Tester{});
    cout << "-- Trying emplace back" << endl;
    yikes.emplace_back();

    cout << "Trying ptr vector" << endl;

    vector<Tester*> ptrs;

    cout << "-- push_back" << endl;
    ptrs.push_back(new Tester{});

    cout << "-- emplace_back" << endl;
    ptrs.emplace_back(new Tester{});

    for ( const auto* ptr : ptrs )
        delete ptr;

    cout << "Trying unique_ptr vector" << endl;

    vector<unique_ptr<Tester>> uptrs;

    cout << "-- push_back" << endl;
    uptrs.push_back(make_unique<Tester>());

    cout << "-- emplace_back" << endl;
    uptrs.emplace_back(new Tester{});
}