#include <iostream>

using namespace std;

int fact(int num)
{
    int product = 1;
    while (num-- > 1)
        product *= num;

    return product;
}

int main()
{
    int num;
    while (cin >> num)
        cout << fact(num) << endl;

    return 0;
}
