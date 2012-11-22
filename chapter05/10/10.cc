#include <iostream>

using namespace std;

void printMonthName(char (&month)[12][10]);

int main()
{
    char month[12][10] = {"January", "February", "March", "April",
            "May", "June", "July", "August", "September", "October",
            "November", "December"};
    printMonthName(month);

    return 0;
}

void printMonthName(char (&month)[12][10])
{
    for (int i = 0; i < 12; ++i)
        cout << month[i] << endl;
}
