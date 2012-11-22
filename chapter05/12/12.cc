#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int SearchPairInString(const string &str, const string &pair);
int SearchPairInArray(const char *str, const char *pair);

int main()
{
    string str;
    string pair;
    cin >> str >> pair;

    char str2[20];
    char pair2[3];
    int i = 0;
    for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
        str2[i++] = *iter;
    str2[i] = '\0';
    i = 0;
    for (string::iterator iter = pair.begin(); iter != pair.end(); ++iter)
        pair2[i++] = *iter;
    pair2[i++] = '\0';

    cout << SearchPairInString(str, pair) << endl;
    cout << SearchPairInArray(str2, pair2) << endl;

    return 0;
}

int SearchPairInString(const string &str, const string &pair)
{
    int position = 0;
    int count = 0;
    do {
        position = str.find(pair, position);
        if (position < str.size()) {
            ++position;
            ++count;
        }
        else
            break;
    } while (1);

    return count;
}

int SearchPairInArray(const char *str, const char *pair)
{
    const char *position = str;
    int count = 0;
    do {
        position = strstr(position, pair);
        if (position != 0) {
            ++position;
            ++count;
        }
        else
            break;
    } while (1);

    return count;
}
