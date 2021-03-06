#include <iostream>

using namespace std;

void swapByPoint(int *i, int *j);
void swapByReference(int& i, int& j);

int main()
{
    int i;
    int j;
    cin >> i >> j;
    cout << i << " - " << j << endl;

    swapByPoint(&i, &j);
    cout << i << " - " << j << endl;

    swapByReference(i, j);
    cout << i << " - " << j << endl;

    return 0;
}

void swapByPoint(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void swapByReference(int& i, int& j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}
