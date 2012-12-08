#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void rev(char *p);

int main()
{
    char p[32];
    scanf("%s", p);
    rev(p);
    cout << p << endl;

    return 0;
}

void rev(char *p)
{
    for (char *q = p+strlen(p)-1; p < q; ++p, --q) {
        char c = *q;
        *q = *p;
        *p = c;
    }
}
