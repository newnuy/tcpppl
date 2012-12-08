#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char *cat(const char *p, const char *q);

int main()
{
    char p[32];
    char q[32];
    scanf("%s", p);
    scanf("%s", q);

    char *r = cat(p, q);
    cout << r << endl;
    delete [] r;

    return 0;
}

char *cat(const char *p, const char *q)
{
    char *r = new char[strlen(p)+strlen(q)+1];
    strcpy(r, p);
    strcat(r, q);

    return r;
}
