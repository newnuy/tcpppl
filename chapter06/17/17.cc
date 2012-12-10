#include <iostream>
#include <cstdio>

using namespace std;

void Citoa(int i, char b[]);

const int base = 10;

int main()
{
    int num;
    char str[32];

    for (int i = 0; i < 2; ++i) {
        cin >> num;
        Citoa(num, str);
        cout << str << endl;
    }

    return 0;
}

void Citoa(int i, char b[])
{
    char *p = b;
    do {
        *p++ = i % base + '0';
    } while (i /= base);
    *p = '\0';

    for (--p; b < p; ++b, --p) {
        char temp = *b;
        *b = *p;
        *p = temp;
    }
}
