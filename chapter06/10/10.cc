#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>

#define LOOP 100000000

using namespace std;

size_t Cstrlen(const char *p);
char *Cstrcpy(char *p, const char *q);
int Cstrcmp(const char *p, const char *q);


int main()
{
    char p[32];
    char q[32];
    scanf("%s", p);
    scanf("%s", q);

    cout << Cstrlen(p) << endl;
    cout << Cstrcmp(p, q) << endl;
    Cstrcpy(p, q);
    cout << p << endl;

    clock_t begin;
    clock_t end;

    begin = clock();
    for (int i = 0; i < LOOP; ++i)
        Cstrlen(q);
    end = clock();
    cout << "Cstrlen: " << end - begin << endl;

    begin = clock();
    for (int i = 0; i < LOOP; ++i)
        strlen(q);
    end = clock();
    cout << "strlen : " << end - begin << endl;

    return 0;
}


size_t Cstrlen(const char *p)
{
    size_t len = 0;
    while (*p++)
        ++len;

    return len;
}


char *Cstrcpy(char *p, const char *q)
{
    char *d = p;
    while (*d++ = *q++)
        ;

    return p;
}


int Cstrcmp(const char *p, const char *q)
{
    while (*p && *q && *p == *q) {
        ++p;
        ++q;
    }

    return *p - *q;
}
