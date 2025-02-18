#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Cube
 *
 * input:
 *      T, N
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^18
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          2
 *          4125
 *          976
 *      output:
 *          125
 *          -1
 *
 */

bool check(ll n) {
    ll a = cbrt(n) + 0.5;
    return a * a * a == n;
}

ll res;
int n, X[100];
string s;

void backtracking(int i) {
    for (int k = 0; k <= 1; k++) {
        X[i] = k;
        if (i == n - 1) {
            ll tmp = 0;
            REP(j, 1, n) if (X[j]) tmp = tmp * 10 + (s[j] - '0');

            if (check(tmp) && tmp > res)
                res = tmp;
        } else
            backtracking(i + 1);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> s;
        n = s.size();
        ms(X, 0);
        res = 0;

        backtracking(0);
        if (!res)
            cout << -1 << endl;
        else
            cout << res << endl;
    }

    return 0;
}
