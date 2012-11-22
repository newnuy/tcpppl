#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<string> vec;
    while (cin >> str) {
        if (str != "Quit" && str != "quit" && str != "QUIT") {
            vector<string>::iterator iter;
            for (iter = vec.begin(); iter != vec.end(); ++iter)
                if (str == *iter)
                    break;
            if (iter == vec.end())
                vec.push_back(str);
        }
        else
            break;
    }

    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << " " << *iter;
    cout << endl;

    // sort
    sort(vec.begin(), vec.end());
    for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        cout << " " << *iter;
    cout << endl;

    return 0;
}
