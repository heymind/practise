#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string s;
    int n;
    map<string, int> m;
    do {
        cin >> n;
        if (n == 0)
            return 0;
        while (n--) {
            cin >> s;
            m[s]++;
        }
        int max = 0;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second > max) {
                max = it->second;
                s = it->first;
            }
        }
        cout << s << endl;
        m.clear();

    } while (true);
}