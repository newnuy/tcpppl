#include <iostream>

using namespace std;

void cat(int argc, char **argv)
{
    while (--argc)
        cout << *++argv;
    cout << endl;
}

int main(int argc, char **argv)
{
    cat(argc, argv);

    return 0;
}
