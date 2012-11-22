#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void inputDate(Date *date);
void outputDate(const Date *date);
void initDate(Date *date, int year, int month, int day);

int main()
{
    Date date;
    initDate(&date, 1970, 1, 1);
    outputDate(&date);
    inputDate(&date);
    outputDate(&date);

    return 0;
}

void inputDate(Date *date)
{
    cin >> date->year >> date->month >> date->day;
}

void outputDate(const Date *date)
{
    cout << date->year << "-" << date->month << "-" << date->day << endl;
}

void initDate(Date *date, int year, int month, int day)
{
    date->year = year;
    date->month = month;
    date->day = day;
}
