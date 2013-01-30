#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int (*CFT)(const void *, const void *);

struct User {
    const char *name;
    const char *id;
    int dept;
};
User heads[] = {
    "Ritchie D.M.",   "dmr",  11271,
    "Sethi R.",       "ravi", 11272,
    "Szymanski T.G.", "tgs",  11273,
    "Schryer N.L.",   "nls",  11274,
    "Schryer N.L.",   "nls",  11275,
    "Kernighan B.W.", "bwk",  11276
};

int cmp1(const void *p, const void *q)
{
    return strcmp(static_cast<const User *>(p)->name, static_cast<const User *>(q)->name);
}

void print_id(User *v, int n)
{
    for (int i = 0; i < n; ++i)
        cout << v[i].name << '\t' << v[i].id << '\t' << v[i].dept << endl;
}

void swap(void *base, size_t sz, int i, int j)
{
    char *p = static_cast<char *>(base) + i*sz;
    char *q = static_cast<char *>(base) + j*sz;
    while (sz--) {
        char c = *p;
        *p++ = *q;
        *q++ = c;
    }
}

void ssort(void *base, size_t n, size_t sz, CFT cmp)
{
    int left = 0;
    int right = n - 1;
    if (left >= right)
        return;

    swap(base, sz, left, (left+right)/2);
    int last = left;
    for (int i = left+1; i <= right; ++i)
        if (cmp(static_cast<char *>(base)+i*sz,
                static_cast<char *>(base)+left*sz) < 0)
            swap(base, sz, ++last, i);
    swap(base, sz, left, last);

    ssort(base, last-left, sz, cmp);
    ssort(static_cast<char *>(base)+(last+1)*sz, n-(last+1), sz, cmp);
}

int main()
{
    ssort(heads, 6, sizeof(User), cmp1);
    print_id(heads, 6);

    return 0;
}
