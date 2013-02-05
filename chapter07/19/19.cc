#include <iostream>
#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

enum ONE_YEAR_MONTH_DAY {
    ONE_YEAR,
    ONE_MONTH,
    ONE_DAY
};

void inputDate(Date *date);
void outputDate(const Date *date);
void initDate(Date *date, int year, int month, int day);
bool isDateValid(Date *date);
void addOne(Date *date, ONE_YEAR_MONTH_DAY addWhat);
int getWeekday(Date *date);
string convertIntToWeekday(int weekday);
Date nextMonday(Date *date);

int main()
{
    Date date;

    initDate(&date, 1970, 1, 1);
    outputDate(&date);
    addOne(&date, ONE_YEAR);
    outputDate(&date);
    cout << endl;

    initDate(&date, 2013, 1, 31);
    outputDate(&date);
    cout << convertIntToWeekday(getWeekday(&date)) << endl;
    addOne(&date, ONE_MONTH);
    outputDate(&date);
    cout << endl;

    initDate(&date, 2012, 2, 28);
    outputDate(&date);
    addOne(&date, ONE_DAY);
    outputDate(&date);
    cout << endl;

    initDate(&date, 2013, 2, 6);
    outputDate(&date);
    Date newDate = nextMonday(&date);
    outputDate(&newDate);

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

bool isDateValid(Date *date)
{
    bool ret = true;
    switch (date->month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (date->day > 31)
                ret = false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (date->day > 30)
                ret = false;
            break;
        case 2:
            if (date->day > 29)
                ret = false;
            else if (date->day == 29)
                if (!(date->year % 400 == 0 ||
                        (date->year % 4 == 0 && date->year % 100 != 0)))
                    ret = false;
            break;
        default:
            break;
    }

    return ret;
}

void addOne(Date *date, ONE_YEAR_MONTH_DAY addWhat)
{
    switch (addWhat) {
        case ONE_YEAR:
            ++(date->year);
            break;
        case ONE_MONTH:
            if (date->month == 12)
                date->month = 1;
            else
                ++(date->month);
            break;
        case ONE_DAY:
            ++(date->day);
            break;
        default:
            break;
    }

    int offset = 0;
    while (!isDateValid(date)) {
        --(date->day);
        ++offset;
    }
    if (offset) {
        if (date->month == 12)
            date->month = 1;
        else
            ++(date->month);
        date->day = offset;
    }
}

int getWeekday(Date *date)
{
    int y = date->year;
    int m = date->month;
    int d = date->day;
    if (m == 1 || m == 2) {
        m += 12;
        --y;
    }

    return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
}

string convertIntToWeekday(int weekday)
{
    string weekdayStr;
    switch (weekday) {
        case 0:
            weekdayStr = "Monday";
            break;
        case 1:
            weekdayStr = "Tuesday";
            break;
        case 2:
            weekdayStr = "Wednesday";
            break;
        case 3:
            weekdayStr = "Thursday";
            break;
        case 4:
            weekdayStr = "Friday";
            break;
        case 5:
            weekdayStr = "Saturday";
            break;
        case 6:
            weekdayStr = "Sunday";
            break;
        default:
            break;
    }

    return weekdayStr;
}

Date nextMonday(Date *date)
{
    int days = 7 - getWeekday(date);

    Date newDate;
    initDate(&newDate, date->year, date->month, date->day);
    while (days--)
        addOne(&newDate, ONE_DAY);

    return newDate;
}
