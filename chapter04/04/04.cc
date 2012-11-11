#include <iostream>

using namespace std;

int main()
{
    char c;

    for (c = 'a'; c <= 'z'; ++c)
        cout << c << " - " << int(c) << " - " << hex << int(c) << dec << endl;

    for (c = '0'; c <= '9'; ++c)
        cout << c << " - " << int(c) << " - " << hex << int(c) << dec << endl;

    return 0;
}
