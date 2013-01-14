#include <iostream>

using namespace std;

void printHello(int argc, char **argv)
{
    while (--argc)
        cout << "Hello, "<< *++argv << "!" << endl;
}

int main(int argc, char **argv)
{
    printHello(argc, argv);

    return 0;
}
