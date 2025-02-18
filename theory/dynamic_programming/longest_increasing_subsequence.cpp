#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Longest increasing subsequence
 * dp[i] = max(dp[i], dp[j] + 1) where j < i & dp[j] < dp[i]
 */

int main() {
    SETUP;
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        int dp[n];
        FOR(i, 0, n) dp[i] = 1;

        FOR(i, 0, n) {
            FOR(j, 0, i) {
                if (a[j] < a[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, dp[i]);

        cout << mx << endl;
    }
    return 0;
}