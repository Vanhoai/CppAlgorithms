#include "bits/stdc++.h"
using namespace std;

/**
 * Binary Exponentiation
 *
 * input:
 *      N, K
 *      1<=N<=10^6; 1<=K<=10^9
 *
 * output: print N^K MOD 10^9 + 7
 *
 * @example
 *      input:
 *          2
 *          9 9
 *          994402 999992619
 *      output:
 *          387420489
 *          925329307
 */

#define MOD 1000000007

long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b = b >> 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        long long a, b; cin >> a >> b;
        cout << binpow(a, b) << endl;
    }

    return 0;
}















