#include "bits/stdc++.h"
using namespace std;

/**
 * Inverse Binary Exponentiation
 *
 * input:
 *      N, M
 *      1<=N<=10^9
 *      M is inverse number of N
 *
 * output: print N^M MOD 10^9 + 7
 *
 * @example
 *      input:
 *          2
 *          8
 *          999995841
 *      output:
 *          16777216
 *          987348397
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

long long inverse(long long n) {
    long long res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n = n / 10;
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
        long long a;
        cin >> a;
        cout << binpow(a, inverse(a)) << endl;
    }

    return 0;
}















