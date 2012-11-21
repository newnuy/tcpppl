#include <iostream>
#include <ctime>

#define NUM  1024
#define LOOP 1000000

using namespace std;

void indexLoop();
void pointLoop();

int main()
{
    clock_t begin;
    clock_t end;

    begin = clock();
    indexLoop();
    end = clock();
    cout << end - begin << endl;

    begin = clock();
    pointLoop();
    end = clock();
    cout << end - begin << endl;

    return 0;
}

void indexLoop()
{
    int str[NUM];
    for (int loop = LOOP; loop > 0; --loop)
        for (int i = 0; i < NUM; ++i)
            str[i] = 1;
}

void pointLoop()
{
    int str[NUM];
    for (int loop = LOOP; loop > 0; --loop)
        for (int *p = str; p < str+NUM; ++p)
            *p = 1;
}
