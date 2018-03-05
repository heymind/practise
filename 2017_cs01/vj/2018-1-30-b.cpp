#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string s;
    set<string> m;
    while (getline(cin, s)) {
        if (s[0] == '#')
            return 0;
        istringstream iss(s);
        copy(istream_iterator<string>(iss), istream_iterator<string>(),
             inserter(m, m.begin()));
        cout << m.size() << endl;
        m.clear();
    }
}