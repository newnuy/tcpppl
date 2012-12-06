#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    while (i > 0)
        ++i;
    cout << i << endl;

    i = -1;
    while (i < 0)
        --i;
    cout << i << endl;

    i = 1;
    int j = 0;
    i /= j;
    cout << i << endl;

    return 0;
}
