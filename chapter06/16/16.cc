#include <iostream>
#include <cstdio>

using namespace std;

int Catoi(const char *p);

int main()
{
    char str[32];

    for (int i = 0; i < 4; ++i) {
        scanf ("%s", str);
        cout << Catoi(str) << endl;
    }

    return 0;
}

int Catoi(const char *p)
{
    int num = 0;
    int symbol = 1;
    int base = 10;

    switch (*p) {
        case '-':
            symbol = -1;
            ++p;
            break;
        default:
            break;
    }

    switch (*p) {
        case '0':
            switch (*++p) {
                case 'x':
                case 'X':
                    base = 16;
                    ++p;
                    break;
                default:
                    base = 8;
                    break;
            }
            break;
        default:
            break;
    }

    while (*p) {
        if (*p >= 'a' && *p <= 'f')
            num = base*num + (*p++ - 'a' + 10);
        else if (*p >= 'A' && *p <= 'F')
            num = base*num + (*p++ - 'A' + 10);
        else
            num = base*num + (*p++ - '0');
    }

    return symbol * num;
}
