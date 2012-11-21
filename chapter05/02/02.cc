#include <iostream>

using namespace std;

struct cp {
    char a;    // 1 Byte
    char *pc;  // 4 Bytes on x86 and 8 Bytes on x86_64
    char b;
    int *pi;
    char c;
    void *pv;
};

int main()
{
    cp test;
    cout << "a   - " << (void *)&test.a << endl;
    cout << "*pc - " << &test.pc << endl;
    cout << "b   - " << (void *)&test.b << endl;
    cout << "*pi - " << &test.pi << endl;
    cout << "c   - " << (void *)&test.c << endl;
    cout << "*pv - " << &test.pv << endl;

    return 0;
}
