#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Setup Characters
 *
 * input:
 *      T, S
 *      1 ≤ T ≤ 100; 1 ≤ length(S) ≤ 10000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          3
 *          geeksforgeeks
 *          bbbabaaacd
 *          bbbbb
 *      output:
 *          1
 *          1
 *          -1
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;

        map<char, int> mp;
        FOR(i, 0, s.size()) mp[s[i]]++;

        int mx = 0;
        for (auto it : mp)
            mx = max(mx, it.second);

        int remain = s.size() - mx;

        int ok = remain + 1 >= mx;
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
