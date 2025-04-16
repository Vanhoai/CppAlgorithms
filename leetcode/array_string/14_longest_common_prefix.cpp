#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

string longestCommonPrefix(vector<string> &v) {
    string res = "";
    for (int i = 0; i < v[0].size(); i++) {
        char c = v[0][i];
        for (int j = 1; j < v.size(); j++) {
            if (i >= v[j].size() || v[j][i] != c) {
                return res;
            }
        }
        res += c;
    }

    return res;
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
        vector<string> v;
        while (ss >> w)
            v.push_back(w);

        cout << longestCommonPrefix(v) << endl;
    }

    return 0;
}
