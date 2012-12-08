#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string, vector<double> > table;
    string str;
    double value;

    while (cin >> str) {
        cin >> value;
        table[str].push_back(value);
    }

    double sum_all = 0;
    for (map<string, vector<double> >::iterator iter = table.begin();
            iter != table.end(); ++iter) {
        vector<double> &vec = iter->second;
        sort(vec.begin(), vec.end());
        double sum = 0;
        for (vector<double>::const_iterator vec_iter = vec.begin();
                vec_iter != vec.end(); ++vec_iter)
            sum += *vec_iter;
        const vector<double>::size_type vsize = vec.size();
        cout << iter->first << " - " << sum << " - " << sum / vsize << " - ";
        cout <<
            (vsize == 0 ? (vec[vsize/2]+vec[vsize/2-1])/2: vec[(vsize-1)/2])
            << endl;
        sum_all += (sum/vsize);
    }
    cout << endl;

    cout << sum_all << " - " << sum_all/table.size() << endl;

    return 0;
}
