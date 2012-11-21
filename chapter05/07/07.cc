#include <iostream>
#include <string>

using namespace std;

struct monthDay {
    string month;
    int day;
};

int main()
{
    char month[12][10] = {"January", "February", "March", "April",
            "May", "June", "July", "August", "September", "October",
            "November", "December"};
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; ++i)
        cout << day[i] << " - " << month[i] << endl;

    cout << endl << "Again !" << endl << endl;

    monthDay md[12] = {{"January", 31}, {"February", 28}, {"March", 31},
            {"April", 30}, {"May", 31}, {"June", 30}, {"July", 31},
            {"August", 31}, {"September", 30}, {"October", 31},
            {"November", 30}, {"December", 31}};
    for (int i = 0; i < 12; ++i)
        cout << md[i].day << " - " << md[i].month << endl;

    return 0;
}
