#include <iostream>
#include <map>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int romanToInt(string s) {
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int res = mp[s[s.size() - 1]];
    int n = mp[s[s.size() - 1]];
    for (int i = s.size() - 2; i >= 0; i--) {
        if (mp[s[i]] < n)
            res -= mp[s[i]];
        else {
            res += mp[s[i]];
            n = mp[s[i]];
        }
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
    while (TC--) {
        string s;
        cin >> s;
        cout << romanToInt(s) << endl;
    }

    return 0;
}
