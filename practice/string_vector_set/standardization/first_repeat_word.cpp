#include <iostream>
#include <set>
#include <sstream>
using namespace std;

/**
input:
2
ngon ngu lap trinh C python lap trinh ngon
a abcd aa aaa bc d

output:
#Test 1: lap
#Test 2: -1
 */

void string_tolower(string &s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string w;

        set<string> se;
        int ok = 0;
        while (ss >> w) {
            if (se.find(w) != se.end()) {
                cout << w << endl;
                ok = 1;
                break;
            }

            se.insert(w);
        }

        if (!ok)
            cout << -1 << endl;
    }

    return 0;
}
