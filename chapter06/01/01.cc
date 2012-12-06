#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const int max_length = 64;
    char input_line[max_length];

    int c;
    char *p = input_line;
    while ((c = getchar()) != EOF)
        *p++ = c;
    *p = '\0';

    p = input_line;
    int quest_count = 0;
    while (*p != '\0')
        if (*p++ == '?')
            quest_count++;

    cout << quest_count << endl;

    return 0;
}
