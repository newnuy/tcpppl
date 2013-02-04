#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

void expandMacro(void)
{
    map<string, string> table;

    char ch;
    while (cin.get(ch)) {
        if (ch == '#') {
            string str_def;
            cin >> str_def;
            if (str_def == "define") {
                string str_src;
                cin >> str_src;
                while (cin.get(ch) && isspace(ch))
                    ;
                cin.putback(ch);
                string str_dec;
                while (cin.get(ch) && ch != '\n') {
                    str_dec.push_back(ch);
                    table[str_src] = str_dec;
                }
            }
            else
                cout << ch << str_def;
        }
        else if (isalnum(ch) || ch == '_') {
            string str_word;
            str_word.push_back(ch);
            while (cin.get(ch) && (isalnum(ch) || ch == '_'))
                str_word.push_back(ch);
            cin.putback(ch);
            if (table.find(str_word) != table.end())
                cout << table[str_word];
            else
                cout << str_word;
        }
        else
            cout << ch;
    }
}

int main()
{
    expandMacro();

    return 0;
}
