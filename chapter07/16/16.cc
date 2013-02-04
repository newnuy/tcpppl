#include <iostream>

using namespace std;

void print(int value, int base=10);

int main()
{
    print(31);
    cout << endl;
    print(31, 10);
    cout << endl;
    print(31, 16);
    cout << endl;
    print(31, 2);
    cout << endl;

    return 0;
}

void print(int value, int base)
{
    if (value == 0)
        return;

    print(value/base, base);

    int unit = value % base;
    if (base == 16 && unit > 9) {
        cout << static_cast<char>('a' + (unit-10));
    }
    else
        cout << unit;
}
