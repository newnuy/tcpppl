#include <iostream>

using namespace std;

enum { ONE, TWO, THREE, FOUR, FIVE };

int main()
{
    cout << "size of bool       : " << sizeof(bool) << endl;
    cout << "size of char       : " << sizeof(char) << endl;
    cout << "size of short int  : " << sizeof(short) << endl;
    cout << "size of int        : " << sizeof(int) << endl;
    cout << "size of long int   : " << sizeof(long) << endl;
    cout << "size of float      : " << sizeof(float) << endl;
    cout << "size of double     : " << sizeof(double) << endl;
    cout << "size of long double: " << sizeof(long double) << endl;
    cout << "size of char *     : " << sizeof(char *) << endl;
    cout << "size of int *      : " << sizeof(int *) << endl;
    cout << "size of double *   : " << sizeof(double *) << endl;
    cout << "size of enum       : " << sizeof(ONE) << endl;

    return 0;
}
