#include <iostream>
#include <cstdarg>

using namespace std;

void error(const char *str ...)
{
    va_list ap;
    va_start(ap, str);

    while (*str != '\0') {
        if (*str == '%') {
            char next = *(str+1);
            switch (next) {
            case 's':
                {
                char *p = va_arg(ap, char *);
                cerr << p;
                str += 2;
                break;
                }
            case 'c':
                {
                int c = va_arg(ap, int);
                cerr << static_cast<char>(c);
                str += 2;
                break;
                }
            case 'd':
                {
                int num = va_arg(ap, int);
                cerr << num;
                str += 2;
                break;
                }
            default:
                {
                cerr << *str++;
                break;
                }
            }
        }
        else {
            cerr << *str++;
        }
    }

    va_end(ap);
}

int main()
{
    error("%d error%c : %s", 3, 's', "Unknown");
    cout << endl;

    return 0;
}
