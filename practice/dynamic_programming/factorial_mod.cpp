#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Factorial Mod
 *
 * input:
 *      T, N
 *      1 <= T <= 10000
 *      0 <= N <= 10^6
 *
 * output: print factorial of N mod 10^9 + 7
 *
 * @example
 *      input:
 *          5
 *          10
 *          6
 *          8
 *          10
 *          13
 *      output:
 *          39916800
 *          720
 *          40320
 *          3628800
 *          227020758
 */

const int maxn = 10000001;
ll dp[maxn];

void init() {
    dp[0] = 0;
    dp[1] = 1;
    FOR(i, 2, maxn) {
        dp[i] = 1LL * i * dp[i - 1];
        dp[i] %= MOD;
    }
}

int main() {
    SETUP;
    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}