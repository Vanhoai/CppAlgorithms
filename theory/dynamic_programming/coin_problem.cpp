#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Coin problem
 * 3 10
 * 4 5 8
 *
 * dp[i] = min(dp[i], d[i - a[j]] + 1) where i > a[j]
 */

int dp[1000001];

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        ms(dp, INF);
        dp[0] = 0;
        REP(i, 1, s) {
            for (int c : a) {
                if (i >= c)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }

        if (dp[s] == INF)
            cout << -1 << endl;
        else
            cout << dp[s] << endl;
    }

    return 0;
}