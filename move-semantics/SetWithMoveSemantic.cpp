#include <iostream>
#include <string>

using namespace std;

class Data
{
public:
    Data()
    {
        cout << "Data constructed" << endl;
    }

    Data(const Data& src)
    {
        cout << "Data copied" << endl;
    }

    Data& operator=(const Data& src)
    {
        cout << "Data copy-assigned" << endl;
        return *this;
    }

    Data(Data&& src) noexcept
    {
        cout << "Data moved" << endl;
    }

    Data& operator=(Data&& src)
    {
        cout << "Data move-assigned" << endl;
        return *this;
    }

    virtual ~Data()
    {
        cout << "Data destroyed" << endl;
    }
};

// Yes, a pass-by-value is used
void SetWithMoveSemantics(Data& target, Data src)
{
    target = move(src);
}

int main()
{
    Data first;
    Data second;

    // This will copy second to src and move src to first
    SetWithMoveSemantics(first, second);

    cout << endl << "Only moves here" << endl;
    Data third;

    // This will move src to third
    SetWithMoveSemantics(third, Data{});

    cout << endl;
}