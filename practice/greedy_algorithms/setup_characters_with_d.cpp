#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Setup Characters with d unit
 *
 * input:
 *      T, S, D
 *      1 ≤ T ≤ 100
 *      1 ≤ D ≤ 100
 *      1 ≤ length(S) ≤ 10000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          2
 *          2
 *          ABB
 *          2
 *          AAA
 *      output:
 *          1
 *          -1
 */

void solve(string s, int d) {

    int n = s.size();
    map<char, int> mp;
    FOR(i, 0, s.size()) mp[s[i]]++;

    vector<pair<char, int>> v;
    for (auto it : mp)
        v.push_back(it);

    sort(all(v), [](pair<char, int> a, pair<char, int> b) -> bool {
        return a.S > b.S;
    });

    string res = string(n, '#');
    bool ok = true;
    FOR(i, 0, sz(v)) {
        int pos = i;
        while (res[pos] != '#')
            pos++;
        FOR(k, 0, v[i].second) {
            if (pos + k * d >= n) {
                ok = false;
                break;
            }
            res[pos + k * d] = v[i].F;
        }
    }

    if (!ok)
        cout << -1 << endl;
    else
        cout << 1 << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int d;
        cin >> d;
        string s;
        cin >> s;

        solve(s, d);
    }

    return 0;
}
