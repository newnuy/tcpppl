#include <iostream>

using namespace std;

void encrypt(char *str, size_t len, const char *key)
{
    if (key == 0)
        return;

    const char *p = key;
    while (len--) {
        if (*p == '\0')
            p = key;
        *str++ ^= *p++;
    }
}

int main(int argc, char **argv)
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

    if (argc == 1) {
        encrypt(str, static_cast<size_t>(len), static_cast<const char *>(0));
        encrypt(str, static_cast<size_t>(len), static_cast<const char *>(0));
    }
    else {
        encrypt(str, len, *++argv);
        encrypt(str, len, *argv);
    }

    cout << str;

    return 0;
}
