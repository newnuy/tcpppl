#include <iostream>
#include <string>
#include <map>

using namespace std;

struct score {
    double sum;
    int num;
};

int main()
{
    map<string, score> table;
    string str;
    double value;

    while (cin >> str) {
        cin >> value;
        table[str].sum += value;
        ++table[str].num;
    }

    double sum_all = 0;
    for (map<string, score>::iterator iter = table.begin(); iter != table.end();
            ++iter) {
        double aver = iter->second.sum / iter->second.num;
        sum_all += aver;
        cout << iter->first << " - " << iter->second.sum << " - "
            << aver <<endl;
    }

    cout << endl;
    cout << sum_all << " - " << sum_all/table.size() << endl;

    return 0;
}
