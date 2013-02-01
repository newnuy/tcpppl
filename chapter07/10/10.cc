#include <iostream>

using namespace std;

void encrypt(char *str, size_t len)
{
    const char *key = "hello, world";

    const char *p = key;
    while (len--) {
        if (*p == '\0')
            p = key;
        *str++ ^= *p++;
    }
}

int main()
{
    char str[512];
    char c;
    char *pStr = str;
    int len = 0;
    while (cin.get(c)) {
        *pStr++ = c;
        ++len;
    }
    *pStr = '\0';

    encrypt(str, static_cast<size_t>(len));
    encrypt(str, static_cast<size_t>(len));

    cout << str;

    return 0;
}
