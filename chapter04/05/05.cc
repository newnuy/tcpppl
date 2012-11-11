#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "char        ~ " << int(numeric_limits<char>::max()) << " ~ "
        << int(numeric_limits<char>::min()) << endl;
    cout << "short       ~ " << numeric_limits<short>::max() << " ~ "
        << numeric_limits<short>::min() << endl;
    cout << "int         ~ " << numeric_limits<int>::max() << " ~ "
        << numeric_limits<int>::min() << endl;
    cout << "long        ~ " << numeric_limits<long>::max() << " ~ "
        << numeric_limits<long>::min() << endl;
    cout << "float       ~ " << numeric_limits<float>::max() << " ~ "
        << numeric_limits<float>::min() << endl;
    cout << "double      ~ " << numeric_limits<double>::max() << " ~ "
        << numeric_limits<double>::min() << endl;
    cout << "long double ~ " << numeric_limits<long double>::max() << " ~ "
        << numeric_limits<long double>::min() << endl;
    cout << "unsigned    ~ " << numeric_limits<unsigned>::max() << " ~ "
        << numeric_limits<unsigned>::min() << endl;

    return 0;
}
